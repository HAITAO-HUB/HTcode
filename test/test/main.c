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
Status InitList(SqList *L)//����һ���յ�˳���
{
	L->elem = (ElemType*)malloc(MAXSIZE);//Ϊ˳������һ����СΪMAXSIZE������ռ�
	if (!L->elem)
		exit(OVERFLOW);//�洢ʧ��
	L->length = 0;//�ձ���Ϊ��
	return OK;
}
void Getlist(SqList*L, int n)
{
	int count = 0;
	int i = 0;
	L->length = n;
	if (n == 0)
		return;
	printf("����˳����Ԫ�أ�");
	for (i = 0; i < n; i++)
	{
		scanf("%d", &L->elem[i]);
		count++;
	}
}
Status Printlist(SqList *L)//  ��ʼ������˳�����Ա�L�Ѵ��� 
{
	ElemType *p;
	p = L->elem;
	int i;
	//    printf("���Ա�ǰ����Ϊ��%d\n", L.listsize);
	if (L->length>0)
	{
		printf("��ǰ���Ա���%d��Ԫ��,�ֱ���\n", L->length);
		for (i = 1; i <= L->length; i++)
		{
			printf("%d ", L->elem[i - 1]);
		}
	}
	else
	{
		printf("Ŀǰ���ǿ����Ա�.\n");
	}
	printf("\n");
	return 0;
}
Status GetElem(SqList *L, int i, ElemType *e)//ȡ����i��Ԫ��
{
	if (i<1 || i>L->length)
	{
		return ERROR;
	}
	else
		*e = L->elem[i - 1];
	return*e;
}
// ����
int LocateElem(SqList *L, ElemType e)//���ص���Ҫ����Ԫ�ص��ڱ��е����
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
Status ListInsert(SqList *L, int i, ElemType e)//���� 
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
		printf("���������Ԫ��");
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
	printf("����˳���ĳ��ȣ�");
	scanf("%d", &n);
	InitList(&la);
	Getlist(&la, n);
	Printlist(&la);
	printf("����ڼ���Ԫ�أ�");
	scanf("%d", &i);
	GetElem(&la, i, &e);
	printf("��%d��Ԫ���ǣ�%d\n", i, GetElem(&la, i, &e));
	LocateElem(&la, i);
	printf("����Ҫ��ѯ�±��Ԫ��ֵ��");
	scanf("%d", &e);
	printf("Ԫ��%d���±��ǣ�%d\n", e, LocateElem(&la, e));
	printf("Ҫ�����Ԫ��λ���ǣ�");
	scanf("%d", &i);
	printf("Ҫ�����Ԫ���ǣ�");
	scanf("%d", &e);
	ListInsert(&la, i, e);
	Printlist(&la);
	printf("Ҫɾ���ڼ���Ԫ�أ�");
	scanf("%d", &i);
	ListDelete(&la, i);
	Printlist(&la);
	return 0;
}