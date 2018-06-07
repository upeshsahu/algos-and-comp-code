#include<bits/stdc++.h>
using namespace std;

int edit_distance(string str1,string str2,int x,int y);
int n,m;
int func_dp(string ,string);

int min(int x,int y,int z)
{
	if(x<y && x<z)
     return x;
    else if(y<x && y<z)
     return y;
    else if(z<y && z<x)
     return z;
}
int main()
{
   string str1,str2;
   cin>>str1>>str2;
   n=str1.length();
   m=str2.length();
   cout<<edit_distance(str1,str2,0,0)<<endl;;
   cout<<func_dp(str1,str2);
}


int edit_distance(string str1,string str2,int x,int y)
{
    if(x==n || y==m)
    	return 0;

   if(str1[x]==str2[y])
   {
   	return edit_distance(str1,str2,x+1,y+1);
   }
   else
   {
   	return 1+min(edit_distance(str1,str2,x+1,y),edit_distance(str1,str2,x,y+1),edit_distance(str1,str2,x+1,y+1));
   }
}



int func_dp(string str1,string str2)
{
	 int n=str1.length();
	 int m=str2.length();
    int a[n+1][m+1];

      for(int i=0;i<=n;i++)
      	for(int j=0;j<=m;j++)
      	{
           if(i==0)
           	a[i][j]=j;
           else if(j==0)
           	a[i][j]=i;
           else if(str1[i-1]==str2[j-1])
           {
             a[i][j]=a[i-1][j-1];
           }
           else
           {
           	a[i][j]=1+min(a[i-1][j],a[i][j-1],a[i-1][j-1]);
           }         

      	}
  return a[n][m];
}