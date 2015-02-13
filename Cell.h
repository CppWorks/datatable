

#ifndef CELL_H
#define CELL_H

#include "stdafx.h"
#include "IObserver.h"
class Row;


class DT_INTERFACE Cell
{
protected:
	wstring _v;
	unsigned short order;
	IObserver* row;

	friend class Row;
public:
	void operator=(const int value);
	void operator=(const float value);
	void operator=(const string& value);
	void operator=(const wstring& value);

	bool operator==(const Cell& rhs);
	bool operator!=(const Cell& rhs);

	void Assign(const wstring& value);

	size_t size();
	const wchar_t* c_str();
	wstring ToString();

	Cell();
	~Cell();
};

#endif //CELL_H