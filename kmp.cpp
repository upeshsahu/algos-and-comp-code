#include<bits/stdc++.h>
using namespace std;

void calculating_lps(string patt,int lps[])
{
   int i=1;
   int l=0;
   lps[0]=0;
   while(i<patt.length())
   {
   	  if(patt[i]==patt[l])
   	  {
   	  	l++;
   	  	lps[i]=l;
   	  	i++;
   	  }
   	  else
   	  {
   	  	if(l!=0)
   	  	{
         l=lps[l-1];
         i++;
   	  	}
   	  	else
   	  	{
   	  		lps[i]=l;
   	  		i++;
   	  	}

   	  }
   }

}

int kmp(string str,string patt)
{   int l=str.length();
	int m=patt.length();
	int lps[m];
	calculating_lps(patt,lps);
	int count=0;
	int i=0,j=0;
	while(i<l)
	{
		if(patt[j]==str[i])
		{
           i++;
           j++;
		}
	   
	    if(j==m)
		{
		    		count++;
		    		j=lps[j-1];
		}
		else if(i<l && patt[j]!=str[i])
		{  

			if(j!=0)
              j=lps[j-1];
		    else
		       i++;	
		}
	}
	return count;
}



int main()
{
  string str,patt;
  cin>>str>>patt;

   cout<<kmp(str,patt);
  


return 0;
}