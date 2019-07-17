#ifndef _HighCreditAccount_H__
#define _HighCreditAccount_H__

#include "NormalAccount.h"

//신용신뢰계좌 Entity 클래스
class HighCreditAccount : public NormalAccount {
private:
	char grade; //신용등급정보
public:
	HighCreditAccount(const char *myname, const int ID, int money, const double rat,
		char score);
	void ShowInfo() const;
	int GetScore()const;
};
#endif