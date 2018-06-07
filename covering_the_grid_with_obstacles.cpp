#include<bits/stdc++.h>
using namespace std;

const int n,m;
int dp_function(int grid[n][m],int n,int m)
{
	int dp[n][m];


	for(int i=1;i<n;i++)
	{
		dp[0][i]=dp[0][i-1]+1;
		
		if(grid[0][i]==-1)
		{
          for(int j=i;j<n;j++)
          	dp[0][j]=INT_MAX;

          break;
		}
		
	}
	for(int i=1;i<m;i++)
	{
		dp[i][0]=dp[i-1][0]+1;
		
		if(grid[i][0]==-1)
		{
          for(int j=i;j<m;j++)
          	dp[j][0]=INT_MAX;

          break;
		}
		
	}



   for(int i=1;i<n;i++)
   	for(int j=1;j<m;j++)
   	{
        if(grid[i][j]==-1)
           dp[i][j]=INT_MAX;
        else
   		dp[i][j]=1+min(dp[i][j-1],dp[i-1][j]);
   	}
  return dp[n][m];
}

int main()
{
   
   cin>>n>>m;
   for(int i=0;i<n;i++)
   	for(int j=0;j<m;j++)
   		cin>>grid[i][j];

    cout<<dp_function(grid,n,m)<<endl;
    return 0;
}