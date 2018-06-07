


int main()
{
    int n;
    cin>>n;
    int a[n];

    for(int i=0;i<n;i++)
    	cin>>a[i];

    int lo=0;
    int hi=n-1;

    while(lo<=hi)
    {
    	int mid=(lo+hi)/2;
         
         if(hi<lo)
         	return a[0];
         else if(hi==lo)
         	return a[lo];

         else if(a[mid]<a[mid-1]  && mid>lo)
         	  return a[mid];
         else if(a[mid]>a[mid+1] && hi>mid)
         	return a[mid+1];
         else if(a[mid]<a[high])
             {
             	hi=mid-1;
             }
         else 
              lo=mid+1;    

    }

	return 0;
}