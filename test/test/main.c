#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAXSIZE 100
typedef int Status;
typedef int ElemType;
typedef struct{
	ElemType *elem;
	int length;
}SqList;
Status InitList(SqList *L)//构造一个空的顺序表
{
	L->elem = (ElemType*)malloc(MAXSIZE);//为顺序表分配一个大小为MAXSIZE的数组空间
	if (!L->elem)
		exit(OVERFLOW);//存储失败
	L->length = 0;//空表长度为零
	return OK;
}
void Getlist(SqList*L, int n)
{
	int count = 0;
	int i = 0;
	L->length = n;
	if (n == 0)
		return;
	printf("输入顺序表的元素：");
	for (i = 0; i < n; i++)
	{
		scanf("%d", &L->elem[i]);
		count++;
	}
}
Status Printlist(SqList *L)//  初始条件：顺序线性表L已存在 
{
	ElemType *p;
	p = L->elem;
	int i;
	//    printf("线性表当前容量为：%d\n", L.listsize);
	if (L->length>0)
	{
		printf("当前线性表有%d个元素,分别是\n", L->length);
		for (i = 1; i <= L->length; i++)
		{
			printf("%d ", L->elem[i - 1]);
		}
	}
	else
	{
		printf("目前还是空线性表.\n");
	}
	printf("\n");
	return 0;
}
Status GetElem(SqList *L, int i, ElemType *e)//取出第i个元素
{
	if (i<1 || i>L->length)
	{
		return ERROR;
	}
	else
		*e = L->elem[i - 1];
	return*e;
}
// 查找
int LocateElem(SqList *L, ElemType e)//返回的是要查找元素的在表中的序号
{
	int i = 0;
	for (i = 0; i < L->length; i++)
	{
		if (e == L->elem[i])
		{
			return i;
			break;
		}
	}
}
Status ListInsert(SqList *L, int i, ElemType e)//插入 
{
	int j = 0;
	L->length++;
	if (i<1 || i>L->length)
	{
		return ERROR;
	}
	if (L->length>MAXSIZE)
	{
		return ERROR;
	}
	for (j = L->length; j > 0 && j != i; j--)
	{
		//L->length++;
		L->elem[j] = L->elem[j - 1];
	}
	L->elem[j] = L->elem[j - 1];
	L->elem[j - 1] = e;
	return 0;
}
Status ListDelete(SqList *L, int i)
{
	int j = 0;
	if (i<1 || i>L->length)
	{
		printf("不存在这个元素");
		return ERROR;
	}
	if (L->length>MAXSIZE)
	{
		return ERROR;
	}
	for (j = i; j <= L->length; j++)
	{
		L->elem[j - 1] = L->elem[j];
	}

	L->length--;
}
int main()
{
	SqList la;
	ElemType e = 0;
	int n = 0;
	int i = 0;
	printf("输入顺序表的长度：");
	scanf("%d", &n);
	InitList(&la);
	Getlist(&la, n);
	Printlist(&la);
	printf("输出第几个元素：");
	scanf("%d", &i);
	GetElem(&la, i, &e);
	printf("第%d个元素是：%d\n", i, GetElem(&la, i, &e));
	LocateElem(&la, i);
	printf("输入要查询下标的元素值：");
	scanf("%d", &e);
	printf("元素%d的下标是：%d\n", e, LocateElem(&la, e));
	printf("要插入的元素位置是：");
	scanf("%d", &i);
	printf("要插入的元素是：");
	scanf("%d", &e);
	ListInsert(&la, i, e);
	Printlist(&la);
	printf("要删除第几个元素：");
	scanf("%d", &i);
	ListDelete(&la, i);
	Printlist(&la);
	return 0;
}