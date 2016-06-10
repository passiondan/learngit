#include<iostream>
#include<assert.h>
using namespace std;

class String
{
public:
	String(char* pdata="");
	String(const String& s);
	~String();
	String& operator=(const String&s);
private:

	int& GetRef();
	
	void ReleaseRef();


private:
	char* _pdata;
	    
	int* _pcount;//需要共同维护的对象个数
	
};  