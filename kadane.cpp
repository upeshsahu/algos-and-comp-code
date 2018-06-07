#include<bits/stdc++.h>
using namespace std;

int main()
{
   int n;
   cin>>n;
   int a[n];

   for(int i=0;i<n;i++)
   	   cin>>a[i];

   int max_ending=0,
   max_so_far=INT_MIN;

   for(int i=0;i<n;i++)
   {
   	max_ending+=a[i];
    
       	if(max_ending>max_so_far)
   		 max_so_far=max_ending;

   	if(max_ending<0)
   		max_ending=0;


   }	

   //very effective for negative numbers for nagatibe numbers

    int max_ending=a[0],
   max_so_far=a[0];

   for(int i=0;i<n;i++)
   {
   	   max_ending=max(max_ending+a[i],a[i]);
   	   max_so_far=max(max_so_far,max_ending);
   }

   cout<<max_so_far<<endl;

	return 0;
}