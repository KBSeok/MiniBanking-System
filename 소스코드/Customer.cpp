#include "MiniBankingCommonDecl.h"
#include "Customer.h"

Customer::Customer(const char * myname) {
	name = String(myname);
}

void Customer::ShowCustomerInfo()const {
	cout << "ÀÌ¸§ : " << name << endl;
}

