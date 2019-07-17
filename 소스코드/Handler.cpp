#include "MiniBankingCommonDecl.h"
#include "Handler.h"
#include "Exception.h"
#include "HighCreditAccount.h"

Handler::Handler() :empNum(0) {}

void Handler::ShowMenu() const {
	cout << "     ----------- Menu -----------" << endl;
	cout << "    |     1. 계좌개설            |" << endl;
	cout << "    |     2. 입금                |" << endl;
	cout << "    |     3. 출금                |" << endl;
	cout << "    |     4. 전체고객 잔액조회   |" << endl;
	cout << "    |     5. 프로그램 종료       |" << endl;
	cout << "     ----------------------------" << endl;
}

void Handler::MakeAccount() {
	int choice;
	char name[20];
	int ID;
	int money;
	double rat;
	int score;
	
	cout << "  [계좌종류선택]" << endl;
	cout << "   1. 보통예금계좌   2. 신용신뢰계좌" << endl;
	
	if(RegException()) return;

	while (1) {
		cout << "   >> 선택 ; ";
		cin >> choice;

		if (!(choice == NORMAL || choice == CREDIT)) {
			cout << "   다시선택하세요." << endl;
			getchar();
			getchar();
			return;
		}
		
		cout << "    이름 입력 : ";
		cin >> name;

		if (empNum > 0) {
			while (1) {
				cout << "    계좌 입력 : ";
				cin >> ID;
				for (int i = 0; i < empNum; i++) {
					if (empList[i]->GetID() != ID) {

						money = RegisterMoneyException();

						cout << "    이율 입력 : ";
						cin >> rat;
						
						if (choice == CREDIT) {
							while (1) {
								cout << "    등급 입력 : ";
								cin >> score;
								if (score == LEVEL_A) {
									rat += 7;
									score = 'A';
									break;
								}
								else if (score == LEVEL_B) {
									rat += 4;
									score = 'B';
									break;
								}
								else if (score == LEVEL_C) {
									rat += 2;
									score = 'C';
									break;
								}
								else
									cout << "    신용등급을 다시 입력하세요" << endl;
							}
						}
						score = 0;

						empList[empNum] = new HighCreditAccount(name, ID, money, rat, score);
						RegiterAccount();
						empNum++;

						cout << "    계좌개설이 완료되었습니다." << endl;
						getchar();
						getchar();
						return;
					}
					else {
						cout << "    등록된 계좌입니다" << endl;
						break;
					}
				}
			}
		}

		else {
			cout << "    계좌 입력 : ";
			cin >> ID;
			
			while (1) {
				money = RegisterMoneyException();
				cout << "    이율 입력 : ";
				cin >> rat;

				if (choice == CREDIT)
					while (1) {
						cout << "    등급 입력 : ";
						cin >> score;
						if (score == LEVEL_A) {
							rat += 7;
							score = 'A';
							break;
						}
						else if (score == LEVEL_B) {
							rat += 4;
							score = 'B';
							break;
						}
						else if (score == LEVEL_C) {
							rat += 2;
							score = 'C';
							break;
						}
						else
							cout << "    신용등급을 다시 입력하세요" << endl;
					}
				score = 0;
				empList[empNum] = new HighCreditAccount(name, ID, money, rat, score);
				RegiterAccount();
				empNum++;

				cout << "    계좌개설이 완료되었습니다." << endl;
				getchar();
				getchar();
				return;
			}			
		}
	}
}

void Handler::DepositMoney() {
	int ID;
	int money;

	while (1) {
		cout << "    계좌 입력 : ";
		cin >> ID;

		for (int i = 0; i < empNum; i++) {

			if (empList[i]->GetID() == ID) {
				while (1) {
					try {
						cout << "    입금 금액 : ";
						cin >> money;
						if (money < 0) {
							DepositException expn(money);
							throw expn;
						}
						
						empList[i]->inmoney(money);

						AgainRegister();

						cout << "    입금이 완료 되었습니다." << endl;
						getchar();
						getchar();
						return;
					}
					catch (AccountException &expn) {
						expn.ShowException();
						break;
					}
				}
			}	
		}
		cout << "    잘못된 계좌입니다." << endl;
		getchar();
		getchar();
		return;
	}
}

void Handler::WithdrawMoney() {
	int ID;
	int money;

	while (1) {
		cout << "    계좌 입력 : ";
		cin >> ID;
		
		for (int i = 0; i < empNum; i++) {
			if (empList[i]->GetID() == ID) {
				while (1) {
					try {
						cout << "출금 금액 : ";
						cin >> money;
						if (money < 0) {
							WithdrawException expn(money);
							throw expn;
						}
						empList[i]->outmoney(money);

						AgainRegister();
					
						cout << "출금이 완료되었습니다." << endl;
						getchar();
						getchar();
						return ;
					}
					catch (AccountException &expn) {
						expn.ShowException();
						break;
					}

				}
			}
		}
		cout << "    잘못된 계좌입니다." << endl;
		getchar();
		getchar();
		return;
	}
}

void Handler::ShowAllAccInfo() const {
	for (int i = 0; i < empNum; i++) {
		empList[i]->ShowInfo();
		cout << "----------------" << endl;
	}
	getchar();
	getchar();
}

Handler::~Handler() {
	for (int i = 0; i < empNum; i++) {
		delete empList[i];
	}
}

void Handler::Load() {
	char name[10];
	int accID; //계좌번호
	int balance; //잔액
	double ratio; //이율정보 
	int score = 0;
	
	ifstream fin;
	fin.open("input.txt");

	
	if (!fin.is_open())return;
	
	while (!fin.eof()) {
		
		fin >> name
			 >> accID
			>> balance
			>> ratio
			>> score;
		empList[empNum++] = new HighCreditAccount
		(name, accID, balance, ratio, score);
	}
}

bool Handler::RegException() {
	try {
		if (empNum > 2) {
			MaxReg expn(empNum);
			throw expn;
		}
	}
	catch (MaxReg &expn) {
		expn.ShowException();
		getchar();
		getchar();
		return true;
	}
	return false;
}

void Handler::RegiterAccount() {
	ofstream fout;
	fout.open("input.txt", ios::app);

	if (empNum > 0)fout << endl;
	fout << empList[empNum]->Getname() << endl;
	fout << empList[empNum]->GetID() << endl;
	fout << empList[empNum]->Getbalance() << endl;
	fout << empList[empNum]->GetRatio() << endl;
	fout << empList[empNum]->GetScore();
	fout.close();
}

int Handler::RegisterMoneyException(){
	int money;

	while (1) {
		try {
			cout << "    금액 입력 : ";
			cin >> money;
			if (money < 0) {
				DepositException expn(money);
				throw expn;
			}
			break;
		}
		catch (AccountException &expn) {
			expn.ShowException();
			getchar();
			
		}
	}
	return money;
}

void Handler::AgainRegister() {
	ofstream fout;
	fout.open("input.txt", ios::ate);

	for (int i = 0; i < empNum; i++) {
		if (empNum > 0)fout << endl;
		fout << empList[i]->Getname() << endl;
		fout << empList[i]->GetID() << endl;
		fout << empList[i]->Getbalance() << endl;
		fout << empList[i]->GetRatio() << endl;
		fout << empList[i]->GetScore();
	}
	fout.close();
}
