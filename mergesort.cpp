#include<bits/stdc++.h>
using namespace std;
int c=0;
int merge(int a[],int l,int m,int r)
{
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

}


// int merge(int a[],int l,int m,int r)
// {
// 	int n1=m-l+1;
// 	int n2=r-m;
// 	int temp[n1+n2];

//     for(int i=l;i<=r;i++)
//     	temp[i-l]=a[i];

// 	int i=0,j=m+1-l,k=l;

//     while(i<=m-l && j<=r-l)
//     {
//     	if(temp[i]<=temp[j])
//           {
//           	a[k]=temp[i];
//            i++;
//            }
//     	else
//     	  {
//     	  	a[k]=temp[j];
//     	  	j++;
//     	  }	
    	
//      k++;
    		
//     }

//     while(j<=r-l && i==m-l+1)
//     	{a[k]=temp[j];
//     		j++;
//     		k++;
//     		}
  
//     while(i<=m-l  && j==r-l+1)
//     	{a[k]=temp[i];
//     		i++;
//     		k++;
      
//     	}

// }


// int merge(int a[],int l,int m,int r)
// {
// 	int n1=m-l+1;
// 	int n2=r-m;
//     int temp[n1+n2];



// 	int i=l,j=m+1,k=0;

//     while(i<=m && j<=r)
//     {
//     	if(a[i]<=a[j])
//           {
//           	temp[k]=a[i];
//              i++;
//            }
//     	else
//     	  {
//     	  	temp[k]=a[j];
//     	  	j++;
//     	  }	
    	
//      k++;
    		
//     }

//     while(j<=r && i==m+1)
//     	{temp[k]=a[j];
//     		j++;
//     		k++;
//     		}
  
//     while(i<=m  && j==r+1)
//     	{temp[k]=a[i];
//     		i++;
//     		k++;
      
//     	}

//     	for(int i=l;i<=r;i++)
//     		a[i]=temp[i-l];

// }

int merge_sort(int a[],int l,int r)
{
	if(l<r)
	{
   int m=l+(r-l)/2;

   merge_sort(a,l,m);
   merge_sort(a,m+1,r);
   merge(a,l,m,r);
	}
}


int main()
{   int n;
	cin>>n;
     int a[n];
     for(int i=0;i<n;i++)
     	cin>>a[i];

     merge_sort(a,0,n-1);

     for(int i=0;i<n;i++)
     	cout<<a[i]<<" ";
     
	return 0;
}