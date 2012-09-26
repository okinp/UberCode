#include "UCNodeInlet.h"



using namespace Uber;


Uber::UCNodeInlet::UCNodeInlet( QGraphicsObject* parent, const UCInletInfo& info )
	: UCNode( parent, info ),
	  m_Info( info )
{

}

void Uber::UCNodeInlet::paint( QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget /*= 0 */ )
{
	UCNode::paint( painter, option, widget );

}

UCNodeInlet::~UCNodeInlet(void)
{

}
