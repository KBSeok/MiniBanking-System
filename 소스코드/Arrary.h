#ifndef _Arrary_H__
#define _Arrary_H__

#include "Customer.h"
typedef Customer * Customer_Ptr;

template <typename T>

class Array {
private:
	T *arr;
	int arrlen;

	Array(const Array& arr) { }
	
	Array& operator=(const Array& arr) { }

public:
	Array(int len = 3);

	T& operator[] (int idx);

	T operator[] (int idx) const;

	int GetArrLen() const;

	~Array();
};
#endif
