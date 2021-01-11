#include<stdio.h>
#include<stdlib.h>
typedef struct
{
	int key;
}element;
struct queue
{
	element data;
	struct queue* link;
};

typedef struct queue* queueptr;

queueptr front[10],rear[10];
void insert(element item,int i)
{
	queueptr temp;
	temp=(queueptr)malloc(sizeof(struct queue));
	temp->data=item;
	if(front[i])
	{
		rear[i]->link=temp;
	}
	else
		front[i]=temp;
	rear[i]=temp;
	rear[i]->link=NULL;
}


element delete(int i)
{
	queueptr temp;
	temp=front[i];
	element item;
	if(front[i])
	{
		item=front[i]->data;
		front[i]=front[i]->link;
	}
	else
	{
		item.key=-1;
	}
	free(temp);
	return item;
}
void display(int i)
{
	queueptr temp;
	temp=front[i];
	if(front[i] == NULL){
		printf("Queue is Empty\n");
		return;
		}
	printf("Queue %d is:",i+1);
	for(;temp;temp=temp->link)
		printf("%d\t",temp->data.key);
	printf("\n");
}


int main(){
	int choice,qno;
	element item;
	int n;
	printf("Enter How many Queus:");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		front[i]=rear[i]=NULL;
	while(1){
		printf(" 1.Insert \n 2. Delete \n 3.Display \n 4.Quit \n");
		printf("Enter the Choice:");
		scanf("%d",&choice);
		if(choice != 4)
		{
			printf("Enter The Queue no from 1 to %d: ",n);
			scanf("%d",&qno);
		}
		switch(choice)
		{
			case 1:
				printf("Enter Data to be inserted:");
				scanf("%d",&item.key);
				insert(item,qno-1);
				break ;
			case 2:
				item = delete(qno-1);
				if(item.key==-1)
					printf("Queue empty....\n");
				else
					printf("Element deleted:%d \n",item.key);
				break;
			case 3:
				display(qno-1);
				break;
			case 4: 
				exit(0);
			default : 
				printf("Invalid Input...");
		}
	}
}
