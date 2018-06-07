#include<bits/stdc++.h>
using namespace std;
int rec_function(int ,int ,string);
int dp_lrs(string str);
int main()
{
    string str;
    cin>>str;
    int n=str.length();

      //cout<<rec_function(n,n,str);
        cout<<dp_lrs(str);
	return 0;
}

int rec_function(int x,int y,string str)
{
    if(x<0 || y<0)
        return 0;
     if(str[x]==str[y] && x!=y)
     {
     	return 1+rec_function(x-1,y-1,str);
     }
     else
     	return max(rec_function(x-1,y,str),rec_function(x,y-1,str));
}

int dp_lrs(string str)
{
	int n=str.length();
	int l[n+1][n+1];

	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++)
		{
               
           if(i==0 || j==0)
           	l[i][j]=0;
           else if(str[i-1]==str[j-1] && i!=j)
           {
           	l[i][j]=1+l[i-1][j-1];
           }
           else
           {
           	l[i][j]=max(l[i][j-1],l[i-1][j]);
           }
		}
	

   // for(int i=0;i<=n;i++)
   // 	{for(int j=0;j<=n;j++)
   // 		cout<<l[i][j];
   // 	cout<<endl;}
     int i=n,j=n;
     while(j>0 && i>0)
     {

     	if( (l[i][j]==l[i-1][j-1]+1) /*&& l[i-1][j]==l[i][j] && l[i][j]==l[i][j-1]*/)
     	{
     		cout<<str[i-1];
     	    i--;
     		j--;
     	}
     	else if(l[i-1][j]==l[i][j] )
        {
                  i--;
        }
        else
        {
        	j--;
        }
     }

		return l[n][n];
}