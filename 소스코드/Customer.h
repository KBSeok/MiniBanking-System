#ifndef _Customer_H__
#define _Customer_H__
#include "string.h"


class Customer {
private:
	String name; //∞Ì∞¥ ¿Ã∏ß
public:
	Customer(const char * myname);
	void ShowCustomerInfo()const;
	String Getname() {
		return name;
	}
	virtual void ShowInfo() const = 0;
	virtual int GetID() = 0;
	virtual void inmoney(int money) = 0;
	virtual void outmoney(int money) = 0;
	virtual int Getbalance() = 0;
	virtual double GetRatio() = 0;
	virtual int GetScore()const = 0;
};
#endif