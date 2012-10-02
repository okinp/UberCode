#include "UCNodeOutlet.h"
#include <QPen>
#include <QPainter>


using namespace Uber;

UCNodeOutlet::UCNodeOutlet( QGraphicsObject* parent, const UCModelData_sptr data )
	: UCNode( parent, data )
{

}


UCNodeOutlet::~UCNodeOutlet(void)
{
}

void Uber::UCNodeOutlet::paint( QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget /*= 0 */ )
{
	QPen pen;
	pen.setWidthF( 5.0f );
	pen.setBrush( Qt::darkBlue );	
	painter->setPen( pen );
	painter->drawEllipse( 0,0, 10, 10 );
	pen.setWidthF( 1.8f );
	pen.setBrush( Qt::black );	
	painter->setPen( pen );
	painter->drawEllipse( -2,-2, 14, 14 );
}
