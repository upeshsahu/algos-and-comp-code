#include <bits/stdc++.h>
using namespace std;
 
// Utility function to get the maximum of two and three integers
int max(int a, int b) { return (a > b)? a : b;}
int max(int a, int b, int c) { return max(a, max(b, c));}
 
// The main function that returns maximum product obtainable
// from a rope of length n
int maxProd(int n)
{
    // Base cases
    if (n == 0 || n == 1) return 0;
 
    // Make a cut at different places and take the maximum of all
    //cout<<"n is "<<n<<endl;;
    int max_val = 0;
    for (int i = 1; i < n; i++)
      {
      //  cout<<"loop is called with i ="<<i<<"and n="<<n<<endl;
        max_val = max(max_val, i*(n-i), maxProd(n-i)*i);
      }
    // Return the maximum of all values
    return max_val;
}
 
int function(int l)
{
    if(l==0)
        return 1;
    if(l<0)
       return 0;
    int res=1;

    if(l==1)
        return 1;
    for(int i=1;i<l;i++)
    {
      res=max(res,i*function(l-i),i*(l-i));
    }

    return res;
}


/* Driver program to test above functions */
int main()
{   int n;
    cin>>n;
    cout << "Maximum Product is " << function(n)<<endl;
    cout << "Maximum Product is " << maxProd(n);
    return 0;
}