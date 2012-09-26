#pragma once
#include <QAbstractListModel>
#include <_2RealApplication.h>

namespace Uber
{

/*!
* Holds all information about a block and grants access to them
* This object can be set in a QTreeView or QTableView to print info
*/
class UCBlockModel : public QAbstractListModel
{	
	/*!
	* Structure to store data for inlets/outlets
	* Note: only use QString members!!!!
	*/
	struct UCModelData
	{
		QString				name;		/*!< name of the inlet/outlet */
		QString				type;		/*!< wheter "Inlet" / "Outlet" depending on type */
		QString				data;		/*!< Data of the inlet/outlet represented by a string */
	};

	/*!
	* Enum-representation of a column in this model
	*/
	enum UCModelDataRowID
	{
		ROWID_NAME = 0,
		ROWID_TYPE,
		ROWID_DATA
	};

	typedef std::vector<UCModelData> ModelDataList; 		/*!< Datastructure to store inlet/outlet information to display in a view */

public:
	static const QString			STR_INLET;
	static const QString			STR_OUTLET;

	UCBlockModel( const QString& bundleName, const QString& blockName );
	virtual ~UCBlockModel(void);

	virtual QModelIndex				index( int row, int column, const QModelIndex &parent = QModelIndex( ) ) const;
	virtual int						rowCount( const QModelIndex &parent = QModelIndex( ) ) const;
	virtual int						columnCount( const QModelIndex &parent = QModelIndex( ) ) const;
	virtual QVariant				data( const QModelIndex &index, int role = Qt::DisplayRole ) const;
	/*virtual bool					setData( const QModelIndex &index, const QVariant &value, int role = Qt::EditRole );*/
	virtual QVariant				headerData( int section, Qt::Orientation orientation, int role = Qt::DisplayRole ) const;
	virtual Qt::ItemFlags			flags( const QModelIndex &index ) const;

	const QString&					GetBundleName() const;
	const QString&					GetBlockName() const;
	_2Real::app::BundleHandle*		GetBundleHandle();
	_2Real::app::BlockHandle*		GetBlockHandle();


private:


	/*! \brief		Will be called in initialization list to init m_HandleBundle
		\return		_2Real::app::BundleHandle* - nullptr or a ptr on success
	*/
	inline _2Real::app::BundleHandle*			InitBundleHandle();

	/*! \brief		Will be called in initialization list to init m_HandleBlock
		\return		_2Real::app::BlockHandle* - nullptr or a ptr on success
	*/
	inline _2Real::app::BlockHandle*			InitBlockHandle();


	QString										m_NameBundle; 		/*!< Name of the bundle, used to fetch bundlehandle from bundlemanager */
	QString										m_NameBlock;		/*!< name of block, used to create handle through bundlehandle */
	_2Real::app::BundleHandle*					m_HandleBundle;		/*!< Handle to bundle instance - responsible for instancing of blocks / bundle unloading */
	_2Real::app::BlockHandle*					m_HandleBlock;		/*!< Handle to block instance - accessing inlet/outlet handles */
	const unsigned int							m_CountInlets, m_CountOutlets; 		/*!< Quantity of inlets/outlets found in a block */
	ModelDataList								m_Data; 			/*!< Storing UCModelData-Objects for each inlet/outlet */
};


}
