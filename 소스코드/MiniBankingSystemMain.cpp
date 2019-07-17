#include "MiniBankingCommonDecl.h"
#include "Handler.h"

//�޴�����
enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

int main() {

	int choice;
	Handler Account;
	Account.Load();
	while (1) {
		system("cls");
		Account.ShowMenu();
		cout << endl;
		cout << endl;
		cout << " >> ���� : ";

		cin >> choice;

		switch (choice) {
		case MAKE:
			Account.MakeAccount();
			break;
		case DEPOSIT:
			Account.DepositMoney();
			break;
		case WITHDRAW:
			Account.WithdrawMoney();
			break;
		case INQUIRE:
			Account.ShowAllAccInfo();
			break;
		case EXIT:
			return 0;
		default:
			cout << "���¸޴��Դϴ�" << endl;
			break;
		}
	}
	
	return 0;
}