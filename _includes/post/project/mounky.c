#include <stdio.h>
#include <stdlib.h>


typedef int status;
typedef int ElemType;

typedef struct NODE_MONKY
{
	ElemType serial_number;
	struct NODE_MONKY *next;
}LNode, *LinkList;

void Build(LinkList L,int n){
	LinkList p,q;
	p = L;
	for(int i=0;i<n;i++)
	{	
		printf("%d\n",i+1);
		q = (LinkList)malloc(sizeof(LNode));
		q -> serial_number = i+1;
		q -> next = NULL;
		p -> next = q;
		p = q;
	}
	p -> next = L->next;
}

void Print(LinkList L,int x)//计算单链表的长度，然后输出单链表
{
    LinkList p;
    p=L->next;
    while(x--)
    {
        printf("%d ",p->serial_number);
        p=p->next;
    }

}

void Delete(LinkList L,int x,int y)//删除值为x的结点
{
    LinkList p,q;
	p=L->next;
	for (int i = 1; i < y; i++)
	{
		for(int j = 2; j < x ; j++)
		{
		p = p->next;
		printf("serial_number change = %d\n",p->serial_number);
		}

		q = p->next;
        p->next = q->next;

        printf("delete %d success\n",q->serial_number);
        printf("p->serial_number = %d\n",p->serial_number);
        free(q);
        q = NULL;
        p = p->next;
        printf("p->serial_number now = %d\n",p->serial_number);
	}
	
}


int main()
{
	int m,n;

	LinkList L,p,q;
	L = (LinkList)malloc(sizeof(LNode));
	L -> next = NULL;
	L -> serial_number = 1;
	printf("please input the number of mounky.\n");
	scanf("%d",&n);
	Build(L,n);
	Print(L,n);
	printf("Please input the number M\n");
	scanf("%d",&m);
	Delete(L,m,n);
	
}