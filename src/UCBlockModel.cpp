#include "UCBlockModel.h"
#include "UCManagerBundles.h"

#include "UCWindowMain.h"
#include <QTreeView>


using namespace Uber;
using namespace _2Real::app;

const QString UCBlockModel::STR_INLET = QString( "Inlet" );
const QString UCBlockModel::STR_OUTLET = QString( "Outlet" );

Uber::UCBlockModel::UCBlockModel( const QString& bundleName, const QString& blockName )
    : QAbstractListModel( nullptr ),
      m_NameBundle( bundleName ),
      m_NameBlock( blockName ),
      m_HandleBundle( InitBundleHandle() ),
      m_HandleBlock( InitBlockHandle() ),
      m_CountInlets( m_HandleBlock ? m_HandleBlock->getAllInletHandles().size() : 0 ),
      m_CountOutlets( m_HandleBlock ? m_HandleBlock->getAllOutletHandles().size() : 0 ),
      m_Data( m_HandleBlock ? m_CountInlets + m_CountOutlets : 0 ) /*!< set initial size of map count of all outlets/inlets */
{

    const unsigned int size = m_Data.size();
    const BlockHandle::InletHandles& inlets = m_HandleBlock->getAllInletHandles();
    const BlockHandle::OutletHandles& outlets = m_HandleBlock->getAllOutletHandles();
    UCModelData data;

    // filling data to member
    // inlets before outlets
    for( int i = 0; i < size; ++i )
    {
        if( i < m_CountInlets ) // insert inlets
        {
            const InletHandle& inlet = inlets[i];		
            data.name = QString::fromStdString( inlet.getName() );
            data.type = STR_INLET;
        }
        else // insert outlets
        {
            const OutletHandle& outlet = outlets[i-m_CountInlets];
            data.name = QString::fromStdString( outlet.getName() );
            data.type = STR_OUTLET;
        }
        data.data = QString( "N/A" );
        m_Data[i] = data;
    }
  
    m_HandleBlock->start();
}


_2Real::app::BundleHandle* Uber::UCBlockModel::InitBundleHandle()
{
    _2Real::app::BundleHandle* handle = &UCManagerBundles::GetInstance().GetBundle( m_NameBundle ).first;
    if( handle->isValid() )
        return handle;
    return nullptr;
}

_2Real::app::BlockHandle* Uber::UCBlockModel::InitBlockHandle()
{
    try
    {
        if( m_HandleBundle->isValid() )
        {
            _2Real::app::BlockHandle* handle = &m_HandleBundle->createBlockInstance( m_NameBlock.toStdString() );
            handle->setUpdateRate( 30.0f );
            handle->setup();
            return handle;
        }
    }
    catch ( _2Real::Exception& e )
    {
        std::cout << e.message() << " " << e.what() << std::endl;
    }
    return nullptr;
}

UCBlockModel::~UCBlockModel(void)
{

}

QModelIndex Uber::UCBlockModel::index( int row, int column, const QModelIndex &parent /*= QModelIndex( ) */ ) const
{
    if ( parent.isValid() && parent.column() != 0 )
        return QModelIndex();

    const UCModelData* item = &m_Data[row];

    switch( column )
    {	
    case ROWID_NAME:
        return createIndex( row, column, (void*)&item->name );
    case ROWID_TYPE:
        return createIndex( row, column, (void*)&item->type );
    case ROWID_DATA:
        return createIndex( row, column, (void*)&item->data );
    default:
        return QModelIndex();
    }
}

int Uber::UCBlockModel::rowCount( const QModelIndex &parent /*= QModelIndex( ) */ ) const
{
    return m_Data.size();
}

int Uber::UCBlockModel::columnCount( const QModelIndex &parent /*= QModelIndex( ) */ ) const
{
    // row for every member in UCModelDataRowID-struct
    return unsigned int( sizeof( UCModelData ) / sizeof( QString ) );
}

QVariant Uber::UCBlockModel::data( const QModelIndex &index, int role /*= Qt::DisplayRole */ ) const
{
    if ( !index.isValid() )
        return QVariant();

    if ( index.row() >= m_Data.size() || index.row() < 0 )
        return QVariant();

    if( role != Qt::DisplayRole )
        return QVariant();
    
    switch( index.column() )
    {	
        case ROWID_NAME:
            return m_Data[index.row()].name;
        case ROWID_TYPE:
            return m_Data[index.row()].type;
        case ROWID_DATA:
            return m_Data[index.row()].data;
        default:
            return QVariant();
    }
}
//
//bool Uber::UCBlockModel::setData( const QModelIndex &index, const QVariant &value, int role /*= Qt::EditRole */ )
//{
//	/*if (role != Qt::EditRole)
//		return false;
//
//	TreeItem *item = getItem(index);
//	bool result = item->setData(index.column(), value);
//
//	if (result)
//		emit dataChanged(index, index);
//
//	return result;*/
//	return QAbstractListModel::setData( index, value, role );
//}

QVariant Uber::UCBlockModel::headerData( int section, Qt::Orientation orientation, int role /*= Qt::DisplayRole */ ) const
{
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole) {
        switch (section) {
        case 0:
            return tr( "Name" );
        case 1:
            return tr( "Node-Type" );
        case 2:
            return tr( "Value" );
        default:
            return QVariant();
        }
    }

    return QVariant();
}

Qt::ItemFlags Uber::UCBlockModel::flags( const QModelIndex &index ) const
{
    if ( !index.isValid() )
        return 0;

    if( index.column() == ROWID_DATA )
        return Qt::ItemIsEditable | Qt::ItemIsEnabled | Qt::ItemIsSelectable;
    return 0;
}

const QString& Uber::UCBlockModel::GetBundleName() const
{
    return m_NameBundle;
}

const QString& Uber::UCBlockModel::GetBlockName() const
{
    return m_NameBlock;
}

_2Real::app::BundleHandle* Uber::UCBlockModel::GetBundleHandle()
{
    return m_HandleBundle;
}

_2Real::app::BlockHandle* Uber::UCBlockModel::GetBlockHandle()
{
    return m_HandleBlock;
}
