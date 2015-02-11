



#ifndef ROW_H
#define ROW_H

#include "stdafx.h"
#include "Cell.h"
#include "ColumnCollection.h"
#include "IObserver.h"

class DataTable;

//RS RowState
#define RS_ADDED		1
#define RS_DELETED		2
#define RS_DETACHED		4
#define RS_MODIFIED		8
#define RS_UNCHANGED	16


class DT_INTERFACE Row : public IObserver
{
protected:
	locale loc;
	ColumnCollection cols;
	vector<Cell> values;
	
	int state;
	bool owned;
	unsigned int order;
	DataTable* table;

	Row();
	Row(ColumnCollection columns);
	void InformUpdate(unsigned int row_order, unsigned short cell_order);

	friend class RowCollection;
	friend class DataTable;
public:
	DataTable* Table();
	void Table(DataTable* _table);
	
	Cell& operator[](unsigned int index);
	Cell& operator[](const wstring& name);
	bool operator==(Row& rhs);

	Row(const Row& u);
	void AcceptChanges();
	void Delete();

	int State();

	wstring serialize();
	void deserialize(const wstring& _xmldata);
	
	~Row();
};

#endif//ROW_H