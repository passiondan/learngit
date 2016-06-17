#define  _CRT_SECURE_NO_WARNINGS
#include"String.h"
/*类中对象需要管理一段资源（内存），则必须将拷贝构造函数和赋值运算符重载写出来*/

String::String(char* pdata)
{
	if (NULL == pdata)
	{
		_pdata = new char[1];
		*_pdata = '\0';
	}
	else
	{
		_pdata = new char[strlen(pdata) + 1];
	        strcpy(_pdata, pdata);
		
	}
}


String::String(const String& s)
{
	_pdata = new char[strlen(s._pdata) + 1];
	strcpy(_pdata, s._pdata);
}


String::~String()
{
	if (NULL != _pdata)
	{
		delete[] _pdata;
		_pdata = NULL;
	}
}


String& String::operator=(const String& s)
{
	if (this != &s)
	{
		char* temp = new char[strlen(s._pdata) + 1];
		strcpy(temp, s._pdata);
		delete[] _pdata;
		_pdata = temp;
	}
	return *this;
}

void funtest()
{
	String s1("nini");
	String s2;
	String s3(s1);
	String s4;
	s4 = s3;
}

int main()
{
	funtest();
	return 0;
}
