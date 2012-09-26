#pragma once
#include <QGraphicsScene>
#include "UCSingleton.h"

namespace Uber
{

class UCSceneView : public QGraphicsScene, public UCSingleton<UCSceneView>
{
	Q_OBJECT

public:
	virtual void		Initialize();
	virtual void		Uninitialize();

	QGraphicsView*		GetRootGraphicsView() const;
	void				SetRootGraphicsView( QGraphicsView* view );

private:
	void				dragEnterEvent(QGraphicsSceneDragDropEvent* event);
	void				dragMoveEvent(QGraphicsSceneDragDropEvent* event);
	void				dropEvent(QGraphicsSceneDragDropEvent* event);


	QGraphicsView*		m_RootGraphicsView;
};

}
