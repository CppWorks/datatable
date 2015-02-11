
#include "stdafx.h"
#include "Column.h"
#include "DataTable.h"

#include <boost/lexical_cast.hpp>
using namespace boost;

std::wstring a2w(const std::string& source)
{
	std::wstring dest(source.length(), L' ');
	std::copy(source.begin(), source.end(), dest.begin());
	return dest; 
}


Column::Column()
{
	AllowDBNull = true;
	AutoIncrement = false;
	PrimaryKey = false;
	Unique = false;
	DataType = 0;
	MaxLength = 0;

	Table = 0;
}
Column::~Column(){}

bool Column::operator==(Column& rhs)
{
	if( AllowDBNull != rhs.AllowDBNull )
		return false;
	if( AutoIncrement != rhs.AutoIncrement )
		return false;
	if( Caption != rhs.Caption )
		return false;
	if( ColumnName != rhs.ColumnName )
		return false;
	if( DataType != rhs.DataType )
		return false;
	if( DefaultValue != rhs.DefaultValue )
		return false;
	if( PrimaryKey != rhs.PrimaryKey )
		return false;
	if( SqlName != rhs.SqlName )
		return false;
	if( Unique != rhs.Unique )
		return false;
	if( MaxLength != rhs.MaxLength )
		return false;

	return true;
}
bool Column::operator!=(Column& rhs)
{
	if( AllowDBNull != rhs.AllowDBNull )
		return true;
	if( AutoIncrement != rhs.AutoIncrement )
		return true;
	if( Caption != rhs.Caption )
		return true;
	if( ColumnName != rhs.ColumnName )
		return true;
	if( DataType != rhs.DataType )
		return true;
	if( DefaultValue != rhs.DefaultValue )
		return true;
	if( PrimaryKey != rhs.PrimaryKey )
		return true;
	if( SqlName != rhs.SqlName )
		return true;
	if( Unique != rhs.Unique )
		return true;
	if( MaxLength != rhs.MaxLength )
		return true;

	return false;
}

wstring Column::serialize()
{
	wstring data = L"\t\t\t<COLUMN name=\"";
	data += SqlName;
	data += L"\" AllowDBNull=\"";
	data += lexical_cast<wstring>(AllowDBNull);
	data += L"\" AutoIncrement=\"";
	data += lexical_cast<wstring>(AutoIncrement);
	data += L"\" DataType=\"";
	data += lexical_cast<wstring>(DataType);
	data += L"\" DefaultValue=\"";
	data += DefaultValue;
	data += L"\" PrimaryKey=\"";
	data += lexical_cast<wstring>(PrimaryKey);
	data += L"\" Unique=\"";
	data += lexical_cast<wstring>(Unique);
	data += L"\" MaxLength=\"";
	data += lexical_cast<wstring>(MaxLength);
	data += L"\" ></COLUMN>\n";

	return data;
}
void Column::deserialize(const wstring& _xmldata)
{

}

//bool Column::operator ==(const Column& u)
//{
//	wstring en = ColumnName;
//	wstring sc = u.ColumnName;
//	
//	to_upper(en, Table ? Table->Locale() : locale::classic() );
//	to_upper(sc, Table ? Table->Locale() : locale::classic() );
//
//	if( en != sc )
//		return false;
//
//	if( DataType != u.DataType )
//		return false;
//
//	if( Table && u.Table )
//	{
//		en = Table->TableName;
//		sc = u.Table->TableName;
//		
//		to_upper(en, Table ? Table->Locale() : locale::classic() );
//		to_upper(sc, Table ? Table->Locale() : locale::classic() );
//
//		if( en != sc )
//			return false;
//	}
//
//	return true;
//}