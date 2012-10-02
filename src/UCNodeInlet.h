#pragma once
#include "UCNode.h"



namespace Uber
{

class UCNodeInlet : public UCNode
{
public:
	UCNodeInlet( QGraphicsObject* parent, const UCModelData_sptr data );
	virtual ~UCNodeInlet(void);

	virtual void paint( QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0 );

private:


};

}
