#pragma once
#include<QGraphicsObject>
#include "UCBlockModel.h"


namespace Uber
{

/*!
* The graphical representation of a block in the scene, holds all information
* in its UCBlockModel, 
*/
class UCBlock : public QGraphicsObject
{
	Q_OBJECT

public:
	UCBlock( const QString& bundleName, const QString& blockName );
	virtual ~UCBlock(void);

	virtual QRectF					boundingRect() const;
	virtual void					paint( QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0 );

	UCBlockModel*					GetModel();

signals:
	void							NotifyBlockSelected( UCBlockModel* model );

protected:
	virtual void					mousePressEvent( QGraphicsSceneMouseEvent *event );

private:
	UCBlockModel					m_Model;
};

}
