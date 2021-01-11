#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10

typedef struct
{
   int key;
}element;

struct stack
{
   element data;
   struct stack *link;
};

typedef struct stack *stkptr;
stkptr top[MAXSIZE];

void push (element item, int i)
{
  stkptr temp;
  temp = (stkptr)malloc(sizeof(stkptr*));
  temp->data = item;
  temp->link = top[i];
  top[i]=temp;
}

element pop(int i)
{
  stkptr temp;
  element item;
  temp=top[i];
  if(temp==NULL)
  {
    item.key = -1;
    return item;
  }
  else
  {
    top[i] = top[i]->link;
    item = temp->data;
    free(temp);
    return item;
  }
}

void display(int i)
{
  stkptr temp = top[i];
  if(temp == NULL)
     printf("Empty Stack");
  for(;temp;temp=temp->link)
  {
     printf("%d\t",temp->data.key);
  }
}

void main()
{
  int ch,i,j;
  element item;
  for(j=0;j<MAXSIZE;j++)
  {
     top[j]=NULL;
  }
  do
  {
     printf("******MULTIPLE LINKED LIST STACK******");
     printf("\n1.Push\n2.Pop\n3.Display\n4.Exit");
     printf("\nEnter choice:");
     scanf("%d",&ch);
     switch(ch)
     {
        case 1: printf("\nEnter the item to be inserted:");
                scanf("%d",&item.key);
                printf("\nEnter the stack number:");
                scanf("%d",&i);
                push(item,i-1);
                break;

        case 2: printf("\nEnter the stack number from which the element should be popped:");
                scanf("%d",&i);
                item = pop(i-1);
                if(item.key==-1)
                    printf("\nEmpty Stack\n");
                else
                    printf("\nDeleted element:%d\n",item.key);
                break;

        case 3: printf("\n Enter the stack number you want to display:");
                scanf("%d",&i);
                display(i-1);
                printf("\n");
                break;

        case 4: printf("\n****EXITING****\n");
                break;

        default: printf("Wrong Choice!");
                 break;
     }
  }while(ch!=4);
}