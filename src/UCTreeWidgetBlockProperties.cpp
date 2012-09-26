#include "UCTreeWidgetBlockProperties.h"
#include "UCBlockModel.h"



using namespace Uber;



UCTreeWidgetBlockProperties::UCTreeWidgetBlockProperties(void)
	: QTreeView()
{
	setItemsExpandable( false );
	setExpandsOnDoubleClick( false );
	setTabKeyNavigation( true );
}


UCTreeWidgetBlockProperties::~UCTreeWidgetBlockProperties(void)
{

}

void UCTreeWidgetBlockProperties::Initialize()
{
	
}

void UCTreeWidgetBlockProperties::Uninitialize()
{
	
}

void Uber::UCTreeWidgetBlockProperties::OnBlockSelected( UCBlockModel* model )
{
	setModel( model );
}
