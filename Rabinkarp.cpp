/*
  Rabin Karp Algorithm
*/
#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
typedef long long ll;
typedef unsigned long long ull;
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

ull p[100005];

int main(){
    
    // Considering all lowercase letters
    // Since there are 26 letters in input alphabet
    // Prime I take is 31
    // PreCalculating all powers of p upto 10^5    
    p[0]=1;

    for(int i=1;i<100005;++i){
     
        p[i]=p[i-1]*31;
    }

    string text,pat;
    cin>>text>>pat;

    // Calculating hash of pattern
    ull hashpat=0;

    for(int i=0;i<pat.size();++i){

       hashpat+=(int)pat[i]*p[i];

    }

    ull temp=0;
    
    vector<int>alloccur;  // Stores all occurences of pat in text

    for(int i=0;i<pat.size();++i){

       temp+=(int)text[i]*p[i];     
    }
   
    if(temp==hashpat){
        
       bool check=true;
       for(int i=0;i<pat.size();++i){

          if(text[i]!=pat[i]){

             check=false;
             break;
          }

       }

       if(check==true){

         alloccur.pb(0);

       }
       
    } 

    for(int i=1;i<text.size();++i){

       temp=temp-(int)text[i-1];
       temp=temp/31; 

       temp+=(text[i+pat.size()-1]*p[pat.size()-1]);

       if(temp==hashpat){

          string str=text.substr(i,pat.size());
          if(str==pat){

             alloccur.pb(i);

          }
       }


    }

    for(int i=0;i<alloccur.size();++i){

       cout<<alloccur[i]<<"\n";

    }


	return 0;
}
