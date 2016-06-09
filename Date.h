#include<iostream>
using namespace std;

class Date
{
	friend ostream& operator<<(ostream& os, const Date& d);
	friend istream& operator>>(istream& is, Date& d);
	friend int operator-(const Date&d1, const Date&d2);


	
public:
	Date(int year = 2016, int month = 6, int day = 2);
	Date(const Date& d);
	~Date();

	Date operator+(int days);
	Date operator-(int days);

	Date& operator+=(int days);
	Date& operator-=(int days);

	Date& operator++();
	Date operator++(int);
	Date& operator--();
	Date operator--(int);

	Date& operator=(const Date& d);


    bool IsLeap();
	int GetMonthDay(int month);

	bool operator>(const Date& d)const;
	bool operator<(const Date& d)const;
	bool operator==(const Date& d)const;
	bool operator!=(const Date& d)const;


private:
	int _year;
	int _month;
	int _day;
};

