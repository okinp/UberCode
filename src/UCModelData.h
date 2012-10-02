#pragma once
#include <QString>
#include <QVariant>
#include <QSharedPointer>
#include "_2RealApplication.h"

namespace Uber
{

class UCModelData;
typedef QSharedPointer<UCModelData> UCModelData_sptr;

/*!
* Abstraction-Layer of Inlets/Outlets to read or write data
* Note: derived classes have to implement methods for each used Primitive-Type!
* Note: Add additional types to this class/header file
*/
class UCModelData
{
protected:
	UCModelData();
public:

	virtual ~UCModelData(){}
	/*! \brief		Returns the name of the Inlet/Outlet as a QString*/
	virtual const QString				Name() const = 0;

	/*! \brief		Returns the type of the a QString (whether "Inlet" / "Outlet" */
	virtual const QString				Type() const = 0;

	/*! \brief		Writes data to a Inlet
					Note: Data-implementation depends on Inlet-Primitive-template-type of derived class */
	virtual void						SetData( QString& str ) = 0;

	/*! \brief		Reads data from a Inlet or Outlet
					Note: Data-implementation depends on Outlet-Primitive-template-type of derived class */
	virtual const QString				Data() const = 0;

	/*! \brief		Returns a new allocated UCModelData-shared-ptr object
					Note: type lookup will be made in here
		\param		handle - handle to a inlet of a block
		\return		Uber::UCModelData_sptr - new allocated object
	*/
	static UCModelData_sptr				CreateModelData( const _2Real::app::InletHandle& handle );

	/*! \brief		Returns a new allocated UCModelData-shared-ptr object
					Note: type lookup will be made in here
		\param		handle - handle to a outlet of a block
		\return		Uber::UCModelData_sptr - new allocated object
	*/
	static UCModelData_sptr				CreateModelData( const _2Real::app::OutletHandle& handle );
};



template <class T>
class UCModelDataPrimitiveInlet : public UCModelData
{
public:

	virtual const QString				Name() const;
	virtual const QString				Type() const;
	virtual void						SetData( QString& str );
	virtual const QString				Data() const;

private:
	// creation only by factory method
	UCModelDataPrimitiveInlet( const _2Real::app::InletHandle& handle );
	UCModelDataPrimitiveInlet( const UCModelDataPrimitiveInlet& obj );
	UCModelDataPrimitiveInlet& operator=( const UCModelDataPrimitiveInlet& obj );

	_2Real::app::InletHandle			m_Handle;

	friend class UCModelData;
};



template <class T>
class UCModelDataPrimitiveOutlet : public UCModelData
{
	typedef T ValueType;
public:
	~UCModelDataPrimitiveOutlet();

	virtual const QString				Name() const;
	virtual const QString				Type() const;
	virtual void						SetData( QString& str );
	virtual const QString				Data() const;
	void								OnNewData( const _2Real::app::AppData& data );

private:
	// creation only by factory method
	UCModelDataPrimitiveOutlet( const _2Real::app::OutletHandle& handle );
	UCModelDataPrimitiveOutlet( const UCModelDataPrimitiveOutlet& obj );
	UCModelDataPrimitiveOutlet& operator=( const UCModelDataPrimitiveOutlet& obj );


	_2Real::app::OutletHandle			m_Handle;
	 ValueType							m_Data;

