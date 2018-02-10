#include<stdio.h>
int main()
{  int n,f=-1,r=-1,beg,l=-1;
   printf("Enter the size of squre matrix\n");  
   scanf("%d",&n);
   
   int a[n][n],queue[n*n],v[n];
   printf("Enter the matrix\n");
   
   for(int i=0;i<n;i++)
     for(int j=0;j<n;j++)
       scanf("%d",&a[i][j]);
 
   printf("Enter the index to begin\n");
   scanf("%d",&beg);
   
   for(int i=0;i<n;i++)
        v[i]=-1;
      
      queue[++r]=beg;
      f++;
      v[beg]=0;
      
      while(f!=-1)
      {
        beg=queue[++l];
        printf(" %c-> ",beg+65);
        f--;
        for(int j=0;j<n;j++)
             if(a[beg][j]==1  && v[j]!=0) 
             { queue[++r]=j;
                    f++;
                    v[j]=0;
             }
       }
return 0;
}



