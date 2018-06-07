#include<bits/stdc++.h>
using namespace std;
int function_recursion(int x,int y,int a[]);

int main()
{
  int n;
   cin>>n;
   int a[n];

   for(int i=0;i<n;i++)
   	cin>>a[i];

   cout<<function_recursion(0,n-1,a);
}

int function_recursion(int x,int y,int a[])
{
    if(x==y)
    	return a[x];
    if(x+1==y)
    	return max(a[x],a[y]);

    return max(a[x]+min(function_recursion(x+1,y-1,a),function_recursion(x+2,y,a)),
    	       a[y]+min(function_recursion(x+1,y-1,a),function_recursion(x,y-2,a)) );
}