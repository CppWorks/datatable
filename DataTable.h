
#ifndef DATATABLE_H
#define DATATABLE_H


#include "stdafx.h"

#include "ColumnCollection.h"
#include "Row.h"
#include "RowCollection.h"
#include "IObserver.h"

class DT_INTERFACE DataTable
{
protected:
	locale loc;
public:
	wstring TableName;

	ColumnCollection Columns;
	RowCollection Rows;

	Row NewRow();

	void AcceptChanges();

	Column PrimaryKey();
	void PrimaryKey(const wstring& name);
	void PrimaryKey(const Column& col);

	locale Locale();
	void Locale(locale _locale);

	void Clear();

	wstring serialize();
	void serialize(wofstream& file);
	void serializeschema(wofstream& file);
	void deserialize(const wstring& _xmldata);

	void operator=(DataTable& rhs);
	DataTable();
	DataTable(const DataTable& u);
	virtual ~DataTable();
};

#endif //DATATABLE_H
