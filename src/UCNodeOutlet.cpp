#include "UCNodeOutlet.h"



using namespace Uber;

UCNodeOutlet::UCNodeOutlet( QGraphicsObject* parent, const UCOutletInfo& info )
	: UCNode( parent, info ),
	  m_Info( info )
{

}


UCNodeOutlet::~UCNodeOutlet(void)
{
}

void Uber::UCNodeOutlet::paint( QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget /*= 0 */ )
{
	UCNode::paint( painter, option, widget );
}
