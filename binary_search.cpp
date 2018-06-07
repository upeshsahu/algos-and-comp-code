#include<bits/stdc++.h>
using namespace std;



int main()
{
   int n,x;
   cin>>n>>x;
   int a[n];
   for(int i=0;i<n;i++)
   	   cin>>a[i];

   	int lo=0;
   	int hi=n-1;

   	
    int ans=-1;
   	while(lo<=hi)
   	{
   	  int mid=(hi-lo)/2+lo;
   	  if(x==a[mid])
   	  {
          ans=mid;
          break;
   	  }
   	  else if(a[mid]<x)
   	  {
          lo=mid+1;
   	  }	
   	  else
      {
          hi=mid-1;
      }
   	}
   	cout<<ans;
return 0;
}