	 friend class UCModelData;
};


inline UCModelData_sptr UCModelData::CreateModelData( const _2Real::app::InletHandle& handle )
{
	const std::string typeName = handle.getTypename();
	if( typeName == "int" )
		return UCModelData_sptr( new UCModelDataPrimitiveInlet<int>( handle ) );
	else if( typeName == "float" )
		return UCModelData_sptr( new UCModelDataPrimitiveInlet<float>( handle ) );
	else if( typeName == "string" )
		return UCModelData_sptr( new UCModelDataPrimitiveInlet<QString>( handle ) );
	else if( typeName == "bool" )
		return UCModelData_sptr( new UCModelDataPrimitiveInlet<bool>( handle ) );

	throw( std::exception( "Error in _2Real::app::InletHandle: Type could not be evaluated! You may correct UCModeldata::CreateModeldata!!!" ) );
}

inline UCModelData_sptr UCModelData::CreateModelData( const _2Real::app::OutletHandle& handle )
{
	const std::string typeName = handle.getTypename();
	if( typeName == "int" )
		return UCModelData_sptr( new UCModelDataPrimitiveOutlet<int>( handle ) );
	else if( typeName == "float" )
		return UCModelData_sptr( new UCModelDataPrimitiveOutlet<float>( handle ) );
	else if( typeName == "string" )
		return UCModelData_sptr( new UCModelDataPrimitiveOutlet<QString>( handle ) );
	else if( typeName == "bool" )
		return UCModelData_sptr( new UCModelDataPrimitiveOutlet<bool>( handle ) );
	else if( typeName == "number image" )
	{
		std::cout << "How to implement \"number image\" type in UCModelData::CreateModelData()?!" << std::endl;
		return UCModelData_sptr( new UCModelDataPrimitiveOutlet<bool>( handle ) ); // Todo: how to implement this?!
	}

	throw( std::exception( "Error in _2Real::app::OutletHandle: Type could not be evaluated! You may correct UCModeldata::CreateModeldata!!!" ) );
}

inline UCModelData::UCModelData()
{

}


/* Inlet Definition */


template <class T>
Uber::UCModelDataPrimitiveInlet<T>::UCModelDataPrimitiveInlet( const _2Real::app::InletHandle& handle )
	: UCModelData(), m_Handle( handle )
{

}

template <class T>
const QString Uber::UCModelDataPrimitiveInlet<T>::Name() const
{
	return QString::fromStdString( m_Handle.getName() );
}

template <class T>
const QString Uber::UCModelDataPrimitiveInlet<T>::Type() const
{
	return QString( "Inlet" );
}

template<>
inline void Uber::UCModelDataPrimitiveInlet<int>::SetData( QString& str )
{
	m_Handle.setValue<int>( QVariant( str ).toInt() );
}

template<>
inline void Uber::UCModelDataPrimitiveInlet<float>::SetData( QString& str )
{
	m_Handle.setValue<float>( QVariant( str ).toFloat() );
}

template<>
inline void Uber::UCModelDataPrimitiveInlet<QString>::SetData( QString& str )
{
	m_Handle.setValue<std::string>( QVariant( str ).toString().toStdString() );
}

template<>
inline void Uber::UCModelDataPrimitiveInlet<bool>::SetData( QString& str )
{
	QString lStr = str.toLower();
	if( lStr == "0" || lStr == "false" )
		m_Handle.setValue<bool>( 0 );
	else if( lStr == "1" || lStr == "true" )
		m_Handle.setValue<bool>( 1 );
}

template <>
inline const QString Uber::UCModelDataPrimitiveInlet<bool>::Data() const
{
	return QVariant( m_Handle.getCurrentInput().getData<bool>() ).toString();
}

template <>
inline const QString Uber::UCModelDataPrimitiveInlet<float>::Data() const
{ 
	return QVariant( m_Handle.getCurrentInput().getData<float>() ).toString();
}

template <>
inline const QString Uber::UCModelDataPrimitiveInlet<int>::Data() const
{
	return QVariant( m_Handle.getCurrentInput().getData<int>() ).toString();
}

template <>
inline const QString Uber::UCModelDataPrimitiveInlet<QString>::Data() const
{
	return QString::fromStdString( m_Handle.getCurrentInput().getData<std::string>() );
}

/* Outlet Definition */


template <class T>
Uber::UCModelDataPrimitiveOutlet<T>::UCModelDataPrimitiveOutlet( const _2Real::app::OutletHandle& handle )
	: UCModelData(), m_Handle( handle )
{
	m_Handle.registerToNewData<UCModelDataPrimitiveOutlet>( *this, &UCModelDataPrimitiveOutlet<T>::OnNewData );
}

template <class T>
Uber::UCModelDataPrimitiveOutlet<T>::~UCModelDataPrimitiveOutlet()
{
	m_Handle.unregisterFromNewData<UCModelDataPrimitiveOutlet>( *this, &UCModelDataPrimitiveOutlet<T>::OnNewData );
}


template <class T>
inline const QString Uber::UCModelDataPrimitiveOutlet<T>::Name() const
{
	return QString::fromStdString( m_Handle.getName() );
}

template <class T>
inline const QString Uber::UCModelDataPrimitiveOutlet<T>::Type() const
{
	return QString( "Outlet" );
}

template <class T>
void Uber::UCModelDataPrimitiveOutlet<T>::OnNewData( const _2Real::app::AppData& data )
{
	m_Data = data.getData<T>();
}

template <>
inline void Uber::UCModelDataPrimitiveOutlet<bool>::SetData( QString& str )
{

}

template <>
inline void Uber::UCModelDataPrimitiveOutlet<int>::SetData( QString& str )
{

}
template <>
inline void Uber::UCModelDataPrimitiveOutlet<float>::SetData( QString& str )
{

}
template <>
inline void Uber::UCModelDataPrimitiveOutlet<QString>::SetData( QString& str )
{

}


template<>
inline void Uber::UCModelDataPrimitiveOutlet<QString>::OnNewData( const _2Real::app::AppData& data )
{
	m_Data = QString::fromStdString( data.getData<std::string>() );
}

template <class T>
inline const QString Uber::UCModelDataPrimitiveOutlet<T>::Data() const
{
	return QVariant( (ValueType)m_Data ).toString();
}

template <>
inline const QString Uber::UCModelDataPrimitiveOutlet<bool>::Data() const
{
	return QVariant( m_Data ).toString();
}

}