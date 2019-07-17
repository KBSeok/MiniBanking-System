#ifndef _NormalAccount_H__
#define _NormalAccount_H__

#include "Customer.h"

//���뿹�ݰ��� Entity Ŭ����
class NormalAccount : public Customer {
private:
	int accID; //���¹�ȣ
	int balance; //�ܾ�
	double ratio; //��������
public:
	NormalAccount(const char * myname, const int ID, int money,
		const double rat);
	void ShowInfo() const;
	void ShowNormaInfo() const;
	int GetID();
	double GetRatio();

	//�ܾ� ��������
	int Getbalance();
	//�Աݾ� ���ϱ�
	void inmoney(int money);
	//����ϱ�
	void outmoney(int money);
};
#endif