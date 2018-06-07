#include<bits/stdc++.h>
using namespace std;

int main()
{
  string str;
  cin>>str;
  int n=str.length();
  
  int v[27];
  vector<int> rec;
  
  for(int i=0;i<=26;i++)
  	  v[i]=-1;
  int l=0;
  int c=0;
  
  for(int i=0;i<n;i++)
  {
     if(v[str[i]-'a']==-1)
     {
     	v[str[i]-'a']=1;
     	l++;
     }
     else
     {  l++;
       for(int j=i-1;j>=0;j--)
       {
       	if(str[i]==str[j])
       		{   
       			l=l+c-(j+1);
       			cout<<l<<" "<<endl;
       			c=j+1;
       			break;
             }
       }
     }
   }



	return 0;
}