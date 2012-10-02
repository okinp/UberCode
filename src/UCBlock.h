#pragma once
#include<QGraphicsObject>
#include "UCBlockModel.h"
#include "UCNode.h"


namespace Uber
{

typedef std::vector<UCNode_sptr>	NodeContainer;

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
	NodeContainer&					GetNodesInlet() const;
	NodeContainer&					GetNodesOutlet() const;

signals:
	void							NotifyBlockSelected( UCBlockModel* model );

protected:
	virtual void					mousePressEvent( QGraphicsSceneMouseEvent *event );

private:
	UCBlockModel					m_Model;
	NodeContainer					m_Inlets;
	NodeContainer					m_Outlets;
};

}
