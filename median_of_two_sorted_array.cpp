#include<bits/stdc++.h>
using namespace std;


int median(int a[],int s)
{	
	
	if(s&1)
		return (a[s/2]);
	else
		return (a[s/2]+a[s/2-1])/2;		
}

int median_function(int a[],int b[],int n)
{

    int m1=median(a,n);
    int m2=median(b,n);
 	
     if(n==-1)
     	return -1;

 	  if (n == 1)
        return (a[0] + b[0])/2;

 	 if(m1==m2)
 	 	return m1;


 	 if(n==2)
 	 	 return (max(a[0], b[0]) + min(a[1],b[1])) / 2;
 	 

       if(m1>m2)
       {  
       	if(n&1)
         return median_function(a,b+n/2,n-n/2);
          	return median_function(a,b+n/2-1,n-n/2+1);
       }
       else
       {
       	 if(n&1)
         return median_function(a+n/2,b,n-n/2);
          	return median_function(a+n/2-1,b,n-n/2+1);
        
       }
	

}



int main()
 {   
 	int n;
 	cin>>n;
 	int a[n],b[n];

 	for(int i=0;i<n;i++)
 		cin>>a[i];
 	for(int j=0;j<n;j++)
 		cin>>b[j];
    cout<<median_function(a,b,n)<<endl;
  
	return 0;
}
