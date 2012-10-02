#pragma once
#include<QGraphicsObject>
#include <QSharedPointer>
#include "UCModelData.h"



namespace Uber
{

class UCNode : public QGraphicsObject
{
	Q_OBJECT
public:
	UCNode( QGraphicsObject* parent, const UCModelData_sptr data );
	virtual ~UCNode(void);

	virtual QRectF					boundingRect() const;


protected:
	const UCModelData_sptr			GetModelData() const;

private:
	const UCModelData_sptr			m_Data;
};

typedef QSharedPointer<UCNode> UCNode_sptr;
}
