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

int main(){

  int year;
  cin>>year;

  string days[7]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};

  // Calculating first week day of year 1 Jan year
  int k=1,m=11,d=(year-1)%100,c=(year-1)/100;

  //cout<<k<<" "<<m<<" "<<d<<" "<<c<<endl;

  // Using Zeller's Formula to get first week day of any year from 1000 to 9999

  int f=k+(13*m-1)/5+d+(d/4)+(c/4)-2*c;

  if(f<0){

     while(f<0){
        f+=7;
     }
     f=f%7;
  }

  else{

    f=f%7;

  }
  cout<<days[f]<<"\n";
  
  return 0;
  
}  
