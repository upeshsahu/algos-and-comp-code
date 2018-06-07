#include<bits/stdc++.h>
using namespace std;

int merge(int a[],int l,int m,int r)
{   int c=0;
	int n1=m-l+1;
	int n2=r-m;
	int L[n1];
	int R[n2];

	for(int i=0;i<n1;i++)
		L[i]=a[i+l];
	for(int i=0;i<n2;i++)
		R[i]=a[i+m+1];

	int i=0,j=0,k=l;

    while(i<n1 && j<n2)
    {
    	if(L[i]<=R[j])
          {
          	a[k]=L[i];
           i++;
           }
    	else
    	  {
    	  	c+=m-i+1;
    	  	a[k]=R[j];
    	  	j++;
    	  }	
    	
     k++;
    		
    }

    while(j<n2 && i==n1)
    	{a[k]=R[j];
    		j++;
    		k++;
    		}
  
    while(i<n1  && j==n2)
    	{a[k]=L[i];
    		i++;
    		k++;
      
    	}
        return c;

}


int merge_sort(int a[],int l,int r)
{  int c=0;
	if(l<r)
	{
   int m=l+(r-l)/2;

   c=merge_sort(a,l,m);
   c+=merge_sort(a,m+1,r);
   c+=merge(a,l,m,r);
	}
    return c;
}


int main()
{   int n;
	cin>>n;
     int a[n];
     for(int i=0;i<n;i++)
     	cin>>a[i];

     int count=merge_sort(a,0,n-1);

     for(int i=0;i<n;i++)
     	cout<<a[i]<<" ";
     cout<<endl<<count<<endl;
     
	return 0;
}