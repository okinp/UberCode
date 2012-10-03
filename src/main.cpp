#include "UCWindowMain.h"
#include <windows.h>
#include <QApplication>
#include <QtGui/QtGui>
#include "vld.h"
#include <iostream>



int main(int argc, char *argv[])
{
	// creating windows and application
	QApplication app( argc, argv );
	app.setOrganizationDomain( "cadet.at" );
	app.setOrganizationName( "CADET" );
	app.setApplicationName( "UberCode" );

	Uber::UCWindowMain& window = Uber::UCWindowMain::GetInstance();
	window.show();
	// starting qt-window logic
	app.exec();
	window.Release(); //Releasing object before QT can -> otherwise crash (cause: mainwindow as singleton)
	return 0;
};