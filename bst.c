#include<stdio.h>
#include<stdlib.h>

struct tree
{
  int data;
  struct tree *rlink;
  struct tree *llink;
};

typedef struct tree *treeptr;

void insert(treeptr *root,int item)
{
  if(!(*root))
  {
    (*root)=(treeptr)malloc(sizeof(treeptr*));
    (*root)->data = item;
    (*root)->llink= NULL;
    (*root)->rlink = NULL;
  }
  else if((*root)->data>item)
    insert(&(*root)->llink,item);
  else if((*root)->data<item)
    insert(&(*root)->rlink,item);
}

void inorder(treeptr root)
{
  if(root)
  {
   inorder(root->llink);
   printf("%d\t",root->data);
   inorder(root->rlink);
  }
}

void search(treeptr root, int item)
{
  if(root==NULL)
  {
    printf("\nNOT FOUND");
    return;
  }
  else if(root->data == item)
  {
    printf("\nFOUND");
    return;
  }
  else if(root->data>item)
    search(root->llink,item);
  else if(root->data<item)
    search(root->rlink,item);
}

int main()
{
  int choice,item;
  treeptr root;
  root=NULL;
  while(1)
  {
   printf("\n*****BINARY SEARCH TREE*****");
   printf("\n1.Insert\n2.Inorder\n3.Search\n4.Exit\n");
   printf("Enter choice:");
   scanf("%d",&choice);
   switch(choice)
   {
     case 1: printf("***INSERT***");
             printf("\nEnter the element to be inserted:");
             scanf("%d",&item);
             insert(&root,item);
             break;
     case 2: printf("\n****INORDER****\n");
             inorder(root);
             break;
     case 3: printf("\n****SEARCH*****\n");
             printf("\nEnter the item to be searched:");
             scanf("%d",&item);
             search(root,item);
             break;
     case 4: printf("****EXITING***\n");
             exit(1);
   }
 }
}
