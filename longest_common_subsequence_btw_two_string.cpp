#include<bits/stdc++.h>
using namespace std;
vector<int> lcs;
int recursivefunction(int x,int y,string str1,string str2);
int dp_lcs(string str1,string str2);
int main()
{

	string str1,str2;
	cin>>str1;
	cin>>str2;
    int n,m;
    n=str1.length();
    m=str2.length();

   // int x=recursivefunction(n-1,m-1,str1,str2);
    int y=dp_lcs(str1,str2);
    cout<<y<<endl;

    // for(int i=lcs.size()-1;i>=0;i--)
    // 	cout<<str1[lcs[i]];
	return 0;
}

int recursivefunction(int x,int y,string str1,string str2)
{

    if(x<0 || y<0)
    	return 0;
    cout<<str1[x]<<" "<<str2[y]<<endl;
  if(str1[x]==str2[y])
  	return 1+recursivefunction(x-1,y-1,str1,str2);
  else
  	return max(recursivefunction(x,y-1,str1,str2),recursivefunction(x-1,y,str1,str2));

}

int dp_lcs(string str1,string str2)
{
     int n=str1.length();
     int m=str2.length();
     int l[n+1][m+1];

     for(int i=0;i<=n;i++)
     {
     	for(int j=0;j<=m;j++)
     	{

           if(i==0 || j==0)
           {
           	l[i][j]=0;
           }
           else if(str1[i-1]==str2[j-1])
           {
           	 
           	l[i][j]=1+l[i-1][j-1];
           	
           }
           else
           {
           	l[i][j]=max(l[i][j-1],l[i-1][j]);
           }


     	}
     }


   int index = l[n][m];
   char lcs[index+1];
   lcs[index] = ' '; // Set the terminating character
 

   int i = n, j = m;
   while (i > 0 && j > 0)
   {
      
      if (str1[i-1] == str2[j-1])
      {
          lcs[index-1] = str1[i-1]; // Put current character in result
          i--; j--; index--;     // reduce values of i, j and index
      }
 
      // If not same, then find the larger of two and
      // go in the direction of larger value
      else if (l[i-1][j] > l[i][j-1])
         i--;
      else
         j--;
   }
   cout<< lcs<<endl;
  return l[n][m];
}