#include<bits/stdc++.h>
using namespace std;


int rec_function(string str,int x,int y)
{
	if(x==y)
       return 0;
	if(x==y-1 && str[x]==str[y])
		return 0;
		

    if(str[x]==str[y])
    	return rec_function(str,x+1,y-1);

    return 1+min(rec_function(str,x+1,y),rec_function(str,x,y-1));

}

int main()
{
  string str;
  cin>>str;
   cout<<rec_function(str,0,str.length()-1);

  return 0;
}

