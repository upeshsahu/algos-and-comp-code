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
typedef vector<int> vi;
typedef vector<pair<int,int> > vii;
typedef vector<list<int> > vl;
typedef vector<list<pair<int,int> > > vlp;
typedef vector<list<pair<int,double> > >vld;
typedef map<int,int> mi;
typedef map<string,int> ms;
typedef set<int> si;

int parent[MAX],n,m,size[MAX];

void initialize(){
   // Initially every node is a parent of itself
   for(int i=0;i<MAX;++i){
      parent[i]=i;
      size[i]=1;   // Initially size of each component is 1
   }
}

// Since we have used Union By Rank
// Complexity of root() changes from n to logn

int root(int x){
	
   // Using path compression
   while(parent[x]!=x){

     parent[x]=parent[parent[x]]; // grand pa
     x=parent[x];   


   }
   
   return x;

}

void union(int x,int y){
	 
   int p=root(x);
   int q=root(y);
	 
   if(p==q) return;
	
   if(size[p]<size[q]){

      parent[p]=parent[q];
      size[q]+=size[p];

   }

   else{

      parent[q]=parent[p];
      size[p]+=size[q];
 
   }
   
}

int main(){
	//lets rock
	return 0;
}
