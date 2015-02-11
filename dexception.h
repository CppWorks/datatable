
#ifndef DEXCEPTION_H
#define DEXCEPTION_H

#include "stdafx.h"

class DException : public std::exception
{
protected:
	string _m_what;
	wstring _wm_what;
public:
	DException() throw(){};
	DException(const char* message) throw()
	{
		_m_what = message;
	}
	DException(wstring message)
	{
		_wm_what = message;
	}
	const char* what() throw()
	{
	    return _m_what.c_str();
	}
	const wchar_t* wwhat() throw()
	{
		return _wm_what.c_str();
	}
	~DException()throw(){}
};

#endif//DEXCEPTION_H