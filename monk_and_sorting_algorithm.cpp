#include<bits/stdc++.h>
#define ll long long int 
using namespace  std;

int main()
{   
	int n;
	cin>>n;
    ll a[n],b[n];

    for(int i=0;i<n;i++)
    	cin>>a[i];
  ll k=1;
  ll j=100000;
  ll sum=-1;
   while(sum!=0)
   {
   	sum=0;
   	pair<ll,int> p[n];
   	ll num=0;
    for(int i=0;i<n;i++)
     {
     	num=( ( a[i]/k) %j  );
     	p[i]=make_pair(num,i);
      sum+=num;
     }
     sort(p,p+n);

    if(sum==0)
    	break;
     for(int i=0;i<n;i++)
     {
         b[i]=a[p[i].second];
     }

     for(int i=0;i<n;i++)
     	a[i]=b[i];

       for(int i=0;i<n;i++)
   	 cout<<a[i]<<" "; 
   	cout<<endl;
   k*=100000;
   j*=100000;
   }    
	return 0;
}