#include<bits/stdc++.h>
using namespace std;

int rec_function(int w[],int v[],int n,int W)
{

    if(n==0 || W==0)
    	return 0;
    if(W<0)
    	return INT_MAX;
    

	return max(v[n-1]+rec_function(w,v,n-1,W-w[n-1]),rec_function(w,v,n-1,W));

}

int dp_function(int w[],int v[],int n,int W)
{
    int dp[W+1][n+1];

    for(int i=0;i<=n;i++)
    	for(int j=0;j<=W;j++)
     {
     	if(j==0 || i==0)
     		dp[j][i]=0;
     	else if(w[i-1]>j)
     		dp[j][i]=dp[j][i-1];
        else
        	dp[j][i]=max(v[i-1]+dp[j-w[i-1]][i-1],dp[j][i-1]);

     }
     return dp[W][n];

}

int main()
{
	int n,W;
	cin>>n>>W;

	int v[n];
	int w[n];

   for(int i=0;i<n;i++)
   	  cin>>v[i];

   for(int i=0;i<n;i++)
      cin>>w[i];
   cout<<dp_function(w,v,n,W);
    return 0;  	
}

