#include "UCBlock.h"
#include <QPointF>
#include <QGraphicsView>
#include "UCTreeWidgetBlockProperties.h"
#include "UCNodeInlet.h"
#include "UCNodeOutlet.h"


using namespace Uber;


Uber::UCBlock::UCBlock( const QString& bundleName, const QString& blockName )
	: QGraphicsObject( nullptr ),
	  m_Model( bundleName, blockName ),
	  m_Inlets( m_Model.GetCountInlets() ),
	  m_Outlets( m_Model.GetCountOutlets() )
{
	 this->setToolTip( bundleName + "->" + blockName );
	// select/drag-able
	setFlag( QGraphicsItem::ItemIsMovable );
	setFlag( QGraphicsItem::ItemIsSelectable );

	// properties-widget should display inlets/outlets on selected graphics object
	connect( this, SIGNAL( NotifyBlockSelected( UCBlockModel* ) ),
			 &UCTreeWidgetBlockProperties::GetInstance(), SLOT( OnBlockSelected( UCBlockModel* ) ) );

	emit NotifyBlockSelected( &m_Model );

	// create nodes for each inlet/outlet
	unsigned int size = m_Model.GetCountInlets();
	for( int i = 0; i < size; ++i )
	{
		m_Inlets[i] = QSharedPointer<UCNode>( new UCNodeInlet( this, m_Model.GetModelDataAt( i ) ) );
		m_Inlets[i]->setPos( 20 + i * 20, 10 );
	}

	size = m_Model.GetCountOutlets();
	for( int i = 0; i < size; ++i )
	{
		m_Outlets[i] = QSharedPointer<UCNode>( new UCNodeOutlet( this, m_Model.GetModelDataAt( i ) ) );
		m_Outlets[i]->setPos( 130 - i * 20, 80 );
	}
}

UCBlock::~UCBlock(void)
{
	
}

QRectF Uber::UCBlock::boundingRect() const
{
	return QRectF( 0, 0, 150, 100 );
}

void Uber::UCBlock::paint( QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget /*= 0 */ )
{
	Q_UNUSED( option )
	Q_UNUSED( widget )

	QPainterPath path;
	path.addRoundedRect( 0, 0, 150, 100, 5, 5 );

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

NodeContainer& Uber::UCBlock::GetNodesInlet() const
{
	return const_cast<NodeContainer&>( m_Inlets );
}

NodeContainer& Uber::UCBlock::GetNodesOutlet() const
{
	return const_cast<NodeContainer&>( m_Outlets );
}
