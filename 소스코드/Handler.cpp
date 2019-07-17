#include "MiniBankingCommonDecl.h"
#include "Handler.h"
#include "Exception.h"
#include "HighCreditAccount.h"

Handler::Handler() :empNum(0) {}

void Handler::ShowMenu() const {
	cout << "     ----------- Menu -----------" << endl;
	cout << "    |     1. ���°���            |" << endl;
	cout << "    |     2. �Ա�                |" << endl;
	cout << "    |     3. ���                |" << endl;
	cout << "    |     4. ��ü�� �ܾ���ȸ   |" << endl;
	cout << "    |     5. ���α׷� ����       |" << endl;
	cout << "     ----------------------------" << endl;
}

void Handler::MakeAccount() {
	int choice;
	char name[20];
	int ID;
	int money;
	double rat;
	int score;
	
	cout << "  [������������]" << endl;
	cout << "   1. ���뿹�ݰ���   2. �ſ�ŷڰ���" << endl;
	
	if(RegException()) return;

	while (1) {
		cout << "   >> ���� ; ";
		cin >> choice;

		if (!(choice == NORMAL || choice == CREDIT)) {
			cout << "   �ٽü����ϼ���." << endl;
			getchar();
			getchar();
			return;
		}
		
		cout << "    �̸� �Է� : ";
		cin >> name;

		if (empNum > 0) {
			while (1) {
				cout << "    ���� �Է� : ";
				cin >> ID;
				for (int i = 0; i < empNum; i++) {
					if (empList[i]->GetID() != ID) {

						money = RegisterMoneyException();

						cout << "    ���� �Է� : ";
						cin >> rat;
						
						if (choice == CREDIT) {
							while (1) {
								cout << "    ��� �Է� : ";
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
									cout << "    �ſ����� �ٽ� �Է��ϼ���" << endl;
							}
						}
						score = 0;

						empList[empNum] = new HighCreditAccount(name, ID, money, rat, score);
						RegiterAccount();
						empNum++;

						cout << "    ���°����� �Ϸ�Ǿ����ϴ�." << endl;
						getchar();
						getchar();
						return;
					}
					else {
						cout << "    ��ϵ� �����Դϴ�" << endl;
						break;
					}
				}
			}
		}

		else {
			cout << "    ���� �Է� : ";
			cin >> ID;
			
			while (1) {
				money = RegisterMoneyException();
				cout << "    ���� �Է� : ";
				cin >> rat;

				if (choice == CREDIT)
					while (1) {
						cout << "    ��� �Է� : ";
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
							cout << "    �ſ����� �ٽ� �Է��ϼ���" << endl;
					}
				score = 0;
				empList[empNum] = new HighCreditAccount(name, ID, money, rat, score);
				RegiterAccount();
				empNum++;

				cout << "    ���°����� �Ϸ�Ǿ����ϴ�." << endl;
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
		cout << "    ���� �Է� : ";
		cin >> ID;

		for (int i = 0; i < empNum; i++) {

			if (empList[i]->GetID() == ID) {
				while (1) {
					try {
						cout << "    �Ա� �ݾ� : ";
						cin >> money;
						if (money < 0) {
							DepositException expn(money);
							throw expn;
						}
						
						empList[i]->inmoney(money);

						AgainRegister();

						cout << "    �Ա��� �Ϸ� �Ǿ����ϴ�." << endl;
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
		cout << "    �߸��� �����Դϴ�." << endl;
		getchar();
		getchar();
		return;
	}
}

void Handler::WithdrawMoney() {
	int ID;
	int money;

	while (1) {
		cout << "    ���� �Է� : ";
		cin >> ID;
		
		for (int i = 0; i < empNum; i++) {
			if (empList[i]->GetID() == ID) {
				while (1) {
					try {
						cout << "��� �ݾ� : ";
						cin >> money;
						if (money < 0) {
							WithdrawException expn(money);
							throw expn;
						}
						empList[i]->outmoney(money);

						AgainRegister();
					
						cout << "����� �Ϸ�Ǿ����ϴ�." << endl;
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
		cout << "    �߸��� �����Դϴ�." << endl;
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
	int accID; //���¹�ȣ
	int balance; //�ܾ�
	double ratio; //�������� 
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
			cout << "    �ݾ� �Է� : ";
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
