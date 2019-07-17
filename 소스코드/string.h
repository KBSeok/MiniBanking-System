#ifndef _String_H__
#define _String_H__
#include "MiniBankingCommonDecl.h"

class String {
private:
	int strLen; //���ڿ� ���� ��� ����
	char * str; //���ڿ� �迭 �ּ�
public:
	//�⺻ ������
	String();

	//�Ű������� �ִ� ������
	String(const char * str);

	//���� ������
	String(const String &copy);

	//�Ҹ���
	~String();

	// = ������ �����ε�
	String &operator=(const String &pos);

	// >> ������ �����ε�
	friend ostream& operator<<(ostream& os, const String &pos);

	// << ������ �����ε�
	friend istream& operator>>(istream& is, String &pos);
};
#endif // !_String_H__

