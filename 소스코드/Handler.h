#ifndef _Handler_H__
#define _Handler_H__

#include "Customer.h"
#include "Arrary.h"

//신용등급
enum { LEVEL_A = 7, LEVEL_B = 4, LEVEL_C = 2 };

//계좌 종류
enum { NORMAL = 1, CREDIT = 2 };

class Handler {
private:
	Customer_Ptr empList[3];
	int empNum;
public:
	Handler();
	void Load();
	void ShowMenu() const;
	void MakeAccount();
	void DepositMoney();
	void WithdrawMoney();
	void ShowAllAccInfo() const;
	bool RegException();
	void RegiterAccount();
	int RegisterMoneyException();
	void AgainRegister();

	~Handler();
};
#endif