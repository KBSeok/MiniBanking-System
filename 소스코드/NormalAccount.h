#ifndef _NormalAccount_H__
#define _NormalAccount_H__

#include "Customer.h"

//보통예금계좌 Entity 클래스
class NormalAccount : public Customer {
private:
	int accID; //계좌번호
	int balance; //잔액
	double ratio; //이율정보
public:
	NormalAccount(const char * myname, const int ID, int money,
		const double rat);
	void ShowInfo() const;
	void ShowNormaInfo() const;
	int GetID();
	double GetRatio();

	//잔액 가져오기
	int Getbalance();
	//입금액 더하기
	void inmoney(int money);
	//출금하기
	void outmoney(int money);
};
#endif