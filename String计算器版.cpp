#define  _CRT_SECURE_NO_WARNINGS
#include"String.h"


String::String(char* pdata)
 :_pcount(new int(1))
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



String::String(const String&s)
 :_pdata(s._pdata)
 , _pcount(s._pcount)
{
	++(*_pcount);
}



String::~String()
{
	cout << "~String()" <<this<< endl;
	assert(_pcount != NULL&&_pdata != NULL);
	--(*_pcount);
	if (0==(*_pcount))
	{
		delete[] _pdata;
		_pdata = NULL;
		delete _pcount;
		_pcount = NULL;
	}
}




String& String::operator=(const String& s)
{
	if (this != &s)
	{
		--(*_pcount);
		if (0 == (*_pcount))
		{
			delete[] _pdata;
			delete _pcount;
		}
		_pcount = s._pcount;
		_pdata = s._pdata;
		++(*_pcount);
	}
	return *this;
}





void funtest()
{
	String s1;
	String s2(s1);
	String s3(s1);
	String s4;
	String s5(s4);
	s4 = s3;
	s5 = s2;
}



void funtest1()
{
	String s1;
	String s2;
	String s3(s2);
	s1 = s2;
}


int main()
{
	/*funtest();*/
	funtest1();
	return 0;
}