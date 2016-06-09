#define  _CRT_SECURE_NO_WARNINGS
#include"Arrary.h"


//一般来说，操作符只能用于内置类型操作数，要想实现组合类型的操作数，则需要重载操作符


Arrary::Arrary()
:_capacity(3)
, _size(0)
{
	_pData = (DataType*)malloc(3 * sizeof(DataType));
	assert(NULL != _pData);
}


void Arrary::PushBack(const DataType &d)
{
	//需要判断数组是否已经满
	if (check_capacity())
	{
		_pData[_size++] = d;
	}
	return;
}


//为了便于PushBack调用check_capacity函数 采用带返回值的函数
bool Arrary:: check_capacity()
{
	if (_size >= _capacity)
	{
		DataType* Temp = NULL;
		Temp = (DataType*)malloc(2 * _capacity*sizeof(DataType));
		//判断是否开辟成功
		if (NULL == Temp)
		{
			return false;
		}
		//开辟成功 把源指针指向数组内容赋值给新开辟的空间（采用memcpy） 注意拷贝的字节数
		memcpy(Temp, _pData, _capacity*sizeof(DataType));
		_capacity *= 2;
		_pData = Temp;
	}

	return true;
}



/*如果返回值是值的形式，可以作为右值，不可作为左值
如果作为左值，则需要返回引用
返回值为值：会创建临时变量，增大系统的开销
返回值为引用：不会创建临时变量*/

DataType& Arrary:: operator[](int index) //传入索引
{
	if (index > (int)_size)
	{
		assert(false);
	}
	return _pData[index];//返回索引对应的值
}


//在类内重载输出操作符，因为调用不符合常规，所以不建议
void Arrary::operator<<(ostream &_cout)
{
	_cout << _size;
}


//在类内重载输入操作符，因为调用不符合常规，所以不建议
void Arrary:: operator>>(istream &_cin)
{
	_cin >> _size;
}




//在类外重载输出操作符，想使用类中的私有成员，则将函数声明为类的友元函数

/*
ostream& _cout输出流对象参数，如果传的是值，则要使用对象创建对象，调用输出流对象的拷贝构造函数，
而输出流对象的拷贝构造函数是私有的,无法调用；传引用，则不会用对象创建对象，不会调用其拷贝构造函数，而且传引用避免创建临时变量，减小系统开销）
const Arrary &a，创建类对象，将要输出的值，顺着箭头到cout，再通过cout输出
*/

/*因为要实现连着输出，所以函数需要有返回值，且为引用
如果为值cout<<a<<a<<endl则将最左边的a通过输出操作符给cout，相当于cout.operator<<(a)返回值为一个值，为常量，
继续想输出下一个a，则成为将a给一个常量，此时左值为常量出错
*/

ostream& operator<<(ostream& _cout, const Arrary &a)
{
	_cout << a._size;//类外函数不能访问类的私有成员，声明为类的友元函数
	return _cout;
}


istream& operator>>(istream& _cin, Arrary &b)//  用类创建的对象前不能有const，因为要将输入的东西给对象的某个成员，所以会随时改变
{
	_cin >> b._size;
	return _cin;
}




int main()
{
	//Arrary a;
	//a.PushBack(1);
	//a.PushBack(2);
	//a.PushBack(3);
	//int arr[10];
	//arr[0] = 1;//作左值
	//int b = 3;
	//b = arr[0];//作右值
	////实现下标操作符的重载 用对象可以直接使用下标操作符  作为左值和右值
	//a[0] = 6;
	//b = a[1];


	//实现输出运算符重载cout<<
	int b = 10;
	int *pb = &b;

	Arrary a;
	/*a << cout; */ //这种写法也是正确的，只是不符合常规，不建议这种书写
	/*a >> cin;*/   //同上

	/*Arrary *pa = &a;*/
	cout << b << endl;
	/*cout << a ;*/  //针对输出操作符无返回值的测试
	cout << a << " " << a << endl;

	cin >> a;


	return 0;
}