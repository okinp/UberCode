#pragma once
#include "UCNode.h"



namespace Uber
{

class UCNodeOutlet : public UCNode
{
	
public:
	UCNodeOutlet( QGraphicsObject* parent, const UCOutletInfo& info );
	virtual ~UCNodeOutlet(void);

	virtual void paint( QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0 );

private:

	const UCOutletInfo					m_Info;
};

}
