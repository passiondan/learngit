#include"Date.h"


Date::Date(int year, int month, int day)
:_year(year)
, _month(month)
, _day(day)
{
	if (_year < 1990)
		_year = 1990;
	if (_month<0 || _month>12)
		_month = 1;
	if (_day < 0 || (!GetMonthDay(month)))
	{
		_day = 1;
	}
	/*if (!((_year >= 1990) && (_month >= 1 && _month <= 12) && ((day >= 0) && GetMonthDay(month))))
	{
		_year = 1990;
		_month = 1;
		_day = 1;
	}*/
}

Date::Date(const Date&d)
{
	_year = d._year;
	_month = d._month;
	_day = d._day;
}

Date::~Date()
{
	cout << "~Date()" << this << endl;
}

bool Date::IsLeap()
{
	if ((_year%4==0&&_year%100!=0)||(_year%400==0))
	{
		return true;
	}
	return false;
}

int Date:: GetMonthDay(int month)
{
	int Days[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (month == 2 && IsLeap())
	{
		Days[month]++;
	}
	return Days[month];
}

Date& Date::operator=(const Date& d)
{
	if (this != &d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	return *this;
}

Date& Date::operator++()
{
	_day++;
	if (_day > GetMonthDay(_month))
	{
		_day = 1;
		_month++;
	}
	if (_month > 12)
	{
		_month = 1;
		_year++;
	}
	return *this;
}

Date& Date:: operator--()
{
	_day--;
	if (_day == 0)
	{
		_month--;
		_day = GetMonthDay(_month);
	}
	if (_month == 0)
	{
		_year--;
		_month += 12;
	}
	return *this;
}

Date Date::operator++(int)
{
	Date temp(*this);//***
	_day++;
	return temp;
}

Date Date::operator--(int)
{
	Date temp(*this);
	_day--;
	return temp;
}

Date Date::operator+(int days)//返回值为值 类对象d的值发生改变，需要返回d（局部变量）
{	
	while (days--)
	{
		++_day;//***直接将类对象的值发生改变
	}
	return *this;//this指针指向空间的内容也发生改变
}

Date Date::operator-(int days)
{
	while (days--)
	{
		--_day;
	}
	return *this;
}

Date& Date::operator +=(int days)//返回引用，因为此时左操作数已发生改变
{
	while (days--)
	{
		++_day;
	}
	return *this;
}

Date& Date::operator-=(int days)
{
	while (days--)
	{
		--_day;
	}
	return *this;
}
/*
默认第一个为隐式的this指针，其类型为 Date* const this，
第二个参数为const Date& d，参数1、参数2的类型不一致
（需要给参数列表后面加上const相当于this指针的类型变为const Date* const this）
*/
bool Date::operator>(const Date& d)const    
{
	if (_year > d._year)
	{
		return true;
	}
	else if (_year <= d._year)
	{
		return false;
	}
	else
	{
		if (_month > d._month)
		{
			return true;
		}
		else if (_month <= d._month)
		{
			return false;
		}
		else
		{
			if (_day > d._day)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
}

bool Date::operator<(const Date& d)const
{
	if (*this>d || *this== d)
	{
		return false;
	}
	return true;
}

bool Date::operator==(const Date& d)const
{
	if (_day == d._day&&_month == d._month&&_year == d._year)
	{
		return true;
	}
	return false;
}

bool Date::operator!=(const Date& d)const
{
	if (_day != d._day &&_month != d._month && _year != d._year)
	{
		return true;
	}
	return false;
}

int operator-(const Date&d1,const Date&d2)
{
	int SumDay = 0;
	int flag = 1;
	Date small, big;
	if ( d1> d2)
	{
		small = d2;
		big = d1;
	}
	else if (d1 < d2)
	{
		small = d1;
		big = d2;
		flag = -1;
	}
	else
	{
		return 0;
	}
	while (small < big)
	{
		SumDay++;
		++small;
	}
	return flag*SumDay;
}


ostream& operator<<(ostream&os, const Date& d)
{
	os << d._year << "/" << d._month << "/" << d._day << endl;
	return os;
}

istream& operator>>(istream& is, Date& d)
{
	is >> d._year >> d._month >>  d._day ;
	return is;
}

Date& FunTest()
{
	Date d11;
	Date &d12(d11 += 3);
	return  d12;
}


int main()
{
	Date d;

	Date ret1=++d;
	cout << ret1<< endl;
	cout << d<< endl;

	Date ret3 = --d;
	cout << ret3 << endl;
	cout << d << endl;
	
	Date ret2 = d++;
	cout << ret2<< endl;
	cout << d << endl;

	Date ret4 = d--;
	cout << ret4 << endl;
	cout << d << endl;

	Date d5;
	Date d6 = d5 + 7;

	cout << d5 << endl;
	cout << d6 << endl;
	
	Date d7;
	Date d8 = d7 - 100;

	cout << d7 << endl;
	cout << d8 << endl;
	
	Date d8(2016, 6, 2);
	Date d9(2015, 12, 28);
	int ret = d8 - d9;
	cout << ret << endl;

	Date d10(2000, 2, 1);
	cout << (d10 > d9) << endl;

	Date d11(2016, 1, 1);
	d11 += 5;
	cout << d11 << endl;

	getchar();
	return 0;
}
