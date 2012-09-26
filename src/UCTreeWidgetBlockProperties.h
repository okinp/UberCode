#pragma once
#include <QTreeView>
#include "UCSingleton.h"



namespace Uber
{
//fwds	
class UCBlockModel;

/*!
* Widget on the right side of the MainWindow
* It shows all properties (inlet/outlet) and their values
* Values of Inlet-Properties can be changed in here
*/
class UCTreeWidgetBlockProperties : public QTreeView, public UCSingleton<UCTreeWidgetBlockProperties>
{
	Q_OBJECT
private:
	// declare ctors/cpyctor/operator= because use of macro UCSINGLETON -> costum ctor
	UCTreeWidgetBlockProperties( void );
	UCTreeWidgetBlockProperties( const UCTreeWidgetBlockProperties& obj );
	~UCTreeWidgetBlockProperties(void);
	UCTreeWidgetBlockProperties& operator=( const UCTreeWidgetBlockProperties& o );

	virtual void			Initialize();
	virtual void			Uninitialize();

public slots:

	/*! \brief		Slot that sets new data model to this view, Called from UCBlock::Ctor && UCBlock::mousePressEvent
		\param		model - to set on this tree view
	*/
	void					OnBlockSelected( UCBlockModel* model );

private:
	friend class UCSingleton<UCTreeWidgetBlockProperties>;
};

}
