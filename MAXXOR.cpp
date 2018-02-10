// Given an array of integers we have to find two elements whose XOR is maximum.
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
typedef vector<string> vs;
typedef vector<pair<int,int> > vii;
typedef vector<list<int> > vl;
typedef vector<list<pair<int,int> > > vlp;
typedef map<int,int> mi;
typedef map<string,int> ms;
typedef set<int> si;
typedef set<string> ss;

string convertToBinary(int num){

   string temp="";

   while(num!=0){

      int b=num%2;

      if(b==0)
        temp='0'+temp;
      else
         temp='1'+temp;

      num/=2;
   }

   return temp;

}

struct trie{

    int next[2];
    int flag;

}node[10005];

int allocated,maxxor=0;

void insert(string s){

      // printf("%d\n",current);
      int current = 0;  //so root node is node[0]
    	for(int i = 0; i < s.length(); i++){

		      if(node[current].next[s[i]-'0'] == 0) { //no link --> so allocate it
			      node[current].next[s[i]-'0'] = allocated;
			      current = allocated;
			      allocated++;
		      }
		      else current = node[current].next[s[i]-'0'];  //already present --> so just update current


	   	    if(i == s.length()-1) {
		     	   node[current].flag = 1;
  		    }

      }

}

void solve(string s){

   int current=0,temp=0,power=s.length()-1;

   for(int i=0;i<s.length();++i){

      if(s[i]=='0'){

          if(node[current].next[1]!=0){

              temp+=pow(2,power-i);
              current=node[current].next[1];

          }

          else
             current=node[current].next[0];

      }

      else{

        if(node[current].next[0]!=0){

            temp+=pow(2,power-i);
            current=node[current].next[0];

        }

        else
           current=node[current].next[1];

      }


   }

   if(temp>maxxor)
      maxxor=temp;


}

int main(){

   int n;
   cin>>n;

   allocated=1;
   memset(node,0,sizeof node);

   int arr[10005];


   for(int i=0;i<n;++i)
     cin>>arr[i];

   vs binary(10005);

   int maxlen=0;

   for(int i=0;i<n;++i){

       string temp=convertToBinary(arr[i]);
       binary[i]=temp;
       if((int)temp.size()>maxlen){

           maxlen=(int)temp.size();
       }

   }

   for(int i=0;i<n;++i){

      int diff=maxlen-(int)binary[i].size();

      for(int j=0;j<diff;++j){

         binary[i]='0'+binary[i];

      }
   }



   for(int i=0;i<n;++i){

      cout<<binary[i]<<"\n";

      if(i==0)
        insert(binary[i]);
      else{

        solve(binary[i]);  // First take XOR with exisiting numbers in trie
        insert(binary[i]);
      }

   }

   cout<<maxxor<<"\n";



   return 0;
}
