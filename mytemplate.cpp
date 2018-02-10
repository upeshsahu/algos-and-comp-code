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
typedef vector<list<pair<int,double> > >vld;
typedef map<int,int> mi;
typedef map<string,int> ms;
typedef set<int> si;

const int N=1000000;

/******** Make your own template ***************/

/* ********* Compare Function for sorting pair of coordinates ************    */

bool compare(const pair<int,int>&i,const pair<int,int>&j){

    if(i.second==j.second)         // Decreasing order according to first coordinate
      return i.first>j.first;

    return i.second<j.second;   // Increasing order according to second coordinate

}


/******  Modular Multiplication Function for Long integes  ********/

long long mulmod(long long a,long long b,long long c){

    long long x=0,y=a%c;
    while(b>0){

        if(b%2==1){

            x=(x+y)%c;

        }

        y=(y*2)%c;
        b/=2;

    }
    return x%c;
}

/****** Modular Exponentiation Function For Long Integers  ******/

long long modulo(long long a,long long b,long long c){

     long long x=1,y=a;

     while(b>0){

         if(b%2==1){

             x=mulmod(x,y,c);
         }
         y=mulmod(y,y,c);
         b/=2;
     }

     return x%c;

}

/***** Sieve Of Eratosthenes is a Bitch *******/

bool prime[2000005];

void sieve(){

  memset(prime,true,sizeof(prime));

  for(int p=2;p*p<=N;p++){

     if(prime[p]==true){

        for(int i=p*2;i<=N;i+=p)
          prime[i]=false;
     }

  }
}

int main(){





   return 0;
}
