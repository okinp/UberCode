#include <QGraphicsSceneDragDropEvent>
#include <QMimeData>
#include <QGraphicsView>
#include "UCSceneView.h"
#include "UCTreeWidgetBundles.h"
#include "UCBlock.h"




using namespace Uber;


void Uber::UCSceneView::Initialize()
{
	m_RootGraphicsView = nullptr;
}

void Uber::UCSceneView::Uninitialize()
{

}

QGraphicsView* Uber::UCSceneView::GetRootGraphicsView() const
{
	return m_RootGraphicsView;
}

void Uber::UCSceneView::SetRootGraphicsView( QGraphicsView* view )
{
	if( view )
		m_RootGraphicsView = view;
}

void UCSceneView::dragEnterEvent(QGraphicsSceneDragDropEvent* event)
{ 
	if( qobject_cast<UCTreeWidgetBundles*>( event->source() ) )
		event->setAccepted( true );
	else event->setAccepted( false );
}

void UCSceneView::dragMoveEvent(QGraphicsSceneDragDropEvent* event)
{
	if( qobject_cast<UCTreeWidgetBundles*>( event->source() ) )
		event->setAccepted( true );
	else event->setAccepted( false );
}

void UCSceneView::dropEvent(QGraphicsSceneDragDropEvent* event)
{
	event->acceptProposedAction();
	if( event->mimeData()->hasText() )
	{
		QByteArray& data = event->mimeData()->data( "text/plain" );
		// split data - bundlename index: 0; blockname index: 1
		QStringList names = QString( data.constData() ).split( '/' );
		
		// creating blocks on scene
		if( names.size() == 2 )
		{
			const QString& bundleName = names.at( 0 );
			const QString& blockName = names.at( 1 );
			UCSceneView& scene = UCSceneView::GetInstance();
			QPointF nodePosition = event->scenePos(); // position where to spawn node

			// a single block has dragged onto scene -> create 1 instance
			if( blockName.size() >= 1 )
			{
				UCBlock* block = new UCBlock( bundleName, blockName );
				block->setPos( nodePosition );
				scene.addItem( block );
			}
			else // a whole bundle has dragged onto scene -> create all containing blocks
			{
				const BundleInfo& info = UCManagerBundles::GetInstance().GetBundle( bundleName );
				BlockInfoList::const_iterator iter = info.second.begin();
				
				// instance all blocks of a bundle
				while( iter != info.second.end() )
				{
					UCBlock* block = new UCBlock( bundleName, iter->first );
					block->setPos( nodePosition );
					scene.addItem( block );

					// advance
					++iter;
					nodePosition += QPointF( 10, 0 );
				}
			}
		}
		else
			std::cout << "UCSceneView::dropEvent(): Error, when trying to split mimedata information!" << std::endl;
	}
	else
		std::cout << "UCSceneView::dropEvent(): Error, drag and drop item no text for identification!" << std::endl;
}
