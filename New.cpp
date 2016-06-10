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
	int*p3 = new int[10]{1, 2, 3, 4, 5, 6};  //ָ���������ݵ�ָ�����p3��һ��ֻ�ܷ���4���ֽ�
	int(*p4)[10] = (int(*)[10])p3; //p4����ָ�룬ָ����10������Ԫ�ص����飬����Ϊint(*)[10]
	free(p);
	delete p1;
	delete[] p3;//�����ͷ�һ��Ҫƥ��ʹ��
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



	/*ϵͳ�Ķ�λnew���ʽ�Լ�����ɾ���ı�ʾ*/
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
	test*p1 = new test;//�ȵ�operator new�У��ٵ����캯���У��ȴ����ռ��ٹ������
	test*p2 = new test[7];
	//int*p3 = (int*)malloc(1 <<30);//ʹ��malloc���ٿռ�Ҫ�����пմ���
	//if (NULL == p3)
	//{
	//	return;
	//}
	//long long int ret = 1 << 30;
	//test*p4 = new test[ret / 4];//ʹ��new�����ռ䲻��Ҫ���������ʧ�ܻ��׳��쳣
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


//��λnew���ʽ 
void funtest2()
{
	int*p = new int[10];
	new(p + 0) int(0);//����ϵͳ����ĺ���
	new(p + 1) int(1);
	new(p + 2) int(2);
	new(p + 3) int(3);
	new(p + 4) int(4);
	new(p, 5) int(5);//�����Լ��ĺ���
	new(p, 6)int(6);
	new(p, 7)int(7);
	new(p, 8)int(8);
	new(p, 9)int(9);
	
}

//new������=operator new+���캯��
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

//delete������=��������=operator delete
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



//new[]�������size+4��=operator new->malloc+count�ι��캯��
test* NewN(size_t count)
{
	test*p = (test*)malloc(sizeof(test)*count + 4);//ָ�����pָ���¿��ٿռ���׵�ַ�����4
	*(int*)p=count;//pǿתΪint*���ٽ�����,����count��ֵ��ֵ����ʱpָ��ռ��׵�ַ�ڴ����Ҫ�������ʹ�С������
	test* ret =(test*) ((int)p + 4);//***�������������Ч��ַ����
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
	int count = *(int*)((int)p - 4);//�ͷ���Ҫȫ���ͷ�
	for (int idex = count - 1; idex >=0; idex--)//��NewN��˳���෴
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




//�Ҵ���
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

//1.thisָ�� Ϊջ�ϵ��ڴ棬delete�ͷŵ��Ƕ��ϵ��ڴ�  
//2.delete�������ȵ������������ٵ���operator delete�����޵ݹ�

