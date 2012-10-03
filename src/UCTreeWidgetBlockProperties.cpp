#include "UCTreeWidgetBlockProperties.h"
#include "UCBlockModel.h"
#include "UCManagerBlockProperties.h"



using namespace Uber;



UCTreeWidgetBlockProperties::UCTreeWidgetBlockProperties(void)
	: QTreeView()
{
	setItemsExpandable( false );
	setExpandsOnDoubleClick( false );
	setTabKeyNavigation( true );

	connect( this, SIGNAL( NotifyBlockPropertiesClicked( UCTreeWidgetBlockProperties* ) ),
			 &UCManagerBlockProperties::GetInstance(),
			 SLOT( OnBlockPropertiesClicked( UCTreeWidgetBlockProperties* ) ) );
}


void Uber::UCTreeWidgetBlockProperties::mousePressEvent( QMouseEvent *widget )
{
	emit NotifyBlockPropertiesClicked( this );
	QTreeView::mousePressEvent( widget );
}


