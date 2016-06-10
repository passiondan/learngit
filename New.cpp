#define  _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<malloc.h>
using namespace std;

void funtest(void)
{
	int*p = (int*)malloc(sizeof(int));
	if (NULL == p)
	{
		return;
	}
	int*p1 = new int(1);
	int*p3 = new int[10]{1, 2, 3, 4, 5, 6};  //指向整型数据的指针变量p3，一次只能访问4个字节
	int(*p4)[10] = (int(*)[10])p3; //p4数组指针，指向有10个整型元素的数组，类型为int(*)[10]
	free(p);
	delete p1;
	delete[] p3;//创建释放一定要匹配使用
}





class test
{
public:
	test()
	{
		cout << "test():"<<this << endl;
	}


	~test()
	{
		cout << "~test():" << this << endl;
	}


	void* operator new(size_t size)
	{
		return malloc(size);
	}


	void* operator new[](size_t count)
 	{
		return operator new(count);
	}



	/*系统的定位new表达式以及搭配删除的表示*/
	void* operator new(size_t size,void* where)
	{
		return where;
	}

	void operator delete(void*p, void* t)
	{

	}


	void operator delete(void* p)
	{
		if (NULL == p)
		{
			return;
		}
	free(p);
	}


	void operator delete[](void* p)
	{
		if (NULL == p)
		{
			return;
		}
		operator delete(p);
	}

private:
	int data;

};





void funtest1()
{
	test* p = (test*)malloc(sizeof(test));
	if (NULL == p)
	{
		return;
	}
	test*p1 = new test;//先到operator new中，再到构造函数中（先创建空间再构造对象）
	test*p2 = new test[7];
	//int*p3 = (int*)malloc(1 <<30);//使用malloc开辟空间要进行判空处理
	//if (NULL == p3)
	//{
	//	return;
	//}
	//long long int ret = 1 << 30;
	//test*p4 = new test[ret / 4];//使用new创建空间不需要，如果开辟失败会抛出异常
	free (p);
	delete p1;
	delete[] p2;
	//free(p3);
	//delete[] p4;
}

void* operator new(size_t size,int* p,size_t pos)
{
	return p + pos;
}


//定位new表达式 
void funtest2()
{
	int*p = new int[10];
	new(p + 0) int(0);//调用系统自身的函数
	new(p + 1) int(1);
	new(p + 2) int(2);
	new(p + 3) int(3);
	new(p + 4) int(4);
	new(p, 5) int(5);//调用自己的函数
	new(p, 6)int(6);
	new(p, 7)int(7);
	new(p, 8)int(8);
	new(p, 9)int(9);
	
}

//new操作符=operator new+构造函数
test* New()
{
	test*p = (test*)malloc(sizeof(test));
	if (NULL == p)
	{
		return NULL;
	}
	new(p)test;
	return p;
}

//delete操作符=析构函数=operator delete
void Delete(test* p)
{
	if (NULL != p)
	{
	 p->~test();
	 free(p);
	 p = NULL;
	}
}


void funtest3()
{
	test*p = New();
	Delete(p);
}



//new[]运算符（size+4）=operator new->malloc+count次构造函数
test* NewN(size_t count)
{
	test*p = (test*)malloc(sizeof(test)*count + 4);//指针变量p指向新开辟空间的首地址，多加4
	*(int*)p=count;//p强转为int*型再解引用,并将count的值赋值，此时p指向空间首地址内存放需要开辟类型大小的数量
	test* ret =(test*) ((int)p + 4);//***将创建对象的有效地址返回
	for (int idex = 0; idex < count; idex++)
	{
		new(ret + idex) test;
	}
	return ret;
}



void DeleteN(test* p)
{
	if (NULL == p)
	{
		return;
	}
	int count = *(int*)((int)p - 4);//释放需要全部释放
	for (int idex = count - 1; idex >=0; idex--)//与NewN的顺序相反
	{
		(p+idex)->~test();
	}
	free((int*)((int)p - 4));
	p = NULL;
}



void funtest4()
{
	test*p = NewN(10);
	DeleteN(p);
}

int main()
{
	/*funtest();*/
	/*funtest1();*/
	/*funtest2();*/
	/*funtest3();*/
	funtest4();
	return 0;
}




//找错误
class Fun
{
public:
	Fun()
	{
		cout << "Fun():" << this << endl;
	}
	~Fun()
	{
		cout << "~Fun():" << this << endl;
		delete this;   
	}
};

//1.this指针 为栈上的内存，delete释放的是堆上的内存  
//2.delete操作符先调用析构函数再调用operator delete，无限递归

