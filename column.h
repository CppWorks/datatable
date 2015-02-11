

#ifndef COLUMN_H
#define COLUMN_H

#include "stdafx.h"

class DataTable;

class DT_INTERFACE Column
{
protected:
	bool PrimaryKey;

	friend class DataTable;
public:
	bool AllowDBNull;
	bool AutoIncrement;
	bool Unique;

	wstring SqlName;
	wstring Caption;
	wstring ColumnName;
	wstring DefaultValue;
	
	unsigned int MaxLength;
	int DataType;//INT, CHAR, ETC...
	//bool operator ==(const Column& u);

	DataTable* Table;

	bool operator==(Column& rhs);
	bool operator!=(Column& rhs);


	wstring serialize();
	void deserialize(const wstring& _xmldata);

	Column();
	virtual ~Column();
};

#endif//COLUMN_H