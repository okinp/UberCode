#pragma once
#include<QGraphicsObject>
#include "UCNodeInfo.h"


namespace Uber
{
class UCNodeInfo;
class UCNode : public QGraphicsObject
{
	Q_OBJECT
public:
	UCNode( QGraphicsObject* parent, const UCNodeInfo& info );
	virtual ~UCNode(void);

	virtual QRectF boundingRect() const;

	virtual void paint( QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0 );


private:

	const UCNodeInfo						m_Info;
};

}
