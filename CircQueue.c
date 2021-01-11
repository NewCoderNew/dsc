#include<stdio.h>
#include<stdlib.h>
#define MALLOC(x,size,type)(x=(type*)malloc(size*sizeof(type)))

typedef struct
{
  int n;
}element;

int front=0,rear=0,capacity=1;
element *queue;
void copy(element *, element *,element *);

void queueFull()
{
  element *newqueue;
  MALLOC(newqueue,capacity*2,element);
  int start=(front+1)%capacity;
  if(start<2){
    copy(queue+start,queue+start+capacity-1,newqueue);
  }
  else{
   copy(queue+start,queue+capacity,newqueue);
   copy(queue,queue+rear+1,newqueue+capacity-start);
  }
  front = 2* capacity-1;
  rear = capacity-1;
  capacity*=2;
  free(queue);
  queue=newqueue;
}

void copy(element *start,element *end,element *newqueue)
{
 element *j;
 element *i;
 i=newqueue;
 j=start;
 for(;j<end;j++,i++)
 {
  *i = *j;
 }
}

void enqueue(element item)
{
  rear = (rear+1)%capacity;
  if(front==rear)
  {
    queueFull();
  }
  queue[rear] = item;
}

element dequeue()
{
  element item;
  if(front == rear)
  {
    printf("Queue is empty");
  }
  front = (front+1)%capacity;
  return queue[front];
}

void display()
{
 int i;
 if(front ==rear)
 {
  printf("Queue is Empty!");
  exit(0);
 }
 for(i=(front+1)%capacity;i!=(rear+1)%capacity;i=(i+1)%capacity)
 {
   printf("%d\t",queue[i].n);
  }
}
int main()
{
 int choice;
 char ch='y';
 element item;
 while(ch == 'y')
 {
  printf("**********Circular Queue*********\n");
  printf("Menu:\n1.Add\n2.Delete\n3.Display\nEnter choice:");
  scanf("%d",&choice);
  switch(choice)
  {
    case 1: printf("*****Enqueue*****\n");
            printf("Enter the item to be added:");
            scanf("%d",&item.n);
            enqueue(item);
            break;
    case 2: printf("*****Dequeue*****\n");
            item = dequeue(item);
            printf("Item deleted:%d",item.n);
            break;
    case 3: printf("*****Display*****\n");
            display();
            break;
    default: printf("Would you like to continue(y/n):");
             scanf("%c",&ch);
             break;
 }
}

}

