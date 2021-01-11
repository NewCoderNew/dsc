#include<stdio.h>
#include<stdlib.h>

struct node
{
  int data;
  struct node *rlink;
  struct node *llink;
};

typedef struct node *listptr;

void insert(listptr* first,int item)
{
  listptr nn;
  nn=(listptr)malloc(sizeof(listptr*));
  nn->data=item;
  nn->llink=NULL;
  nn->rlink=NULL;
  if(*first)
  {
    nn->rlink=*first;
    (*first)->llink=nn;
  }
  *first=nn;
  //return;
}

void del(listptr* first)
{
  int item;
  listptr temp;
  temp = *first;
  item = (*first)->data;
  *first=(*first)->rlink;
  (*first)->llink=NULL;
  free(temp);
}

void search(listptr first , int item)
{
  while(first)
  {
    if(first->data==item)
    {
      printf("\nFound");
      return;
    }
    else
      first = first->rlink;
  }
  printf("\nNot Found");
}

void display(listptr first)
{
  int ch = 0;
  printf("\n1.Forward \n 2. Reverse\n");
  printf("Enter Choice:");
  scanf("%d",&ch);
  if(first)
  {
      switch (ch)
      {
        case 1: while(first)
                {
                    printf("%d\t",first->data);
                    first=first->rlink;
                }
                break;
        case 2: while(first->rlink != NULL)
                {
                    first = first->rlink;
                }
                while(first != NULL)
                {
                    printf("%d \t ",first->data);
                    first = first->llink;
                }
                break;
        
        default: printf("Invalid Choice");
                break;
      }
    
  }
  else
  {
     printf("\nEmpty List");
  }
}

int main()
{
  listptr first;
  int ch,item;
  while(1)
  {
    printf("\n1.Insert\n2.Delete\n3.Search\n4.Display\n5.Exit\n");
    printf("Enter choice:");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1: printf("\n Enter the element to be inserted:");
              scanf("%d",&item);
              insert(&first,item);
              break;
      case 2: del(&first);
              break;
      case 3: printf("\n Enter the element to be searched:");
              scanf("%d",&item);
              search(first,item);
              break;
      case 4: display(first);
              break;
      case 5: exit(1);
    }
  }
}
