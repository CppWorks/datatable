


#ifndef ROWCOLLECTION_H
#define ROWCOLLECTION_H

#include "stdafx.h"
#include "Row.h"

class DataTable;

class DT_INTERFACE RowCollection
{
protected:
	DataTable* table;
	vector<Row> rows;

	RowCollection(){};
	
	void Table(DataTable* _table);

	friend class DataTable;
public:
	void Add(Row row);
	void Remove(Row row);
	void RemoveAt(unsigned int index);
	void Clear();

	unsigned int Count();
	

	Row& operator[](unsigned int index);

	~RowCollection();
};

#endif//ROWCOLLECTION
