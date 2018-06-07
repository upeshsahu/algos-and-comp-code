#include<bits/stdc++.h>
using namespace std;
int function(int ,int);
int main()
{
   int n;
   cin>>n;
   cout<<function(n,3);
return 0;
}


// int function(int n,sum){

// 	if(sum==0)
// 		return 1;

// 	if(sum<0)
// 		return 0;

//     if(n<=0 && sum>=1)
//     	return 0;



// 	return function(n-1,sum)+function(n,sum-n);
// }

int function(int sum,int n)
{
     if(sum==0)
     	return 1;
     if(sum <0 || n<=0)
     	return 0;
	int res=0;
    for(int i=1;i<=n;i++)
    {
    	res+=function(sum-i,n);
    }
    return res;
}

int dp_function(int n)
{

  int count[n+1];
  count[0]=1,count[1]=1,count[2]=2;
  for(int i=3;i<=n;i++)
  	count[i]=count[i-1]+count[i-2]+count[i-3];

  return count[n];
}