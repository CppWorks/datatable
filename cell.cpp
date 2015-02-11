

#include "stdafx.h"
#include "Cell.h"
#include <boost/lexical_cast.hpp>

using namespace boost;

Cell::Cell()
{
	row = 0;
}
Cell::~Cell()
{
}

void Cell::Assign(const wstring& value)
{
	_v = value;
}
bool Cell::operator==(const Cell& rhs)
{
	if( _v != rhs._v )
		return false;
	return true;
}
bool Cell::operator!=(const Cell& rhs)
{
	if( _v == rhs._v )
		return false;
	return true;
}
void Cell::operator=(const int value)
{ 
	operator=(lexical_cast<wstring>(value));
}
void Cell::operator=(const float value)
{
	operator=(lexical_cast<wstring>(value));
}
void Cell::operator=(const wstring& value)
{
	Assign(value);

	row->InformUpdate(0, order);
}

const wchar_t* Cell::c_str()
{
	return _v.c_str();
}
wstring Cell::ToString()
{
	return _v;
}
size_t Cell::size()
{
	return _v.size();
}

