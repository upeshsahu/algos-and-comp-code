#include<bits/stdc++.h>
using namespace std; 
/*

Code for find sum of product of subset which size is k */
int n;
long long val[1000][1000];
long long rec(int arr[],int id,int k)
{
	long long sum=0;
	
	if(k==1)
		for(int i=id;i<n;i++)
			sum+=arr[i];
	else if((n-id)==k)
		sum = arr[id]*rec(arr,id+1,k-1);
	else if(id<n)
		sum = rec(arr,id+1,k)+arr[id]*rec(arr,id+1,k-1);
	return  sum;



}
int main()
{
	
	scanf("%d",&n);
	int arr[10001];
	for (int i = 0; i < n; ++i)
	{
		/* code */
		scanf("%d",&arr[i]);

	}
	long long sum=0;
	//printf("%lld\n", rec(arr,0,n-1));
	
	
	printf("%lld\n",rec(arr,0,2) );


	return 0;
}
