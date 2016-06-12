#define  _CRT_SECURE_NO_WARNINGS
#define MAX_SIZE 10

#include<assert.h>
#include<stdio.h>
#include<string.h>

typedef int DataType;
typedef unsigned int Size_t;

typedef struct SeqList
{
	DataType arrary[MAX_SIZE];
	Size_t size;//size����������ЧԪ�ظ���Ҳ����һ��Ԫ���±�
}SeqList, *PSeqList;

//����ԭ��
void InitSeqList(PSeqList seqlist);
void PushBack(PSeqList seqlist, DataType data);
void PopBack(PSeqList seqlist);
void PrintSequList(PSeqList seqlist);
void PullFront(PSeqList seqlist, DataType data);
void PopFront(PSeqList seqlist);
void Insert(PSeqList seqlist, int pos, DataType data);
int Find(PSeqList seqlist, DataType data);
void Erase(PSeqList seqlist, int pos);
void Remove(PSeqList seqlist, DataType data);
void RemoveAll(PSeqList seqlist, DataType data);


//��ʼ��˳���
void InitSeqList(PSeqList seqlist)
{
	assert(NULL != seqlist);
	memset(seqlist->arrary, 0, MAX_SIZE*sizeof(DataType));
	seqlist->size = 0;
}

//β��
void PushBack(PSeqList seqlist, DataType data)
{
	assert(NULL != seqlist);
	//���˳����Ƿ�����
	/*if (seqlist->size>= MAX_SIZE)
	{
		return;
	}
	seqlist->arrary[seqlist->size] = data;
	seqlist->size++;*/
	Insert(seqlist, seqlist->size, data);
}

//βɾ
void PopBack(PSeqList seqlist)
{
	assert(NULL != seqlist);
	//���˳����Ƿ�Ϊ��
	if (seqlist->size <= 0)
	{
		return;
	}
	seqlist->size--;
}

//��ӡ˳���
void PrintSequList(PSeqList seqlist)
{
	int i = 0;
	assert(NULL != seqlist);
	for (i = 0; i < seqlist->size; i++)
	{
		printf("%d", seqlist->arrary[i]);
	}
	printf("\n");
}

//ͷ��
void PullFront(PSeqList seqlist, DataType data)
{
	//int iIdx = seqlist->size;
	//assert(NULL != seqlist);
	////���˳����Ƿ�����
	//if (seqlist->size>= MAX_SIZE)
	//{
	//	return;
	//}
	////��������
	//for (iIdx; iIdx > 0; iIdx--)
	//{
	//	seqlist->arrary[iIdx] = seqlist->arrary[iIdx-1];
	//}
	////���ݲ����һ��λ��
	//seqlist->arrary[0] = data;
	//seqlist->size++;
	Insert(seqlist, 0, data);
}

//ͷɾ
void PopFront(PSeqList seqlist)
{
	int iIdx = 0;
	assert(NULL != seqlist);
	//���˳����Ƿ�Ϊ��
	if (seqlist->size <= 0)
	{
		return;
	}
	for (iIdx = 0; iIdx < seqlist->size-1; iIdx++)
	{
		seqlist->arrary[iIdx] = seqlist->arrary[iIdx+1];
	}
	seqlist->size--;
}

//�κ�ָ��λ�ò���
void Insert(PSeqList seqlist, int pos, DataType data)
{
	int i;
	//ȷ��˳���δ�� pos��[0,size)֮��
	assert((NULL != seqlist)&&(pos>=0)&&(pos<=seqlist->size));
	for (i = seqlist->size; i > pos; i--)
	{
		seqlist->arrary[i] = seqlist->arrary[i-1];
	}
	seqlist->arrary[pos] = data;
	seqlist->size++;
}

//˳����в���Ԫ��
int Find(PSeqList seqlist, DataType data)
{
	int i = 0;
	assert(NULL != seqlist);
	for (i = 0; i < seqlist->size; i++)
	{
		if (seqlist->arrary[i] == data)
		{
			return i;
		}
	}
	return -1;
}


// ɾ��˳�����posλ���ϵ�Ԫ��
void Erase(PSeqList seqlist, int pos)
{
	int i = pos;
	/*assert((NULL != seqlist) && (pos >= 0) && (pos <= seqlist->size));*/
	assert((NULL != seqlist));
	if (!(pos >= 0) && (pos <= seqlist->size))
	{
		printf("not exist\n");
		return;
	}
	for (i = pos; i <seqlist->size-1; i++)
	{
		seqlist->arrary[i] = seqlist->arrary[i+1];
	}
	seqlist->size--;
}

//�Ƴ�˳����е�Ԫ��data
void Remove(PSeqList seqlist, DataType data)
{
	assert(NULL != seqlist);
	Erase(seqlist, Find(seqlist,data));
}

