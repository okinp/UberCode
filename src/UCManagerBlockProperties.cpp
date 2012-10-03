#include <QLayout>
#include <QDockWidget>
#include <QEvent>
#include "UCManagerBlockProperties.h"
#include "UCTreeWidgetBlockProperties.h"
#include "UCBlockModel.h"
#include "UCWindowMain.h"




using namespace Uber;

void Uber::UCManagerBlockProperties::Initialize()
{
	m_SelectedDock.first = nullptr;
	m_SelectedDock.second = nullptr;
}

void Uber::UCManagerBlockProperties::Uninitialize()
{

}

void Uber::UCManagerBlockProperties::OnBlockSelected( UCBlockModel* model )
{
	if( !m_SelectedDock.first && !m_SelectedDock.second )
		AddDockAndTreeWidget( model );
	else if( m_SelectedDock.first && m_SelectedDock.second )
		m_SelectedDock.second->setModel( model );
	else
		std::cout << "unknown error in UCManagerBlockProperties::OnBlockSelected()" << std::endl;
}

void Uber::UCManagerBlockProperties::OnBlockDoubleClicked( UCBlockModel* model )
{
	AddDockAndTreeWidget( model );
}

QDockWidget* Uber::UCManagerBlockProperties::AddDockAndTreeWidget( UCBlockModel* model )
{
	QDockWidget* dock = new QDockWidget();
	UCTreeWidgetBlockProperties* properties = new UCTreeWidgetBlockProperties();
	m_SelectedDock = std::make_pair( dock, properties );

	UCWindowMain::GetInstance().addDockWidget( Qt::RightDockWidgetArea, dock, Qt::Horizontal );
	m_Docks.push_back( m_SelectedDock );
	dock->setGeometry( QRect( 915, 21, 115, 721 ) );

	QWidget* widget = new QWidget( dock );
	dock->setWidget( widget );

	QLayout* layout = new QVBoxLayout( widget );
	widget->setLayout( layout );
	layout->setMargin( 0 );
	layout->setGeometry( QRect( 800, 50, 100, 200 )  );
	layout->addWidget( properties );
	properties->setModel( model );
	dock->installEventFilter( this );
	return dock;
}

void Uber::UCManagerBlockProperties::OnBlockPropertiesClicked( UCTreeWidgetBlockProperties* widget )
{
	DockContainer::iterator iter = m_Docks.begin();
	DockContainer::iterator end = m_Docks.end();

	for( ; iter != end; ++iter )
	{
		if( iter->second == widget )
			m_SelectedDock = *iter;
	}
}


bool Uber::UCManagerBlockProperties::eventFilter( QObject* object, QEvent* event )
{
	if( event->type() == QEvent::Close )
	{
		DockContainer::iterator iter = m_Docks.begin();
		DockContainer::iterator end = m_Docks.end();

		for( ; iter != end; ++iter )
		{
			if( iter->first == object )
			{
				m_Docks.remove( *iter );
				break;
			}
		}
		if( m_Docks.size() )
			m_SelectedDock = *m_Docks.begin();
		else
			m_SelectedDock = std::make_pair( nullptr, nullptr );
		return true;
	}
	return false;
}


