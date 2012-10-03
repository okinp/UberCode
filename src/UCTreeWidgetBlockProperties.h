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
class UCTreeWidgetBlockProperties : public QTreeView
{
	Q_OBJECT

public:
	UCTreeWidgetBlockProperties();

	virtual void				mousePressEvent( QMouseEvent * );

signals:
	void						NotifyBlockPropertiesClicked( UCTreeWidgetBlockProperties* widget );



private:
	friend class UCSingleton<UCTreeWidgetBlockProperties>;
};

}
