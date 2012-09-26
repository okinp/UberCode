#pragma once
#include<QGraphicsObject>

namespace Uber
{

class UCNode : public QGraphicsObject
{
public:
	UCNode(void);
	~UCNode(void);

	virtual QRectF boundingRect() const;

	virtual void paint( QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0 );

	virtual int type() const;

	virtual bool sceneEventFilter( QGraphicsItem *watched, QEvent *event );

	virtual bool sceneEvent( QEvent *event );

	virtual void dragEnterEvent( QGraphicsSceneDragDropEvent *event );

	virtual void dragLeaveEvent( QGraphicsSceneDragDropEvent *event );

	virtual void dragMoveEvent( QGraphicsSceneDragDropEvent *event );

	virtual void dropEvent( QGraphicsSceneDragDropEvent *event );

	virtual void mousePressEvent( QGraphicsSceneMouseEvent *event );

	virtual void mouseMoveEvent( QGraphicsSceneMouseEvent *event );

	virtual void mouseReleaseEvent( QGraphicsSceneMouseEvent *event );

};

}
