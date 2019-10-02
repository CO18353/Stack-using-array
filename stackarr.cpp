#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
void push(int*,int,int*,int);
int pop(int*,int,int*);
void traverse(int*,int*,int*,int*,int);
void update_stack(int*,int*,int*,int*,int);
int peep(int*,int*,int*,int*,int,int);
int main()
{
	int n,op,*s,*ss,TOP=-1,TOP2=-1,ele,up;
	printf("Enter the Size of Stack: ");
	scanf("%d",&n);
	s=(int*)malloc(n*sizeof(int));
	if(s==NULL)
	{
		printf("Memory Not Allocated");
		exit(0);
	}
	ss=(int*)malloc(n*sizeof(int));
	if(ss==NULL)
	{
		printf("Memory Not Allocated");
		exit(0);
	}
/*	for(int i=0;i<n;i++)
	{
		printf("Enter the element %d: ",i+1);
		scanf("%d",s+i);
		TOP=TOP+1;
	}*/
	while(1)
	{
		printf("Press 1.PUSH\n2.POP\n3.TRAVERSE\n4.UPDATE\n5.PEEP\nO/P: ");
		scanf("%d",&op);
		switch(op)
		{																															
			case 1:
					printf("Enter the element to insert: ");
					scanf("%d",&ele);
					push(s,n,&TOP,ele);
					break;
			case 2:
					printf("\t\t%d\n",pop(s,n,&TOP));
					break;
			case 3:
					traverse(s,ss,&TOP,&TOP2,n);
					break;
			case 4:
					update_stack(s,ss,&TOP,&TOP2,n);
					break;
			case 5:
					printf("Enter the element to find: ");
					scanf("%d",&ele);
					printf("%d",peep(s,ss,&TOP,&TOP2,n,ele));
					break;
			default:
					exit(0);
		}
	}
}
void push(int *s,int n,int *TOP,int ele)
{
	if(*TOP==n-1)
	{
		printf("Overflow\n");
	}
	else
	{
		*TOP=*TOP+1;
		s[*TOP]=ele;
	}
}
int pop(int *s,int n,int *TOP)
{
	if(*TOP==-1)
	{
		printf("Underflow ");
		return 0;
	}
	else
	{
		int p=*(s+(*TOP));
		*TOP=*TOP-1;
		return p;		
	}
}
void traverse(int *s,int *ss,int *TOP,int *TOP2,int n)
{
	int e;
	if(*TOP!=-1)
	{
		while(*TOP!=-1)
		{
			e=pop(s,n,TOP);
			push(ss,n,TOP2,e);
			printf("%d\n",e);
		}

		while(*TOP2!=-1)
		{
			e=pop(ss,n,TOP2);
			push(s,n,TOP,e);
		}
	}
}
void update_stack(int *s,int *ss,int *TOP,int *TOP2,int n)
{
	int e,up,newe;
	if(*TOP!=-1)
	{
		printf("Enter the element to update: ");
		scanf("%d",&up);
		while(*TOP!=-1)
		{
			if(s[*TOP]==up)
			{
				printf("Enter the new element: ");
				scanf("%d",&newe);
				s[*TOP]=newe;
			}
			e=pop(s,n,TOP);
			push(ss,n,TOP2,e);
		}

		while(*TOP2!=-1)
		{
			e=pop(ss,n,TOP2);
			push(s,n,TOP,e);
		}
	}
}
int peep(int *s,int *ss,int *TOP,int *TOP2,int n,int ele)
{
	int e,pos;
	if(*TOP!=-1)
	{
		while(*TOP!=-1)
		{
			if(s[*TOP]==ele)
			{
				pos=(*TOP)+1;
			}
			e=pop(s,n,TOP);
			push(ss,n,TOP2,e);
		}

		while(*TOP2!=-1)
		{
			e=pop(ss,n,TOP2);
			push(s,n,TOP,e);
		}
		return pos;
	}	
}

