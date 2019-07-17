#include "MiniBankingCommonDecl.h"
#include "Exception.h"

DepositException::DepositException(int money) :demoney(money) {}

void DepositException::ShowException() {
	cout << "    ���� �޼��� : " << demoney << "�� �Ա��� �Ұ� �մϴ�." << endl;
}

WithdrawException::WithdrawException(int money) : Wibalance(money) {}

void WithdrawException::ShowException() {
	cout << "    ���� �޼��� : " << Wibalance << "�� ����� �Ұ� �մϴ�" << endl;
}

MaxReg::MaxReg(int num) :NUM(num) {}

void MaxReg::ShowException() {
	cout << "    ���� �޼��� : �� �̻� ������ �Ұ� �մϴ�." << endl;
}