#include<stdio.h>
#define MAX_TERMS 101
#define MAX_COL 101

typedef struct{
int row;
int col;
int data;
}term;

void input(term a[])
{
 int A[50][50],n,m,curr,i,j;
 printf("Enter the number of rows:");
 scanf("%d",&m);
 printf("Enter the numebr of columns:");
 scanf("%d",&n);
 printf("Enter the values of the matrix");
 for(i=0;i<m;i++)
{  for(j=0;j<n;j++)
   {
    printf("r:%d c:%d",i,j);
    scanf("%d",&A[i][j]);
   }
}
curr =1;
for(i=0;i<m;i++)
{  for(j=0;j<n;j++)
   {
    if(A[i][j]!=0){
    a[curr].row =i;
    a[curr].col=j;
    a[curr].data=A[i][j];
    curr++;
   }
 }
}
a[0].row=m;
a[0].col=n;
a[0].data = curr-1;

}

void output(term a[]){
 int m,n,i,j,num_terms;
 num_terms = a[0].data;
 printf("Row\tcol\tdata\n");
 for(i=0;i<=num_terms;i++){
  printf("%d\t%d\t%d\t",a[i].row,a[i].col,a[i].data);
  printf("\n");
 }
}


void fastranspose(term a[] , term b[]){
 int rowterms[MAX_COL],startpos[MAX_COL];
 int i,j,numcols = a[0].col , numters = a[0].data,numrows = a[0].row;
 b[0].row = numcols;
 b[0].col = numrows;
 b[0].data = numters;
 if(numters > 0){
     for(i=0;i<numcols;i++){
        rowterms[i] = 0;
     }
     for(i=1;i<= numters;i++){
        rowterms[a[i].col]++;
     }
     startpos[0] = 1;
     for(i=1;i<numcols;i++){
        startpos[i] = startpos[i-1] + rowterms[i-1];
     }
     for(i=1;i<=numters;i++){
        j=startpos[a[i].col]++;
        b[j].row = a[i].col;
        b[j].col = a[i].row;
        b[j].data = a[i].data;
     }
  }
}

int main()
{
  term a[MAX_TERMS],b[MAX_TERMS];
  input(a);
  output(a);
  fastranspose(a,b);
  output(b);
}

