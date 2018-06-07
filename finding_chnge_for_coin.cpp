#include<bits/stdc++.h>
using namespace std;
int dp_function(int s[],int n,int m);

/* To count total number solutions, we can divide all set solutions in two sets.
1) Solutions that do not contain mth coin (or Sm).
2) Solutions that contain at least one Sm.
Let count(S[], m, n) be the function to count the number of solutions, then it can be written as sum of count(S[], m-1, n) and count(S[], m, n-Sm).*/
int m,n;
int rec_function(int s[],int sum,int m);
int main()
{
 
   cin>>n>>m;
   int s[m];

   for(int i=0;i<m;i++)
     cin>>s[i];
   
     cout<<rec_function(s,n,m)<<endl;
     cout<<dp_function(s,n,m)<<endl;

	return 0;
}


int rec_function(int s[],int sum,int m)
{
		if(sum<0)
		return 0;


	if(sum==0)
		return 1;

   if(m<=0 && n>=1)
   	return 0;
  

  return rec_function(s,sum,m-1)+rec_function(s,sum-s[m-1],m);
}


int dp_function(int s[],int n,int m)
{
     int dp[n+1][m];

     for(int i=0;i<m;i++)
     	dp[0][i]=1;

     for(int i=1;i<=n;i++)
     	for(int j=0;j<m;j++)
     	{
     		int x=(i-s[j]>=0)?(dp[i-s[j]][j]):(0);
     		int y=j>=1?dp[i][j-1]:0;
     		dp[i][j]=x+y;
     	}

     	return dp[n][m-1];
}