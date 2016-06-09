#define  _CRT_SECURE_NO_WARNINGS
#include"Arrary.h"


//һ����˵��������ֻ�������������Ͳ�������Ҫ��ʵ��������͵Ĳ�����������Ҫ���ز�����


Arrary::Arrary()
:_capacity(3)
, _size(0)
{
	_pData = (DataType*)malloc(3 * sizeof(DataType));
	assert(NULL != _pData);
}


void Arrary::PushBack(const DataType &d)
{
	//��Ҫ�ж������Ƿ��Ѿ���
	if (check_capacity())
	{
		_pData[_size++] = d;
	}
	return;
}


//Ϊ�˱���PushBack����check_capacity���� ���ô�����ֵ�ĺ���
bool Arrary:: check_capacity()
{
	if (_size >= _capacity)
	{
		DataType* Temp = NULL;
		Temp = (DataType*)malloc(2 * _capacity*sizeof(DataType));
		//�ж��Ƿ񿪱ٳɹ�
		if (NULL == Temp)
		{
			return false;
		}
		//���ٳɹ� ��Դָ��ָ���������ݸ�ֵ���¿��ٵĿռ䣨����memcpy�� ע�⿽�����ֽ���
		memcpy(Temp, _pData, _capacity*sizeof(DataType));
		_capacity *= 2;
		_pData = Temp;
	}

	return true;
}



/*�������ֵ��ֵ����ʽ��������Ϊ��ֵ��������Ϊ��ֵ
�����Ϊ��ֵ������Ҫ��������
����ֵΪֵ���ᴴ����ʱ����������ϵͳ�Ŀ���
����ֵΪ���ã����ᴴ����ʱ����*/

DataType& Arrary:: operator[](int index) //��������
{
	if (index > (int)_size)
	{
		assert(false);
	}
	return _pData[index];//����������Ӧ��ֵ
}


//�����������������������Ϊ���ò����ϳ��棬���Բ�����
void Arrary::operator<<(ostream &_cout)
{
	_cout << _size;
}


//�����������������������Ϊ���ò����ϳ��棬���Բ�����
void Arrary:: operator>>(istream &_cin)
{
	_cin >> _size;
}




//�����������������������ʹ�����е�˽�г�Ա���򽫺�������Ϊ�����Ԫ����

/*
ostream& _cout�����������������������ֵ����Ҫʹ�ö��󴴽����󣬵������������Ŀ������캯����
�����������Ŀ������캯����˽�е�,�޷����ã������ã��򲻻��ö��󴴽����󣬲�������俽�����캯�������Ҵ����ñ��ⴴ����ʱ��������Сϵͳ������
const Arrary &a����������󣬽�Ҫ�����ֵ��˳�ż�ͷ��cout����ͨ��cout���
*/

/*��ΪҪʵ��������������Ժ�����Ҫ�з���ֵ����Ϊ����
���Ϊֵcout<<a<<a<<endl������ߵ�aͨ�������������cout���൱��cout.operator<<(a)����ֵΪһ��ֵ��Ϊ������
�����������һ��a�����Ϊ��a��һ����������ʱ��ֵΪ��������
*/

ostream& operator<<(ostream& _cout, const Arrary &a)
{
	_cout << a._size;//���⺯�����ܷ������˽�г�Ա������Ϊ�����Ԫ����
	return _cout;
}


istream& operator>>(istream& _cin, Arrary &b)//  ���ഴ���Ķ���ǰ������const����ΪҪ������Ķ����������ĳ����Ա�����Ի���ʱ�ı�
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
	//arr[0] = 1;//����ֵ
	//int b = 3;
	//b = arr[0];//����ֵ
	////ʵ���±������������ �ö������ֱ��ʹ���±������  ��Ϊ��ֵ����ֵ
	//a[0] = 6;
	//b = a[1];


	//ʵ��������������cout<<
	int b = 10;
	int *pb = &b;

	Arrary a;
	/*a << cout; */ //����д��Ҳ����ȷ�ģ�ֻ�ǲ����ϳ��棬������������д
	/*a >> cin;*/   //ͬ��

	/*Arrary *pa = &a;*/
	cout << b << endl;
	/*cout << a ;*/  //�������������޷���ֵ�Ĳ���
	cout << a << " " << a << endl;

	cin >> a;


	return 0;
}