#define  _CRT_SECURE_NO_WARNINGS
#include"SeqList.h"

void FunTest()
{
	/*
	SeqList seqList;
	InitSeqList(&seqList);
    PushBack(&seqList, 1);
    PushBack(&seqList, 5);
	PushBack(&seqList, 3);
	PushBack(&seqList, 4);
	PushBack(&seqList, 3);
	PushBack(&seqList, 7);
	PushBack(&seqList, 6);
	PrintSequList(&seqList);*/
	/*Remove(&seqList, 2);*/
	/*Remove(&seqList, 11);*/
	/*RemoveAll(&seqList, 3);*/
	/*Bubble_sort(&seqList);*/
	/*Select_sort(&seqList);*/
	/*printf("%d\n",Bin_search(&seqList, 6, 2));*/
	/*PrintSequList(&seqList);*/
//}
	SeqList seqList;
	InitSeqList(&seqList);
	PullFront(&seqList, 5);
	PullFront(&seqList, 6);
	PullFront(&seqList, 7);
	PullFront(&seqList, 8);
	PrintSequList(&seqList);
	PopFront(&seqList);
	PopFront(&seqList);
	PopFront(&seqList);
	//PopFront(&seqList);
	PrintSequList(&seqList);
}

//void FunTest2()
//{
//	SeqList seqList;
//	InitSeqList(&seqList);
//	PushBack(&seqList, 1);
//	PushBack(&seqList, 2);
//	if (-1 != Find(&seqList, 3))
//	{
//		printf("3 is in seqlist\n");
//	}
//	else
//	{
//		printf("3 isnot in seqlist\n");
//	}
//	if (-1 != Find(&seqList, 1))
//	{
//		printf("1 is in seqlist\n");
//	}
//	else
//	{
//		printf("1 isnot in seqlist\n");
//	}
//}

void FunTest3()
{
	SeqList seqList;
	InitSeqList(&seqList);
	PushBack(&seqList, 1);
	PushBack(&seqList, 2);
	PushBack(&seqList, 3);
	PushBack(&seqList, 4);
	PrintSequList(&seqList);
	printf("%d", Bin_search(&seqList,4, 2));
	/*Insert(&seqList, 2, 6);
	PrintSequList(&seqList);*/
}



int main()
{
	/*FunTest();*/
	//FunTest1();
	//FunTest2();
	FunTest3();
	return 0;
}