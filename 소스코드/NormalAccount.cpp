#include "MiniBankingCommonDecl.h"
#include "NormalAccount.h"
#include "Exception.h"

NormalAccount::NormalAccount(const char * myname, const int ID, int money,
	const double rat)
	: Customer(myname), accID(ID), balance(money), ratio(rat) {
}

void NormalAccount::ShowInfo() const {
	ShowCustomerInfo();
	ShowNormaInfo();
}

void NormalAccount::ShowNormaInfo() const {
	cout << "°èÁÂ¹øÈ£ : " << accID << endl;
	cout << "ÀÜ¾× : " << balance << endl;
	cout << "ÀÌÀ²Á¤º¸ : " << ratio << '%' << endl;
}

int NormalAccount::GetID()  {
	return accID;
}

int NormalAccount::Getbalance() {
	return balance;
}

double NormalAccount::GetRatio() {
	return ratio;
}


void NormalAccount::inmoney(int money) {
	if (money < 0) {
		DepositException expn(money);
		throw expn;
	}
	balance += money*(1 + ratio/100);
}

void NormalAccount::outmoney(int money) {
	if (balance - money < 0) {
		WithdrawException expn(money);
		throw expn;
	}
	balance -= money;
}