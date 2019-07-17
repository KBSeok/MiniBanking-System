#include "MiniBankingCommonDecl.h"
#include "string.h"

//기본 생성자
String::String() :str(NULL), strLen(0) {}

//매개변수가 있는 생성자
String::String(const char * str) {
	strLen = strlen(str) + 1;
	this->str = new char[strLen];
	strcpy(this->str, str);
}

//복사 생성자
String::String(const String &copy) {
	strLen = strlen(copy.str);
	str = new char[strLen+1];
	strcpy(str, copy.str);
}

//소멸자
String::~String() {
	delete[] str;
}

String&String::operator=(const String &pos) {
	delete[]str;
	str = new char[strlen(pos.str) + 1];
	strcpy(str, pos.str);
	String(str);
	return *this;
}

ostream& operator<<(ostream& os, const String &pos)
{
	os << pos.str;
	return os;
}

istream& operator>>(istream& is, String &pos) {
	char str[100];
	is >> str;
	pos = String(str);
	return is;
}