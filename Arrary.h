#include<iostream>
#include<assert.h>
using namespace std;
typedef int DataType;
typedef unsigned int size_t;


class Arrary
{
	friend ostream& operator<<(ostream& _cout, const Arrary &a);
	friend istream& operator>>(istream& _cin, Arrary &b);

public:
	Arrary();
	bool check_capacity();
	void PushBack(const DataType &d);
	DataType& operator[](int index); //´«ÈëË÷Òý
	void operator<<(ostream &_cout);
	void operator>>(istream &_cin);

private:
	DataType* _pData;
	size_t _size;
	size_t _capacity;

};