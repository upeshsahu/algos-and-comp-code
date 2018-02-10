#include<stdio.h>
void push(int*,int);
int pop(int*);
int top=-1;
int main()
{  int n,beg;
   printf("Enter the size of squre matrix\n");
   scanf("%d",&n);

   int a[n][n],stack[n*n],v[n];
   printf("Enter the matrix\n");

   for(int i=0;i<n;i++)
     for(int j=0;j<n;j++)
       scanf("%d",&a[i][j]);

   printf("Enter the index to begin\n");
   scanf("%d",&beg);

   for(int i=0;i<n;i++)
        v[i]=-1;

     push(stack,beg);
     v[beg]=0;

      while(top!=-1)
      {  beg=pop(stack);
         printf(" %c-> ",beg+65);
        
        for(int j=0;j<n;j++)
             if(a[beg][j]==1  && v[j]!=0)
             {
                push(stack,j);
                    v[j]=0;
             }
       }
return 0;
}
void push(int *s,int n)
{  s[++top]=n;}

int pop(int *s)
{ int t=top;
    top--;
return s[t];}
