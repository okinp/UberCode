#pragma once
#include <QTreeWidget>
#include "UCManagerBundles.h"



namespace Uber
{

/*!
* This Object is responsible for showing all loaded bundles in a QTreeWidget
* DragNDrop actions to scene (for creating visual block instances) will happen
* from this QTreeWidget
*/
class UCTreeWidgetBundles : public QTreeWidget
{
	Q_OBJECT

public:
	UCTreeWidgetBundles( QWidget* parent );
	~UCTreeWidgetBundles(void);
	
protected:
	void					mouseMoveEvent(QMouseEvent* event);
	void					mousePressEvent(QMouseEvent* event);

private slots:
		void				OnItemClicked( QTreeWidgetItem* item, int column );
		void				OnBundleDetected( const QString& bundleName, const BlockInfoList& blocks );
		void				OnBundleUnloaded( const QString& bundleName, const BlockInfoList& blocks );

private:

	QPoint					m_StartPos; 		/*!< Startpositon when a left-mouse-click occured */

};

}
