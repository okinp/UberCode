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

	Uber::UCWindowMain window;
	window.show();
	// starting qt-window logic
	return app.exec();
};