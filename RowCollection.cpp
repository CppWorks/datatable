

#include "stdafx.h"
#include "RowCollection.h"
#include "DException.h"


#pragma warning (disable:4267)
RowCollection::~RowCollection()
{
}
void RowCollection::Add(Row row)
{
	if( row.Table() != table )
		throw DException(L"This Row is belongs to another DataTable");

	if( row.state & RS_ADDED )
		throw DException(L"This Row is already belongs to this DataTable");
	
	row.order = rows.size();
	row.state = RS_ADDED;

	rows.push_back(row);
}
unsigned int RowCollection::Count()
{
	return rows.size();
}
Row& RowCollection::operator[](unsigned int index)
{
	if( index >= rows.size() )
		throw DException(L"Index out of range");
	return rows[index];
}
void RowCollection::Remove(Row row)
{
	for( vector<Row>::iterator it = rows.begin(); it != rows.end(); ++it )
	{
		if( *it == row )
		{
			rows.erase( it );
			return;
		}
	}
}
void RowCollection::RemoveAt(unsigned int index)
{
	if( index >= rows.size() )
		throw DException(L"Index out of range");

	unsigned int i = 0;
	for( vector<Row>::iterator it = rows.begin(); it != rows.end(); ++it, ++i )
	{
		if( index == i )
		{
			rows.erase(it);
			return;
		}
	}
}
void RowCollection::Clear()
{
	rows.clear();
}
void RowCollection::Table(DataTable* _table)
{
	table = _table;
	for(unsigned int i = 0; i < rows.size(); ++i )
		rows[i].Table(table);
}