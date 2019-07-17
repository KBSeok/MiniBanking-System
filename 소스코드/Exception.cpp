#include "MiniBankingCommonDecl.h"
#include "Exception.h"

DepositException::DepositException(int money) :demoney(money) {}

void DepositException::ShowException() {
	cout << "    예외 메세지 : " << demoney << "는 입금이 불가 합니다." << endl;
}

WithdrawException::WithdrawException(int money) : Wibalance(money) {}

void WithdrawException::ShowException() {
	cout << "    예외 메세지 : " << Wibalance << "는 출금이 불가 합니다" << endl;
}

MaxReg::MaxReg(int num) :NUM(num) {}

void MaxReg::ShowException() {
	cout << "    예외 메세지 : 더 이상 저장이 불가 합니다." << endl;
}