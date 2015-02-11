// DataTable.cpp : Defines the initialization routines for the DLL.
//

#include "stdafx.h"
#include "DataTable.h"

#include <boost/algorithm/string.hpp>

using namespace boost;


DataTable::DataTable()
{	
	loc = locale::classic();
	Rows.table = &(*this);
	Columns.table = this;
}
DataTable::DataTable(const DataTable& u)
{
	this->Columns = u.Columns;
	this->loc = u.loc;
	this->Rows = u.Rows;
	this->TableName = u.TableName;
	Columns.Table(this);

	for( unsigned i = 0; i < Rows.Count(); ++i )
		Rows[i].Table(this);
}
void DataTable::operator=(DataTable& rhs)
{
	this->Columns = rhs.Columns;
	this->loc = rhs.loc;
	this->Rows = rhs.Rows;
	this->TableName = rhs.TableName;
	Columns.Table(this);

	for( unsigned i = 0; i < Rows.Count(); ++i )
		Rows[i].Table(this);
}
DataTable::~DataTable()
{
}

Row DataTable::NewRow()
{
	Row row(Columns);
	row.Table(this);
	return row;
}

void DataTable::AcceptChanges()
{
	for( unsigned int i = 0; i < Rows.Count(); ++i )
	{
		if( Rows[i].State() & RS_DELETED )
			Rows.RemoveAt(i);
		else
			Rows[i].AcceptChanges();
	}
}
Column DataTable::PrimaryKey()
{
	for( unsigned int i = 0; i < Columns.Count(); ++i )
		if( Columns[i].PrimaryKey )
			return Columns[i];
	return Column();
}
void DataTable::PrimaryKey(const wstring& name)
{
	for( unsigned int i = 0; i < Columns.Count(); ++i )
	{
		wstring en = Columns[i].ColumnName;
		wstring sc = name;
		
		to_upper(en, loc);
		to_upper(sc, loc);
		//en.MakeUpper();
		//sc.MakeUpper();

		if( en == sc )
			Columns[i].PrimaryKey = true;
	}
}
void DataTable::PrimaryKey(const Column& col)
{
	for( unsigned int i = 0; i < Columns.Count(); ++i )
	{
		wstring en = Columns[i].ColumnName;
		wstring sc = col.ColumnName;
		
		to_upper(en, loc);
		to_upper(sc, loc);
		//en.MakeUpper();
		//sc.MakeUpper();

		if( en == sc )
			Columns[i].PrimaryKey = true;
	}
}
locale DataTable::Locale()
{
	return loc;
}
void DataTable::Locale(locale _locale)
{
	loc = _locale;
}

void DataTable::Clear()
{
	Rows.Clear();
}
wstring DataTable::serialize()
{
	wstring data = L"\t<TABLE name=\"";
	data += TableName;
	data += L"\" >\n";

	//Serialize METADATA
	data += L"\t\t<METADATA>\n";
	for( unsigned int i = 0; i < Columns.Count(); ++i )
		data += Columns[i].serialize();
	data += L"\t\t</METADATA>\n";


	//Serialize DATA
	data += L"\t\t<DATA>\n";
	for( unsigned int i = 0; i < Rows.Count(); ++i )
		data += Rows[i].serialize();
	data += L"\t\t</DATA>\n";
	data += L"\t</TABLE>\n";
	return data;
}
void DataTable::serialize(wofstream& file)
{
	file << L"\t<TABLE name=\"";
	file << TableName;
	file << L"\" >\n";

	serializeschema(file);


	//Serialize DATA
	file << L"\t\t<DATA>\n";
	for( unsigned int i = 0; i < Rows.Count(); ++i )
		file << Rows[i].serialize();
	file << L"\t\t</DATA>\n";
	file << L"\t</TABLE>\n";
}
void DataTable::serializeschema(wofstream& file)
{
	//Serialize METADATA
	file << L"\t\t<METADATA>\n";
	for( unsigned int i = 0; i < Columns.Count(); ++i )
		file << Columns[i].serialize();
	file << L"\t\t</METADATA>\n";
}
void DataTable::deserialize(const wstring& _xmldata)
{

}