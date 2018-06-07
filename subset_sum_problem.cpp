#include<bits/stdc++.h>
using namespace std;

bool dp_function(int sum,int a[],int n);
bool function_rec(int sum,int a[],int n);


bool dp_function(int sum,int a[],int n)
{
   bool dp[n+1][sum+1];


   for(int i=0;i<=n;i++)
   	  dp[i][0]=true;

   for(int i=1;i<=sum;i++)
   	  dp[0][i]=false;

   	
    for(int i=1;i<=n;i++)
    	for(int j=1;j<=sum;j++)
    	{
    		if(j<a[i-1])
    			dp[i][j]=dp[i-1][j];
    		else
    			dp[i][j]=dp[i-1][j-a[i-1]]|dp[i-1][j];
    	}

   		return dp[n][sum];




}

int main()
{
   int n,sum;
   cin>>n>>sum;
   int a[n];
   for(int i=0;i<n;i++)
   	  cin>>a[i];


	
      cout<<dp_function(sum,a,n);
return 0;
}



bool function_rec(int sum,int a[],int n)
{
    if(sum==0)
    	return true;
    if(sum<0)
    	return false;
    if(n<0)
    	return false;

	return function_rec(sum-a[n-1],a,n-1)|function_rec(sum,a,n-1);
}