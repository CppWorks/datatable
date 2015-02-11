

#include "stdafx.h"
#include "Row.h"
#include <boost/algorithm/string.hpp>

using namespace boost;


Row::Row()
{
	owned = false;
	state = RS_UNCHANGED;
	table = 0;
	loc = locale::classic();
}
Row::Row(ColumnCollection columns)
{
	owned = false;
	cols = columns;
	state = RS_UNCHANGED;
	table = 0;
	loc = locale::classic();

	for(unsigned int i = 0; i < cols.Count(); i++)
	{
		Cell c;
		c.order = (unsigned short)i;
		c.row = this;
		c.Assign( cols[i].DefaultValue );
		values.push_back(c);
	}
}
Row::Row(const Row& u)
{
	this->cols = u.cols;
	this->loc = u.loc;
	this->order = u.order;
	this->owned = u.owned;
	this->state = u.state;
	this->table = u.table;
	this->values = u.values;

	for( unsigned int i = 0; i < values.size(); ++i )
		values[i].row = this;
}
Row::~Row()
{
}
bool Row::operator==(Row& rhs)
{
	if( cols.Count() != rhs.cols.Count() )
		return false;

	for( unsigned int i = 0; i < cols.Count(); ++i)
	{
		if( cols[i] != rhs.cols[i] )
			return false;
		for( unsigned int x = 0; x < values.size(); ++x )
			if( values[x] != rhs.values[x] )
				return false;
	}
	return true;

}
Cell& Row::operator[](unsigned int index)
{
	if( index > cols.Count() )
		throw DException(L"Index out of range");

	return values[index];
}
Cell& Row::operator[](const wstring& name)
{
	for( unsigned int i = 0; i < cols.Count(); ++i)
	{
		wstring en = cols[i].ColumnName;//Existing Name;
		wstring sc = name;//search criteria
		
		to_upper(en, loc);
		to_upper(sc, loc);

		if( en == sc )
			return values[i];
	}

	throw DException( L"There is no such column; " );
	//throw DException( (L"There is no such column; ") + name) );
}
int Row::State()
{
	return state;
}

void Row::InformUpdate(unsigned int row_order, unsigned short cell_order)
{
	if( (state | RS_ADDED) != RS_ADDED )
		state |= RS_MODIFIED;
}
void Row::AcceptChanges()
{
	state = RS_UNCHANGED;
}
void Row::Delete()
{
	state = RS_DELETED;
}
DataTable* Row::Table()
{
	return table;
}
void Row::Table(DataTable* _table)
{
	table = _table;
	for( unsigned int i = 0; i < cols.Count(); ++i)
		cols[i].Table = table;
}
wstring Row::serialize()
{
	wstring data = L"\t\t\t<ROW>\n";
	
	for( unsigned int i = 0; i < cols.Count(); ++i)
	{
		data += L"\t\t\t\t<";
		data += cols[i].SqlName;
		data += L">";

		data += values[i].ToString();		

		data += L"</";
		data += cols[i].SqlName;
		data += L">\n";
	}
	
	data += L"\t\t\t</ROW>\n";
	return data;
}
void Row::deserialize(const wstring& _xmldata)
{

}