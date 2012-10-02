#include "UCNode.h"


using namespace Uber;


UCNode::UCNode( QGraphicsObject* parent, const UCModelData_sptr data )
	: QGraphicsObject( parent ),
	  m_Data( data )
{
	this->setToolTip( m_Data->Name() );

}


UCNode::~UCNode(void)
{
}


QRectF Uber::UCNode::boundingRect() const
{
	return QRectF( -5, -5, 20, 20 );
}

const UCModelData_sptr Uber::UCNode::GetModelData() const
{
	return m_Data;
}
