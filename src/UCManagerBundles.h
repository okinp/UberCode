#pragma once
#include "UCSingleton.h"
#include "_2RealApplication.h"
#include <map>
#include <QObject>


class QStringList;
class QString;

namespace Uber
{

// creating new type for easily switching engine types over all
typedef	_2Real::app::Engine TypeEngine;
typedef TypeEngine* TypePtrEngine;
typedef TypeEngine& TypeRefEngine;
typedef TypeRefEngine (*TypeInitializeEngine)(); 	/*!< functor-prototype to init-function for m_engine member */

static TypeInitializeEngine _InitEngine = _2Real::app::Engine::instance; 	/*!< global engine initializer-function */

typedef QString BlockName;
typedef std::pair<BlockName, _2Real::app::BlockInfo>		BlockInfo; 		/*!< contains block name and info */
typedef std::vector<BlockInfo>								BlockInfoList; 	/*!< containing information about blocks from a bundle */
typedef std::pair<_2Real::app::BundleHandle, BlockInfoList>	BundleInfo;		/*!< containing all blocks (BlockInfoList) hashed by bundleHandle */
typedef std::vector<BundleInfo>								BundleInfoList; /*!< containing information about all bundles */
/*!
* Handles loading from bundles and provides UCNodes which can be pulled
* to main windows graphic scene
*/
class UCManagerBundles : public QObject, public UCSingleton<UCManagerBundles>
{
	UCSINGLETON( UCManagerBundles )
	Q_OBJECT

	typedef QString								BundleName;
	typedef std::map<BundleName, BundleInfo>	BlockContainer; 	/*!< std::map containing all bundles hashed by bundleName */

public:

	virtual void				Initialize();
	virtual void				Uninitialize();

	/*! \brief		Loads Bundles from paths delivered by UCManagerSettings */
	void						LoadBundles();

	/*! \brief		Loads Bundles from the given list containing directory-paths
		\param		directoryPaths - a list containing paths to find bundles
	*/
	void						LoadBundles( const QStringList& directoryPaths );

	/*! \brief		Loads a bundle from a given bundle-path
		\param		bundlePath - path to a bundle to load
	*/
	void						LoadBundle( const QString& bundlePath );

	/*! \brief		Scans the given paths for bundles to load
		\param		directoryPaths - QStringList containing paths to directories that should be looked up
		\param		out - QStringlist filled with paths to found bundles
	*/
	void						FetchBundlePaths( const QStringList& directoryPaths, QStringList& out ) const;

	/*! \brief		Returns all loaded Blocks and their corresponding infos
		\param		out - BlockInstancingInfoList to fill in all available blocks
	*/
	void						GetLoadedBlocks( BlockInfoList& out ) const;

	/*! \brief		Returns all loaded Bundles in a BundleInfoList
		\param		out - BundleInfoList to fill in all available bundles
	*/
	void						GetLoadedBundles( BundleInfoList& out ) const;

	/*! \brief		Gets a BlockInfo resolved by its bundle- and block-name */
	BlockInfo&					GetBlock( const BundleName& bundleName, const BlockName& blockName ) const;

	/*! \brief		Returns a BundleInfo resolved by its bundle name */
	BundleInfo&					GetBundle( const BundleName& name ) const;

signals:

	/*! \brief		Notification send on load of new bundle*/
	void						NotifyBundleDetected( const QString& bundleName, const BlockInfoList& blocks );
	/*! \brief		Notification send on unload of a bundle*/
	void						NotifyBundleUnloaded( const QString& bundleName, const BlockInfoList& blocks );

private:

	mutable BlockContainer						m_Blocks;			/*!< Instances of all loaded bundles/blocks */
	static TypeRefEngine						m_Engine;			/*!< Pointer to 2Real-Engine */
};

}
