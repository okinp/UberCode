#pragma once
#include <QString>
namespace _2Real{namespace app{class InletHandle; class OutletHandle; }}

namespace Uber
{


class UCNodeInfo
{
protected:
	UCNodeInfo( const QString& Name, const QString& Type, const QString& Value, const unsigned int Index )
		: name( Name ),
		type( Type ),
		value( Value ),
		index( Index )
	{

	}
public:

	const QString&			name;
	const QString&			type;
	const QString&			value;
	const unsigned int		index;

	friend class UCBlockModel;
};

class UCInletInfo : public UCNodeInfo
{
	UCInletInfo( const QString& Name, const QString& Type, const QString& Value, const unsigned int Index, const _2Real::app::InletHandle& Handle )
		: UCNodeInfo( Name, Type, Value, Index ),
		handle( Handle )
	{}

public:

	const _2Real::app::InletHandle&		handle;

	friend class UCBlockModel;
};

class UCOutletInfo : public UCNodeInfo
{
	UCOutletInfo( const QString& Name, const QString& Type, const QString& Value, const unsigned int Index, const _2Real::app::OutletHandle& Handle )
		: UCNodeInfo( Name, Type, Value, Index ),
		handle( Handle )
	{}

public:

	const _2Real::app::OutletHandle&		handle;

	friend class UCBlockModel;
};

}