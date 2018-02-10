/*
   Mayank Pratap Singh
   MNNIT, 2nd year IT
   AC ho.
*/
#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

#define MOD 1000000007

typedef long long ll;
typedef long double ld;

const int INF=(int)(1e9);
const ll INF64=(ll)(1e18);
const ld EPS=1e-9;
const ld PI=3.1415926535897932384626433832795;


typedef vector<int> vi;
typedef vector<pair<int,int> > vii;
typedef vector<list<int> > vl;
typedef vector<list<pair<int,int> > > vlp;
typedef map<int,int> mi;
typedef map<string,int> ms;
typedef set<int> si;

int L[1000],countLis[1000];

int lis(int arr[],int n){

   for(int i=0;i<n;++i){

     L[i]=1;
     countLis[i]=1;

     int maxi=0;

     for(int j=i-1;j>=0;--j){

        if(arr[j]<arr[i]){

           if(L[j]>maxi){
             maxi=L[j];
             countLis[i]=countLis[j];

           }
           else if(L[j]==maxi){

            countLis[i]+=countLis[j];

           }
        }
     }

     L[i]+=maxi;

   }

   int maxi=0,pos,count=0;

   for(int i=0;i<n;++i){

      if(L[i]>maxi){

         count=countLis[i];
         maxi=L[i];

      }

      else if(L[i]==maxi){

        count+=countLis[i];

      }
    //  cout<<L[i]<<" "<<countLis[i]<<"\n";

   }

   return count;


}

int main(){

 int t;

 cin>>t;

 while(t--){

    int n,arr[1000],x;
    memset(L,0,sizeof(L));
    memset(countLis,0,sizeof(countLis));

    cin>>n;

    for(int i=0;i<n;++i)
        cin>>arr[i];

     cout<<lis(arr,n)<<"\n";

 }

   return 0;
}
