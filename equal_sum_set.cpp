#include<bits/stdc++.h>
using namespace std;

double function_rec(int n,int k,int a[]);
int main()
{
    int n,k;
    cin>>n>>k;
    int a[n];

    for(int i=0;i<n;i++)
        cin>>a[i];

    cout<<function_rec(n,k,a);


    return 0;
}



double function_rec(int n,int k,int a[])
{   

    if(k==1)
    {  double s=0;
        for(int i=n-1;i>=0;i--)
        {
            s+=a[i];
        }
        
        return s/n;
    }

     double res=0,sum=0;
       for(int i=n-1;i>0;i--)
       {
          sum+=a[i];
        // cout<<i<<" "<<k-1<<endl;
         res= max(function_rec(i,k-1,a)+sum/(n-i),res);
       }
  return res;


}







// // A simple solution is to use recursion. An efficient solution is memorization where we keep the largest score upto k i.e. for 1, 2, 3… upto k;

// // Let memo[i][k] be the best score portioning A[i..n-1] into at most K parts. In the first group, we partition A[i..n-1] into A[i..j-1] and A[j..n-1], then our candidate partition has score average(i, j) + score(j, k-1)), where average(i, j) = (A[i] + A[i+1] + … + A[j-1]) / (j – i). We take the highest score of these.

// // In total, our recursion in the general case is :
// // memo[n][k] = max(memo[n][k], score(memo, i, A, k-1) + average(i, j))
// // for all i from n-1 to 1 .

#define MAX 1000
 
double memo[MAX][MAX];
 
// bottom up approach to calculate score
double score(int n, vector<int>& A, int k)
{
    if (memo[n][k] > 0)
        return memo[n][k];
    double sum = 0;
    for (int i = n - 1; i > 0; i--) {
        sum += A[i];
        memo[n][k] = max(memo[n][k], score(i, A, k - 1) +
                                          sum / (n - i));


                                      |------n-1,k-2
           |------n-1,k-1----|-n=n-i--|------
           |------n-2,k-1             |------
           |------n-3,k-1
           |------ | 
    n,k----|       |
           |       |
           |------1,k-1 
    }
    return memo[n][k];
}
 
double largestSumOfAverages(vector<int>& A, int K)
{
    int n = A.size();
    double sum = 0;
    memset(memo, 0.0, sizeof(memo));
    for (int i = 0; i < n; i++) {
        sum += A[i];
 
        // storing averages from starting to each i ; 
 //base case here we are storing the sum of 1 ,2,3,4,5.....all element and this is utilize as base case for dp
        memo[i + 1][1] = sum / (i + 1);
    }
    return score(n, A, K);
}
 
int main()
{   int n,x;
    cin>>n;
    vector<int> A;
    for(int i=0;i<n;i++)
       {
        cin>>x;
        A.push_back(x);
       } 
    int K = 3; // atmost partioning size
    cout << largestSumOfAverages(A, K) << endl;

   for(int i=0;i<=n;i++)
    {for(int j=0;j<=K;j++)
        cout<<memo[i][j]<<" ";
    cout<<endl;}
    return 0;
}
