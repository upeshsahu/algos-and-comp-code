#include<bits/stdc++.h>
using namespace std;
int costcal[100][100];
int main()
{
    int n,m;
    cin>>n>>m;
   
    for(int i=0;i<n;i++)
    	for(int j=0;j<m;j++)
    		cin>>costcal[i][j];
	return 0;
}

int dp_function(int n,int m)
{
    int b1[n+2][m+2];
    int b2[n+2][m+2];
    int g1[n+2][m+2];
    int g2[n+2][m+2];


    for(int i=0;i<=n;i++)
    	for(int j=0;j<=m;j++)
    	{
    		if(i==0 || j==0)
    			b1[i][j]=0;
    		else
    			b1[i][j]=max(b1[i-1][j],b1[i][j-1])+costcal[i-1][j-1];
    	}


   
    for(int i=n+1;i>=1;i--)
    	for(int j=m+1;j>=1;j--)
    	{
    		if(i==n+1 || j==m+1)
    			b2[i][j]=0;
    		else
    			b2[i][j]=max(b2[i+1][j],b2[i][j+1])+costcal[i-1][j-1];
    	}

    for(int i=n+1;i>=0;i--)
      for(int j=0;j<=m;j++)
        {
        	if(i==n+1 || j==0)
        		g1[i][j]=0;
        	else
        		g1[i][j]=max(g1[i+1][j],g1[i][j-1])+costcal[i-1][j-1];
        }	

    for(int i=0;i<=n;i++)
      for(int j=m+1;j>=0;j--)
        {
        	if(i==0 || j==m+1)
        		g2[i][j]=0;
        	else
        		g2[i][j]=max(g2[i-1][j],g2[i][j+1])+costcal[i-1][j-1];
        }	
         int res=INT_MIN;
         int op1,op2;
        for(int i=2;i<=n-2;i++)
        	for(int j=2;j<=m-2;j++)
        	{
        	 op1=b1[i-1][j]+b2[i+1][j]+g1[i][j-1]+g2[i][j+1];
        	 op2=b1[i][j-1]+b2[i][j+1]+g1[i-1][j]+g2[i+1][j];
        	res=max(res,op1+op2);
        	}
  return res;
}
