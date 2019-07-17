#ifndef _DepositException_H__
#define _DepositException_H__

#include"MiniBankingCommonDecl.h"
#include "AccountException.h"

class DepositException : public AccountException {
private:
	int demoney;
public:
	DepositException(int money);
	void ShowException();
};

class WithdrawException : public AccountException {
private:
	int Wibalance;
public:
	WithdrawException(int money);
	void ShowException();
};

class MaxReg : public AccountException {
private:
	int NUM;
public:
	MaxReg(int num);
	void ShowException();
};

#endif