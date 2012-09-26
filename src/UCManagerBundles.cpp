#include <QStringList>
#include <QString>
#include <QDir>
#include "UCTreeWidgetBundles.h"
#include "UCManagerSettings.h"



using namespace Uber;
using namespace _2Real;
using namespace app;

TypeRefEngine UCManagerBundles::m_Engine = _InitEngine();

// empty objects for getter functions
// prevent warning: not all control paths return a value
Uber::BlockInfo __emptyBlock;
Uber::BundleInfo __emptyBundle;

void Uber::UCManagerBundles::Initialize()
{
	
}

void Uber::UCManagerBundles::Uninitialize()
{
	
}

void Uber::UCManagerBundles::FetchBundlePaths( const QStringList& directoryPaths, QStringList& out ) const
{
	out.clear();
	QStringList::const_iterator iter = directoryPaths.constBegin();
	QStringList::const_iterator end = directoryPaths.constEnd();

	for ( ; iter != end; ++iter )
	{
		QDir dir( *iter ); // open directory
		if( dir.exists() )
		{
			QStringList nameFilters;
			// filter bundles by file-type
			nameFilters << "*.dll" << "*.DLL" << "*.so" << "*.a" << "*.sl" << "*.dylib" << "*.bundle" ;

			QFileInfoList fileInfoList = dir.entryInfoList( nameFilters, QDir::Files | QDir::Readable );
			QFileInfoList::const_iterator filesIter = fileInfoList.constBegin();
			QFileInfoList::const_iterator filesEnd = fileInfoList.constEnd();

			// append to string list
			for ( ; filesIter != filesEnd; ++filesIter )
				out <<  filesIter->canonicalFilePath();
		}
		else
			std::cout << "Directory \"" << iter->toStdString() << "\" does not exist!" << std::endl;
	}
}

void Uber::UCManagerBundles::LoadBundles()
{
	LoadBundles( UCManagerSettings::GetInstance().GetBundleDirectories() );
}

void Uber::UCManagerBundles::LoadBundles( const QStringList& directoryPaths )
{
	QStringList bundlePaths;
	// fetch all paths to bundles in all given directories
	FetchBundlePaths( directoryPaths, bundlePaths );

	// load all bundles
	QStringList::const_iterator iter = bundlePaths.constBegin();
	QStringList::const_iterator end = bundlePaths.constEnd();
	for( ; iter != end; ++iter )
		LoadBundle( *iter );
}

void Uber::UCManagerBundles::LoadBundle( const QString& bundlePath )
{
	try
	{
		// getting 2real information
		_2Real::app::BundleHandle& bundleHandle = m_Engine.loadBundle( bundlePath.toStdString() );
		const _2Real::app::BundleInfo& bundleInfo = bundleHandle.getBundleInfo();
		const _2Real::app::BundleInfo::BlockInfos& blocks = bundleInfo.exportedBlocks;
		
		// put them into m_blocks if they aren't already in map
		_2Real::app::BundleInfo::BlockInfos::const_iterator iter = blocks.begin();
		_2Real::app::BundleInfo::BlockInfos::const_iterator end = blocks.end();
		BlockInfoList bundleBlocks;

		// filter blocks and put BlockInfo to BlockInfoList
		for ( ; iter!= end; ++iter )
			bundleBlocks.push_back( BlockInfo( QString::fromStdString( iter->name ), *iter ) );

		// Create a BundleInfo and put it to BlockContainer hashed by bundle name
		BundleName bundleName = QString::fromStdString( bundleInfo.name );
		m_Blocks.insert( std::make_pair( bundleName, BundleInfo( bundleHandle,
																 bundleBlocks ) ) );
		// send notification to observer
		emit NotifyBundleDetected( bundleName, bundleBlocks ); 
	}
	catch ( NotFoundException& )
	{
	}
	catch ( AlreadyExistsException& )
	{
		std::cout << bundlePath.toStdString() << " has already been loaded." << std::endl;
	}
	catch ( ... )
	{
		std::cout << "Other exception" << std::endl;
	}
}

void Uber::UCManagerBundles::GetLoadedBlocks( BlockInfoList& out ) const
{
	out.clear();
	BlockContainer::const_iterator iter = m_Blocks.begin();
	BlockContainer::const_iterator end = m_Blocks.end();
	
	for( ; iter != end; ++iter )
	{
		BlockInfoList& infos = *const_cast<BlockInfoList*>( &iter->second.second );
		out.insert( out.begin(), infos.begin(), infos.end() );
	}
}

void Uber::UCManagerBundles::GetLoadedBundles( BundleInfoList& out ) const
{
	out.clear();
	BlockContainer::const_iterator iter = m_Blocks.begin();
	BlockContainer::const_iterator end = m_Blocks.end();

	for( ; iter != end; ++iter )
		out.push_back( *const_cast<BundleInfo*>( &iter->second ) );
}

Uber::BlockInfo& Uber::UCManagerBundles::GetBlock( const BundleName& bundleName, const BlockName& blockName ) const
{
	BlockInfoList& blocks = GetBundle( bundleName ).second;
	BlockInfoList::iterator iter = blocks.begin();
	BlockInfoList::const_iterator end = blocks.end();
	for( ; iter != end; ++iter )
		if( iter->first == blockName )
			return *iter;
	return __emptyBlock;
}

Uber::BundleInfo& Uber::UCManagerBundles::GetBundle( const BundleName& name ) const
{
	if( m_Blocks.find( name ) != m_Blocks.end() )
		return m_Blocks[name];
	return __emptyBundle;
}
