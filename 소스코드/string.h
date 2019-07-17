#ifndef _String_H__
#define _String_H__
#include "MiniBankingCommonDecl.h"

class String {
private:
	int strLen; //문자열 길이 멤버 변수
	char * str; //문자열 배열 주소
public:
	//기본 생성자
	String();

	//매개변수가 있는 생성자
	String(const char * str);

	//복사 생성자
	String(const String &copy);

	//소멸자
	~String();

	// = 연산자 오버로딩
	String &operator=(const String &pos);

	// >> 연산자 오버로딩
	friend ostream& operator<<(ostream& os, const String &pos);

	// << 연산자 오버로딩
	friend istream& operator>>(istream& is, String &pos);
};
#endif // !_String_H__

