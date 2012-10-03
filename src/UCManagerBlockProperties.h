#pragma once
#include "UCSingleton.h"
#include "QObject"
#include <vector>

class QDockWidget;
class QLayout;

namespace Uber
{
	//fwds
	class UCTreeWidgetBlockProperties;
	class UCBlockModel;

class UCManagerBlockProperties : public QObject, public UCSingleton<UCManagerBlockProperties>
{
	Q_OBJECT
	UCSINGLETON( UCManagerBlockProperties )
	
	typedef std::pair<QDockWidget*, UCTreeWidgetBlockProperties*>	DockWidgetAndTree;
	typedef std::list<DockWidgetAndTree>							DockContainer;

public slots:

	/*! \brief		Slot that sets new data model to this view, Called from UCBlock::Ctor && UCBlock::mousePressEvent
		\param		model - to set on this tree view
	*/
	void						OnBlockSelected( UCBlockModel* model );
	void						OnBlockDoubleClicked( UCBlockModel* model );
	void						OnBlockPropertiesClicked( UCTreeWidgetBlockProperties* widget );

private:
	virtual void				Initialize();
	virtual void				Uninitialize();
	virtual bool				eventFilter( QObject* object, QEvent* event );

	
	QDockWidget*				AddDockAndTreeWidget( UCBlockModel* model );


private:

	DockContainer				m_Docks;
	DockWidgetAndTree			m_SelectedDock;
};

}
