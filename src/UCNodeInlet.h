#pragma once
#include "UCNode.h"



namespace Uber
{

class UCNodeInlet : public UCNode
{
public:
	UCNodeInlet( QGraphicsObject* parent, const UCInletInfo& info );
	virtual ~UCNodeInlet(void);

	virtual void paint( QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0 );

private:

	const UCInletInfo						m_Info;
};

}
