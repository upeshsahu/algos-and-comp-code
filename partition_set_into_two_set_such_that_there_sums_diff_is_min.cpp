#include<bits/stdc++.h>
using namespace std;
int sum;
int rec_function(int a[],int n,int sum1)
{
	
   if(n==0)
   	return abs(sum -2*sum1);


   return min(rec_function(a,n-1,sum1-a[n-1]),rec_function(a,n-1,sum1));


}


int function_dp(int a[],int n,int sum)
{
  int dp[sum+1][n+1];

  for(int i=0;i<=n;i++)
  	for(int j=0;j<=sum;j++)
  	{   
  		if(j==0 && i!=0)
  			dp[j][i]=0;
  		else if(i==0)
  			dp[j][i]=1;
  		else if(j<a[i-1])
  			dp[j][i]=dp[j][i-1];
  		else 
  			dp[j][i]=dp[j][i-1]|dp[j-a[i-1]][i-1];
  		
  	}


  	int diff = INT_MAX;
     
    // Find the largest j such that dp[n][j]
    // is true where j loops from sum/2 t0 0
    for (int j=sum/2; j>=0; j--)
    {
        // Find the 
        if (dp[j][n] == true)
        {
            diff = sum-2*j;
            break;
        }
    }
    return diff;

}

int main()
{
	int n;
	cin>>n;
	int a[n];
	sum=0;
	for(int i=0;i<n;i++)
		{
			cin>>a[i];
          sum+=a[i];
		}

	cout<<function_dp(a,n,sum);	

}

