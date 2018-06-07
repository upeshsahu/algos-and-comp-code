#include<bits/stdc++.h>
using namespace std;
int function_rec(string ,int,int);
int function_dp(string);

int main()
{
   string str;
   cin>>str;
   int n=str.length();

   cout<<function_rec(str,0,n-1);
   cout<<function_dp(str);

}

int function_rec(string str,int x,int y)
{
   if(x>y)
   	return INT_MAX;
   if(x==y )
   	return 0;
   if(x==y-1 && str[x]==str[y])
   	return 0;
   if(x==y-1 && str[x]!=str[y])
   	return 1;


  if(str[x]==str[y])
  	 return function_rec(str,x+1,y-1);
  else
  	 return 1+min(function_rec(str,x+1,y),function_rec(str,x,y-1));

}

int function_dp(string str)
{
	int n=str.length();
	int dp[n][n];
     for(int i=0;i<n;i++)
     	for(int j=0;j<n;j++)
     		dp[i][j]=0;

    for(int gap=1;gap<n;gap++)
	  for(int i=0, j=gap;i<n,j<n;j++,i++)
        {
        	
        	dp[i][j]=(str[i]==str[j])?(dp[i+1][j-1]):(min(dp[i][j-1],dp[i+1][j])+1);
        }
        return dp[0][n-1];

}