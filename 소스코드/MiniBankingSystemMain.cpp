#include "MiniBankingCommonDecl.h"
#include "Handler.h"

//메뉴선택
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
		cout << " >> 선택 : ";

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
			cout << "없는메뉴입니다" << endl;
			break;
		}
	}
	
	return 0;
}