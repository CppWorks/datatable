

#include "stdafx.h"
#include "ColumnCollection.h"
#include "DException.h"
#include "DataTable.h"

#include <boost/algorithm/string.hpp>

using namespace boost;

ColumnCollection::ColumnCollection()
{
	table = 0;
}
void ColumnCollection::Add( Column column )
{
	for(unsigned int i = 0; i < cols.size(); i++)
	{
		wstring en = cols[i].ColumnName;//Existing Name;
		wstring sc = column.ColumnName;//search criteria
		
		to_upper(en, table ? table->Locale() : locale::classic() );
		to_upper(sc, table ? table->Locale() : locale::classic() );

		if( en == sc )
			throw DException(L"DataTable has already a column with same name");		
	}
	column.Table = table;
	cols.push_back( column );
}
void ColumnCollection::Add( const wstring& columnName, int dataType)
{
	for(unsigned int i = 0; i < cols.size(); i++)
	{
		wstring en = cols[i].ColumnName;//Existing Name;
		wstring sc = columnName;//search criteria
		
		to_upper(en, table ? table->Locale() : locale::classic() );
		to_upper(sc, table ? table->Locale() : locale::classic() );

		if( en == sc )
			throw DException(L"DataTable has already a column with same name");		
	}

	Column c;
	c.ColumnName = columnName;
	c.DataType = dataType;
	c.Table = table;
	cols.push_back(c);
}
Column& ColumnCollection::operator[](unsigned int index)
{
	if( index > cols.size() )
		throw DException(L"Index out of range");

	return cols[index];
}
Column& ColumnCollection::operator[](const wstring& name)
{
	for(unsigned int i = 0; i < cols.size(); i++)
	{
		wstring en = cols[i].ColumnName;//Existing Name;
		wstring sc = name;//search criteria
		
		to_upper(en, table ? table->Locale() : locale::classic() );
		to_upper(sc, table ? table->Locale() : locale::classic() );

		if( en == sc )
			return cols[i];
	}
	throw DException(L"DataTable does not have a column with such a name");
}

unsigned int ColumnCollection::Count()
{
	return cols.size();
}
void ColumnCollection::Clear()
{
	cols.clear();
}
void ColumnCollection::Table(DataTable* _table)
{
	table = _table;
	for(unsigned int i = 0; i < cols.size(); i++)
		cols[i].Table = table;
}
