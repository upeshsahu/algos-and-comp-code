#include<bits/stdc++.h>
using namespace std;

void calculate_z(string str,int z[])
{
	int m=str.length();

	for(int i=1;i<m;i++)
	{
      int l=0,r=0;
      if(i>r)
      { l=r=i;
        while(r<m && str[r-l]==str[r])
        	r++;
        z[i]=r-l;
        r--;
      }
      else
      {  int k=l-i;
      	if(z[k]<r-i+1)
      	{
          z[i]=z[k];
      	}
      	else
      	{
          l=i;
           while(r<m && str[r-l]==str[r])
        	r++;
        z[i]=r-l;
        r--;
      	}

      }
	}
}
void z_algo(string str,string ptrr)
{ 
	string timepass=ptrr+"$"+str;
    int m=timepass.length();
	int z[m];

	calculate_z(timepass,z);

	for(int i=1;i<m;i++)
	{
		if(z[i]==ptrr.length())
			cout<<(i-ptrr.length()-1)<<endl;
	}

}

int main()
{
	string str,ptr;
	cin>>str>>ptr;

z_algo(str,ptr);
return 0;}