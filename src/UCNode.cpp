#include "UCNode.h"
#include <QPen>
#include <QPainter>


using namespace Uber;


UCNode::UCNode( QGraphicsObject* parent, const UCNodeInfo& info )
	: QGraphicsObject( parent ),
	  m_Info( info )
{
	this->setToolTip( info.name );

}


UCNode::~UCNode(void)
{
}


QRectF Uber::UCNode::boundingRect() const
{
	return QRectF( -5, -5, 20, 20 );
}

void Uber::UCNode::paint( QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget /*= 0 */ )
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
