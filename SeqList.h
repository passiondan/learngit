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
	Size_t size;//size是数组中有效元素个数也是下一个元素下标
}SeqList, *PSeqList;

//函数原型
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


//初始化顺序表
void InitSeqList(PSeqList seqlist)
{
	assert(NULL != seqlist);
	memset(seqlist->arrary, 0, MAX_SIZE*sizeof(DataType));
	seqlist->size = 0;
}

//尾插
void PushBack(PSeqList seqlist, DataType data)
{
	assert(NULL != seqlist);
	//检测顺序表是否已满
	/*if (seqlist->size>= MAX_SIZE)
	{
		return;
	}
	seqlist->arrary[seqlist->size] = data;
	seqlist->size++;*/
	Insert(seqlist, seqlist->size, data);
}

//尾删
void PopBack(PSeqList seqlist)
{
	assert(NULL != seqlist);
	//检测顺序表是否为空
	if (seqlist->size <= 0)
	{
		return;
	}
	seqlist->size--;
}

//打印顺序表
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

//头插
void PullFront(PSeqList seqlist, DataType data)
{
	//int iIdx = seqlist->size;
	//assert(NULL != seqlist);
	////检测顺序表是否已满
	//if (seqlist->size>= MAX_SIZE)
	//{
	//	return;
	//}
	////搬移数据
	//for (iIdx; iIdx > 0; iIdx--)
	//{
	//	seqlist->arrary[iIdx] = seqlist->arrary[iIdx-1];
	//}
	////数据插入第一个位置
	//seqlist->arrary[0] = data;
	//seqlist->size++;
	Insert(seqlist, 0, data);
}

//头删
void PopFront(PSeqList seqlist)
{
	int iIdx = 0;
	assert(NULL != seqlist);
	//检测顺序表是否为空
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

//任何指定位置插入
void Insert(PSeqList seqlist, int pos, DataType data)
{
	int i;
	//确保顺序表未满 pos在[0,size)之间
	assert((NULL != seqlist)&&(pos>=0)&&(pos<=seqlist->size));
	for (i = seqlist->size; i > pos; i--)
	{
		seqlist->arrary[i] = seqlist->arrary[i-1];
	}
	seqlist->arrary[pos] = data;
	seqlist->size++;
}

//顺序表中查找元素
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


// 删除顺序表中pos位置上的元素
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

//移除顺序表中的元素data
void Remove(PSeqList seqlist, DataType data)
{
	assert(NULL != seqlist);
	Erase(seqlist, Find(seqlist,data));
}

// 移除顺序表中所有元素data
void RemoveAll(PSeqList seqlist, DataType data)
{
	//1.借助一块空间（重新开辟） 把不要删除的元素放到另外开辟的数组空间
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
	memcpy(seqlist->arrary, tempArr, count*sizeof(DataType));//将重新开辟空间中的元素拷贝到原来的顺序表中，拷贝count个
	seqlist->size = count;//此时顺序表中元素的个数已经发生改变 应该为未删除元素的个数 即count个
	free(tempArr);

	//2.遍历顺序表 遇到要删除的元素 计数器count+1 继续遍历，删除元素后面的元素左移count位 
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


//冒泡排序法实现
void Bubble_sort(PSeqList seqlist)
{
	int i = 0;
	int j = 0;
	int flag = 0;//采用标志位，如果已序  则if语句进不去
	assert(NULL != seqlist);
	for (i = 0; i < seqlist->size - 1; i++)//完成将最大元素后移需要的次数
	{
		flag = 0;
		for (j = 0; j < seqlist->size - i - 1; j++)//元素依次与后者进行比较
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


//选择排序法
void Select_sort(PSeqList seqlist)
{
	//1.
	//int i = 0;
	//int k;//k最小元素位置
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


	////2.寻找最大元素放到顺序表的尾部
	//int i = 0;
	//int j = 0;
	//int pos = 0;
	//DataType temp = 0;
	//for (i = 0; i < seqlist->size - 1; i++)
	//{
	//	pos = 0;
	//	for (j = 1; j < seqlist->size - i; j++)//for (j = 1; j <= seqlist->size - i - 1; j++)  保证最后一个元素要取到
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


	//3.寻找最大做小元素，最大元素放到顺序表的尾部，最小元素放到顺序表头部
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

		//思考
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


//二分查找法 （有序数组）
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
