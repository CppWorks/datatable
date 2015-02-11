


#ifndef COLUMN_COLLECTION_H
#define COLUMN_COLLECTION_H

#include "stdafx.h"
#include "Column.h"

class DataTable;

class DT_INTERFACE ColumnCollection
{
private:
	int coldisn;
protected:
	DataTable* table;
	vector<Column> cols;
	
	void Table(DataTable* _table);
	friend class DataTable;
public:
	void Add( Column column );
	void Add( const wstring& columnName, int dataType = 0);

	Column& operator[](unsigned int index);
	Column& operator[](const wstring& name);

	void Clear();

	unsigned int Count();

	ColumnCollection();
};

#endif//COLUMN_COLLECTION_H