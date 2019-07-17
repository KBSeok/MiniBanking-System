#ifndef _HighCreditAccount_H__
#define _HighCreditAccount_H__

#include "NormalAccount.h"

//�ſ�ŷڰ��� Entity Ŭ����
class HighCreditAccount : public NormalAccount {
private:
	char grade; //�ſ�������
public:
	HighCreditAccount(const char *myname, const int ID, int money, const double rat,
		char score);
	void ShowInfo() const;
	int GetScore()const;
};
#endif