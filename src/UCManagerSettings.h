#pragma once
#include <QStringList>
#include <QSharedPointer>
#include <QSettings>
#include "UCSingleton.h"

namespace Uber
{
/*!
* Singleton class managing configurations. Fetch Instance with GetInstance() and use getter/setter
* methods do access/write settings.
* Note: Settings.ini will be accessible in .data folder!
*/
class UCManagerSettings : public UCSingleton<UCManagerSettings>
{
	UCSINGLETON( UCManagerSettings );

	typedef QSharedPointer<QSettings> QSettings_sp;

	virtual void				Initialize();
	virtual void				Uninitialize();

public:
	// Identification-Values
	const static QString		PATH_SETTINGS;
	const static QString		ID_DIRECTORIES_BUNDLE;



	/*! \brief     Retrieves all paths that was saved to settings earlier
		\return    QT_NAMESPACE::QStringList - Containing all strings to bundle-directories
	*/
	QStringList					GetBundleDirectories();

	/*! \brief     Saves a List with given bundle-directories to an ini-file
		\param     paths - QStringList containing all paths
	*/
	void						SetBundleDirectories( QStringList& paths );

private:
	QSettings_sp				m_Settings; 	/*!< QT-Object writing/reading objectfile from ./data/settings.ini */
};


}
