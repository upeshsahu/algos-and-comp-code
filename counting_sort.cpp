#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int a[n];

	int hash[1000001];

	for(int i=1;i<=1000000;i++) hash[i]=0;

	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		hash[x]++;
	}
    int d=0;
    // for(int i=0;i<=1000000;i++)
    // {
    // 	if(hash[i]!=0)
    //       {
    //       	hash[i]=hash[i]+d;
    //       	d=hash[i];

    //       }
    // }

    for(int i=0;i<=1000000;i++)
    {
    	while(hash[i]!=0)
    	{
    		cout<<i<<" ";
    	hash[i]--;
    	}
    }

	return 0;
}