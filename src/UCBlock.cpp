#include "UCBlock.h"
#include <QPointF>
#include <QGraphicsView>
#include "UCTreeWidgetBlockProperties.h"



using namespace Uber;


Uber::UCBlock::UCBlock( const QString& bundleName, const QString& blockName )
	: QGraphicsObject( nullptr ),
	  m_Model( bundleName, blockName )
{
	// select/drag-able
	setFlag( QGraphicsItem::ItemIsMovable );
	setFlag( QGraphicsItem::ItemIsSelectable );

	// properties-widget should display inlets/outlets on selected graphics object
	connect( this, SIGNAL( NotifyBlockSelected( UCBlockModel* ) ),
			 &UCTreeWidgetBlockProperties::GetInstance(), SLOT( OnBlockSelected( UCBlockModel* ) ) );

	emit NotifyBlockSelected( &m_Model );
}

UCBlock::~UCBlock(void)
{
	
}

QRectF Uber::UCBlock::boundingRect() const
{
	return QRectF( -150, -100, 150, 100 );
}

void Uber::UCBlock::paint( QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget /*= 0 */ )
{
	Q_UNUSED(option)
	Q_UNUSED(widget)

	QPainterPath path;
	path.addRoundedRect( -150, -100, 150, 100, 5, 5 );

	QPen pen;
	pen.setWidthF(1.f);
	pen.setBrush(Qt::black);	
	painter->setPen(pen);
	painter->setBrush(QColor(69,82,80));
	painter->drawPath( path );
}

UCBlockModel* Uber::UCBlock::GetModel()
{
	return &m_Model;
}

void Uber::UCBlock::mousePressEvent( QGraphicsSceneMouseEvent *event )
{
	emit NotifyBlockSelected( &m_Model );
	QGraphicsObject::mousePressEvent( event );
}
