#include "MiniBankingCommonDecl.h"
#include "HighCreditAccount.h"
HighCreditAccount::HighCreditAccount(const char *myname, const int ID, int money, 
	const double rat, char score)
	: NormalAccount(myname, ID, money, rat), grade(score) {}

void HighCreditAccount::ShowInfo() const {
	ShowCustomerInfo();
	ShowNormaInfo();

	if (grade == 0) 
		cout << "�ſ��� : ������� " << endl;
	else 
		cout << "�ſ��� : " << grade << endl;
}

int HighCreditAccount::GetScore()const {
	return grade;
}