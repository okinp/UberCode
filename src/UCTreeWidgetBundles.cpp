#include "UCTreeWidgetBundles.h"
#include "UCManagerBundles.h"
#include <QMouseEvent>
#include <QApplication>


using namespace Uber;

UCTreeWidgetBundles::UCTreeWidgetBundles( QWidget* parent )
	: QTreeWidget( parent )
{
	setColumnCount( 1 );
	setHeaderItem( new QTreeWidgetItem( (QTreeWidget*) nullptr, QStringList( QString( "_2RealBundles" ) ) ) );

	// bundlemanager inserted bundles
	connect( &UCManagerBundles::GetInstance(),
			 SIGNAL( NotifyBundleDetected( const QString&, const BlockInfoList& )),
			 this, SLOT(OnBundleDetected( const QString&, const BlockInfoList& )) );

	// bundlemanager unloaded bundles
	connect( &UCManagerBundles::GetInstance(),
		SIGNAL( NotifyBundlyUnloaded( const QString&, const BlockInfoList& )),
		this, SLOT(OnBundleUnloaded( const QString&, const BlockInfoList& )) );

	setWindowTitle( QString( "kasfklsjf" ) );
}


UCTreeWidgetBundles::~UCTreeWidgetBundles(void)
{
	
}

void Uber::UCTreeWidgetBundles::mouseMoveEvent( QMouseEvent* event )
{
	if( event->buttons() & Qt::LeftButton )
	{
		int distance = (event->pos() - m_StartPos).manhattanLength();
		if( distance >= QApplication::startDragDistance() )
		{
			// fill drag and drop item with information to catch on element to drop on
			QTreeWidgetItem *item = currentItem();
			if( item )
			{
				QMimeData *mimeData = new QMimeData;
				QByteArray data;
				
				// block has been dragged into scene
				if( item->parent() )
				{
					// set both: bundle and block name
					data.append( item->parent()->text( 0 ) ); // bundle name
					data.append( "/" );
					data.append( item->text( 0 ) ); // block name
				}
				// bundle has been dragged into scene
				else
				{
					data.append( item->text( 0 ) ); // bundle name
					data.append( "/" );
					data.append( "" ); // no block name available
				}

				// store data to QDrag
				mimeData->setData( "text/plain", data );
				QDrag* drag = new QDrag( this );
				drag->setMimeData( mimeData );
				Qt::DropAction dropAction = drag->exec( Qt::CopyAction );
			}
		}
	}
	QTreeWidget::mouseMoveEvent( event );
}

void Uber::UCTreeWidgetBundles::mousePressEvent( QMouseEvent* event )
{
	if( event->button() == Qt::LeftButton )
		m_StartPos = event->pos();
	QTreeWidget::mousePressEvent( event );
}

void Uber::UCTreeWidgetBundles::OnBundleDetected( const QString& bundleName, const BlockInfoList& blocks )
{
	// At first create top level item with bundle name
	QTreeWidgetItem* itemBundle = new QTreeWidgetItem( this );
	itemBundle->setText( 0, bundleName );
	
	BlockInfoList::const_iterator iter = blocks.begin();
	BlockInfoList::const_iterator end = blocks.end();

	// insert block-items into the top level item
	for( ; iter != end; ++iter )
	{
		QTreeWidgetItem* itemBlock = new QTreeWidgetItem( itemBundle );
		itemBlock->setText( 0, iter->first );
		itemBundle->addChild( itemBlock );
	}
	addTopLevelItem( itemBundle );
	itemBundle->setExpanded( true );
}


void Uber::UCTreeWidgetBundles::OnBundleUnloaded( const QString& bundleName, const BlockInfoList& blocks )
{

}

void Uber::UCTreeWidgetBundles::OnItemClicked( QTreeWidgetItem* item, int column )
{
	
}