// �Ƴ�˳���������Ԫ��data
void RemoveAll(PSeqList seqlist, DataType data)
{
	//1.����һ��ռ䣨���¿��٣� �Ѳ�Ҫɾ����Ԫ�طŵ����⿪�ٵ�����ռ�
	int i = 0;
	int count = 0;
	DataType* tempArr = NULL;
	assert(NULL != seqlist);
	tempArr = (DataType*)malloc(seqlist->size*sizeof(DataType));
	if (NULL == *tempArr)
	{
		return;
	}
	for (i = 0; i < seqlist->size; i++)
	{
		if (seqlist->arrary[i] != data)
		{
			tempArr[count++] = seqlist->arrary[i];
		}
	}
	memcpy(seqlist->arrary, tempArr, count*sizeof(DataType));//�����¿��ٿռ��е�Ԫ�ؿ�����ԭ����˳����У�����count��
	seqlist->size = count;//��ʱ˳�����Ԫ�صĸ����Ѿ������ı� Ӧ��Ϊδɾ��Ԫ�صĸ��� ��count��
	free(tempArr);

	//2.����˳��� ����Ҫɾ����Ԫ�� ������count+1 ����������ɾ��Ԫ�غ����Ԫ������countλ 
	/*int i = 0;
	int count = 0;
	for (i = 0; i < seqlist->size; i++)
	{
		if (seqlist->arrary[i] == data)
		{
			count++;
		}
		else
		{
			seqlist->arrary[i-count] = seqlist->arrary[i];
		}
	}
	seqlist->size -= count;*/
}


//ð������ʵ��
void Bubble_sort(PSeqList seqlist)
{
	int i = 0;
	int j = 0;
	int flag = 0;//���ñ�־λ���������  ��if������ȥ
	assert(NULL != seqlist);
	for (i = 0; i < seqlist->size - 1; i++)//��ɽ����Ԫ�غ�����Ҫ�Ĵ���
	{
		flag = 0;
		for (j = 0; j < seqlist->size - i - 1; j++)//Ԫ����������߽��бȽ�
		{
			flag = 0;
			if (seqlist->arrary[j]>seqlist->arrary[j + 1])
			{
				int tmp = seqlist->arrary[j];
				seqlist->arrary[j] = seqlist->arrary[j+1];
				seqlist->arrary[j + 1] = tmp;
				flag = 1;
			}
		}
		if (0 == flag)
		{
			break;
		}
	}
}


//ѡ������
void Select_sort(PSeqList seqlist)
{
	//1.
	//int i = 0;
	//int k;//k��СԪ��λ��
	//assert(NULL != seqlist);
	//for (i = 1; i <= seqlist->size - 2; i++)
	//{
	//	int j = 0;
	//	k = i;
	//	for (j = i + 1; j <= seqlist->size-1; j++)
	//	{
	//		if (seqlist->arrary[j] < seqlist->arrary[k])
	//		{
	//			k = j;
	//		}
	//	}
	//	if (i != k)
	//	{
	//		DataType temp;
	//		temp = seqlist->arrary[i];
	//		seqlist->arrary[i] = seqlist->arrary[k];
	//		seqlist->arrary[k] = temp;
	//	}
	//}


	////2.Ѱ�����Ԫ�طŵ�˳����β��
	//int i = 0;
	//int j = 0;
	//int pos = 0;
	//DataType temp = 0;
	//for (i = 0; i < seqlist->size - 1; i++)
	//{
	//	pos = 0;
	//	for (j = 1; j < seqlist->size - i; j++)//for (j = 1; j <= seqlist->size - i - 1; j++)  ��֤���һ��Ԫ��Ҫȡ��
	//	{
	//		if (seqlist->arrary[j] > seqlist->arrary[pos])
	//		{
	//			pos = j;
	//		}
	//	}
	//	if (pos != seqlist->size - i - 1)
	//	{
	//		temp = seqlist->arrary[pos];
	//		seqlist->arrary[pos] = seqlist->arrary[seqlist->size - i - 1];
	//		seqlist->arrary[seqlist->size - i - 1] = temp;
	//	}
	//}


	//3.Ѱ�������СԪ�أ����Ԫ�طŵ�˳����β������СԪ�طŵ�˳���ͷ��
	int i = 0;
	int j = 0;
	int MaxPos = 0;
	int MinPos = 0;
	DataType temp= 0;
	assert(NULL != seqlist);
	for (i = 0; i < seqlist->size/2; i++)
	{
		MaxPos = i;
		MinPos = i;
		for (j = i + 1; j < seqlist->size -i; j++)
		{
			if (seqlist->arrary[j]>seqlist->arrary[MaxPos])
			{
				MaxPos = j;
			}
			if (seqlist->arrary[j]<seqlist->arrary[MinPos])
			{
				MinPos = j;
			}
		}
		if (MaxPos != seqlist->size - i - 1)
		{
			temp = seqlist->arrary[MaxPos];
			seqlist->arrary[MaxPos] = seqlist->arrary[seqlist->size- i- 1];
			seqlist->arrary[seqlist->size - i- 1] = temp;
		}

		//˼��
		if (i == MaxPos&&seqlist->size - 1 - i == MinPos)
		{
			continue;
		}

		if (MinPos != i)
		{
			temp = seqlist->arrary[MinPos];
			seqlist->arrary[MinPos] = seqlist->arrary[i];
			seqlist->arrary[i] = temp;
		}
	}
}


//���ֲ��ҷ� ���������飩
int Bin_search(PSeqList seqlist, size_t size, DataType data)
{
	int left = 0;
	int right = size - 1; //[]
	// int right = size ;   [) 
	int middle = 0;
	int temp = 0;
	while (left <= right)//while (left < right)
	{
		middle = left + (right - left) / 2;
		temp = seqlist->arrary[middle];
		if (data < temp)
		{
			right = middle - 1;//right = middle;
		}
		else if (data>temp)
		{
			left = middle + 1;
		}
		else
			return middle;
	}
	return -1;
}
