#include "UCNodeInlet.h"
#include <QPen>
#include <QPainter>


using namespace Uber;


Uber::UCNodeInlet::UCNodeInlet( QGraphicsObject* parent, const UCModelData_sptr data )
	: UCNode( parent, data )
{

}

UCNodeInlet::~UCNodeInlet(void)
{

}

void Uber::UCNodeInlet::paint( QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget /*= 0 */ )
{
	QPen pen;
	pen.setWidthF( 5.0f );
	pen.setBrush( Qt::yellow );	
	painter->setPen( pen );
	painter->drawEllipse( 0,0, 10, 10 );
	pen.setWidthF( 1.5f );
	pen.setBrush( Qt::black );	
	painter->setPen( pen );
	painter->drawEllipse( -2,-2, 14, 14 );
}