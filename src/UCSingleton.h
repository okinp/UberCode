#pragma once

namespace Uber
{
/*!
* Template Singleton implementation, use it through derivation
* NOTE: If using macro UCSINGLETON( classname ): do not declare Ctor/CpyCtor/Dtor or operator=
* they are handled by base class, for initialization/uninitialization use virtual methods
* NOTE: If NOT using macro UCSINGLETON( classname ): Costume definition of ctor is possible but
* be aware of declaring CpyCtor/Dtor/operator= private
* NOTE: Not Threading save
*/
template< class T >
class UCSingleton
{
	typedef T* TypePtr;
	typedef T& TypeRef;

public:

	/*! \brief     Returns a Reference to an Object, Object will be allocated on first call to this function
		\return    RefType - Reference to Singleton Object
	*/
	static TypeRef				GetInstance()
	{
		if( !m_Instance )
		{
			m_Guard.m_Charge = m_Instance = new T();
			m_Instance->Initialize();
		}
		return *m_Instance;
	}

	/*! \brief	  Releases the memory if GetInstance() allocated memory before */
	static void					Release()
	{
		if( m_Instance )
		{
			delete m_Instance;
			m_Instance = nullptr;
			m_Guard.m_Charge = nullptr;
		}
	}

protected:
	UCSingleton(){}
	virtual ~UCSingleton(){ m_Guard.m_Charge = m_Instance = nullptr; }

	/*! \brief     Will be called when Object gets initialized	*/
	virtual void				Initialize() = 0;

	/*! \brief     Will be called before Object will be deleted	*/
	virtual void				Uninitialize() = 0;

private:
	// Non copyable object
	UCSingleton( const UCSingleton& obj );
	UCSingleton& operator=( const UCSingleton& obj );
	
	static TypePtr					m_Instance;

	/*!
	* Object created in global memory, will be destroyed at program
	* end and delete singleton safely
	*/
	class Guard
	{
	public:
		Guard() : m_Charge( nullptr ) {}
		~Guard(){ if( m_Charge) { m_Charge->Uninitialize(); delete m_Charge; m_Charge = nullptr; } }

		TypePtr						m_Charge;
	};
	static Guard					m_Guard;
	friend class Guard;
};

// Static member-ptrs need to be globally initialized
template<class T>
typename Uber::UCSingleton<T>::TypePtr Uber::UCSingleton<T>::m_Instance = nullptr; // typename -> PtrType is type not function-ptr

template<class T>
typename Uber::UCSingleton<T>::Guard Uber::UCSingleton<T>::m_Guard;

/*!
* Macro for defining all important ctors/operators private
* Use it if there is no need for a custom Ctor
* sets base-class as a friend
*/
#define UCSINGLETON( classname ) private: classname(){ } \
classname( const classname& ); \
~classname() {} \
classname& operator=( const classname& );\
friend class UCSingleton<classname>;\

}
