#include <QtGui/QListWidget>
#include <QtGui/QMessageBox>
#include <QListWidgetItem>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QListWidgetItem>
#include <QToolButton>
#include <QFileDialog>

#include <ui_SettingsPathBundles.h>
#include "UCDialogPathBundles.h"
#include "UCManagerSettings.h"
#include "UCManagerBundles.h"



using namespace Uber;



UCDialogPathBundles::UCDialogPathBundles()
	: QDialog( nullptr )
{
	setWindowFlags( Qt::WindowCloseButtonHint );
	m_UIWindow = Ui_SettingsPathBundles_sp( new Ui_SettingsPathBundles() );
	m_UIWindow->setupUi( this );

	
	//referencing widgets to member-ptrs
	m_PathBundleEntries = m_UIWindow->pathBundleEntries;
	
	// loading existing bundle paths from settings
	QStringList dirList = UCManagerSettings::GetInstance().GetBundleDirectories();
	const int size = dirList.size();

	m_PathBundleEntries->setGridSize( QSize( m_PathBundleEntries->size().width(), 20 ) );

	for( int i=0; i < size; ++i )
	{
		const QString& str = dirList.at( i );
		if( !str.isEmpty() )
		{
			QListWidgetItem* item = new QListWidgetItem( m_PathBundleEntries );
			item->setText( str );
			m_PathBundleEntries->addItem( item );
		}
	}

	// finally connect a punch of actions to all buttons and itemwidget-responses
	InitConnections();
}


UCDialogPathBundles::~UCDialogPathBundles(void)
{
	
}

void Uber::UCDialogPathBundles::OnAddItem()
{
	QListWidgetItem* item = new QListWidgetItem( m_PathBundleEntries );
	item->setText( "Choose Folder" );
	m_PathBundleEntries->addItem( item );
	m_PathBundleEntries->setItemSelected( item, true );
}

void Uber::UCDialogPathBundles::OnRemoveItem()
{
	qDeleteAll( m_PathBundleEntries->selectedItems() );
	update();
}

void Uber::UCDialogPathBundles::OnAccept()
{
	// if there is a widget open -> close it to call OnRemoveWidget -> write to item.text
	m_PathBundleEntries->setCurrentItem( nullptr );

	const int size = m_PathBundleEntries->count();
	QStringList strList;

	// filter paths and save with settings-manager
	for( int i = 0; i < size; ++i )
	{
		QListWidgetItem* item = m_PathBundleEntries->item( i );
		strList.insert( i, item->text() );
	}
	UCManagerSettings::GetInstance().SetBundleDirectories( strList );
	UCManagerBundles::GetInstance().LoadBundles(); // Refresh Bundles
	accept();
}

void Uber::UCDialogPathBundles::OnInsertWidget( QListWidgetItem* item )
{
	// Creating a widget for the given item
	UCPathBundlesWidgetItem* itemWidget = new UCPathBundlesWidgetItem( m_PathBundleEntries );
	itemWidget->SetPath( item->text() );
	m_PathBundleEntries->setItemWidget( item, itemWidget );
}

void Uber::UCDialogPathBundles::OnRemoveWidget( QListWidgetItem* next, QListWidgetItem* previous )
{
	// write text to item and remove widget
	UCPathBundlesWidgetItem* widget = static_cast<UCPathBundlesWidgetItem*>( m_PathBundleEntries->itemWidget( previous ) );
	if( widget )
		previous->setText( widget->GetPath() );
	m_PathBundleEntries->removeItemWidget( previous );
}

void Uber::UCDialogPathBundles::InitConnections()
{
	// connect actions
	connect( m_UIWindow->btn_ok, SIGNAL( clicked() ), this, SLOT( OnAccept() ) );
	connect( m_UIWindow->btn_cancel, SIGNAL( clicked() ), this, SLOT( reject() ) );
	connect( m_UIWindow->btn_add, SIGNAL( clicked() ), this, SLOT( OnAddItem() ) );
	connect( m_UIWindow->btn_delete, SIGNAL( clicked() ),  this, SLOT( OnRemoveItem() ) );
	// insert widget for choosing/changing path if double-click item
	connect( m_PathBundleEntries, SIGNAL( itemDoubleClicked( QListWidgetItem* ) ), this, SLOT( OnInsertWidget( QListWidgetItem* ) ) );
	// remove widget if clicking to some other items
	connect( m_PathBundleEntries, SIGNAL( currentItemChanged ( QListWidgetItem* , QListWidgetItem*  ) ), this, SLOT( OnRemoveWidget( QListWidgetItem*, QListWidgetItem* ) ) );
}



// -> Implementation of UCPathBundlesWidgetItem

UCPathBundlesWidgetItem::UCPathBundlesWidgetItem( QListWidget* parent )
	: QWidget( parent )
{
	// creating widget gui
	m_Text = new QLineEdit( QString( "" ), this );
	m_OpenFolder = new QToolButton( this );

	m_OpenFolder->setText( QString( "..." ) );
	QHBoxLayout* layout = new QHBoxLayout( this );
	layout->setMargin( 0 );
	layout->addWidget( m_Text );
	layout->addWidget( m_OpenFolder );
	setLayout( layout );

	// show folder dialog
	connect( m_OpenFolder, SIGNAL( clicked() ), this, SLOT( OnOpenFolder() ) );
}

void UCPathBundlesWidgetItem::OnOpenFolder()
{
	QFileDialog fd;
	fd.setFileMode( QFileDialog::DirectoryOnly );
	fd.setOptions( QFileDialog::ShowDirsOnly );

	if( fd.exec() == QDialog::Accepted )
	{
		QStringList res = fd.selectedFiles ();
		if ( res.count() )
			SetPath( res[0] );
	}
}

void UCPathBundlesWidgetItem::SetPath( const QString& str )
{
	m_Text->setText( str );
}

const QString UCPathBundlesWidgetItem::GetPath() const
{
	return m_Text->text();
}

