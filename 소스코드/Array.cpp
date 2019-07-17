#include "MiniBankingCommonDecl.h"
#include "Arrary.h"
#include "Exception.h"

template <typename T>
Array<T>::Array(int len) : arrlen(len) {
	arr = new Customer_Ptr[len];
}

template <typename T>
T& Array<T>::operator[] (int idx) {
	if (idx < 0 || idx >= arrlen) {
		MaxReg expn(idx);
		throw expn;
	}

	return arr[idx];
}

template <typename T>
T Array<T>:: operator[] (int idx) const {
	if (idx < 0 || idx >= arrlen) {
		MaxReg expn(idx);
		throw expn;
	}

	return arr[idx];
}

template <typename T>
int Array<T>::GetArrLen() const {
	return arrlen;
}

template <typename T>
Array<T>::~Array() {
	delete[]arr;
}