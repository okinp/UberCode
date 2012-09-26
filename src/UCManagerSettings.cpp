#include "UCManagerSettings.h"

using namespace Uber;

const QString UCManagerSettings::PATH_SETTINGS = "data\\Settings.ini";
const QString UCManagerSettings::ID_DIRECTORIES_BUNDLE = "BundleDirectories";


void Uber::UCManagerSettings::Initialize()
{
	m_Settings = QSettings_sp( new QSettings( PATH_SETTINGS, QSettings::IniFormat ) );
}

void Uber::UCManagerSettings::Uninitialize()
{

}

QStringList Uber::UCManagerSettings::GetBundleDirectories()
{
	return m_Settings->value( ID_DIRECTORIES_BUNDLE ).toStringList();
}

void Uber::UCManagerSettings::SetBundleDirectories( QStringList& paths )
{
	m_Settings->setValue( ID_DIRECTORIES_BUNDLE, paths );
	m_Settings->sync();
}
