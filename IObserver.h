



#ifndef IOBSERVER_H
#define IOBSERVER_H

class DT_INTERFACE IObserver
{
protected:
	IObserver(){};
public:
	virtual void InformUpdate(unsigned int row_order, unsigned short cell_order) = 0;
};

#endif//IOBSERVER_H