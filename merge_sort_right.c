#include<stdio.h>
void merge(int a[],int,int ,int );


void mergesort(int a[],int start,int end)
 {   int mid;
     if(start<end)
     { 
      mid=(start+end)/2;
      mergesort(a,start,mid);
      mergesort(a,mid+1,end);  
      merge(a,start,mid,end);
     }
}

void merge(int a[],int start,int mid,int end)
{
   int i=start,j=mid+1,index=start,temp[100],k;
   
   while( (i<=mid) && (j<=end))
     {
       if(a[i]>a[j])
          { temp[index]=a[j];
               j++;
          }
       else if(a[i]<a[j])
         {  temp[index]=a[i];
              i++;
         }
         index++;
     }
   while(i<=mid&&j>end)
         {  temp[index]=a[i]; 
               index++;
               i++;}
   while(j<=end&&i>mid)
        {    temp[index]=a[j];
               index++;
               j++;}
      
 


  for(k=start;k<index;k++)   
        a[k]=temp[k];
}  


int main()
{  int n,i,m=0,a[100];
   printf("enter the elements"); 
   scanf("%d",&n);
 
  for(i=0;i<n;i++)
    scanf("%d",&a[i]);

  mergesort(a,m,n-1);

  printf("the merge sorted array is \n");
   for(i=0;i<n;i++)
     printf(" %d ",a[i]);

return 0;}


