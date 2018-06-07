#include<bits/stdc++.h>
using namespace std;

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int a[],int l,int r)
{   int i=l-1;
	int pi=r;
	for(int j=l;j<r;j++)
	{
       if(a[j]<=a[pi])
       {
       	i++;
       	swap(&a[i],&a[j]);
       }
	}
	swap(&a[i+1],&a[pi]);
	return i+1;
}

void quick_sort(int a[],int l,int r)
{
	if(l<r){
	int pi=partition(a,l,r);
	
	quick_sort(a,l,pi-1);
	quick_sort(a,pi+1,r);

   }
}


//to further optimise the algo we can reduce the recursive call by 

// void quick_sort(int a[],int l,int r)
// {
// 	if(l<r){
// 	int pi=partition(a,l,r);
	
// 	quick_sort(a,l,pi-1);
// 	l=pi+1;

//    }
// }

int main()
{
   int n;
   cin>>n;
   int a[n];

   for(int i=0;i<n;i++)
   	   cin>>a[i];
   	quick_sort(a,0,n-1);

   	for (int i = 0; i < n; ++i)
   	{
   		cout<<a[i]<<" ";
   	}

	return 0;
}