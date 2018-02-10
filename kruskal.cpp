/* Author:- Mayank Pratap Singh

   2nd year, MNNIT   
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
typedef map<int,int> mi;
typedef map<string,int> ms;
typedef set<int> si;

const int MAx=1e5+5;

int parent[MAX],n,m,size[MAX];
vector<pair<ll,pair<int,int> > >adjList;

void initialize(){

  // Initially every node is a parent of itself
  for(int i=0;i<MAX;++i){
     parent[i]=i;
     size[i]=1;  // Initially size of each component is 1
  }

}

// Since we have used Union By Rank
 // Complexity of root() changes from n to logn

int root(int x){

   // Now using path compression.

   while(parent[x]!=x){

      parent[x]=parent[parent[x]]; // Grandpa
      x=parent[x];

   }

   return x;

}

// I have used Union By Rank

void union(int x,int y){

  int p=root(x);
  int q=root(y);

  if(size[p]<size[q]){

     parent[p]=parent[q];
     size[q]+=size[p];
  }

  else{

     parent[q]=parent[p];
     size[p]+=size[q];

  }


}

ll kruskal(vector<pair<ll,pair<int,int> > >adjList){
 
    int x,y;
    
    ll cost=0,minCost=0;
    
    for(int i=0;i<m;++i){
        
        // Selecting edges one by one in increasing order
        x=adjList[i].ss.ff;
        y=adjList[i].ss.ss;
        
        cost=adjList[i].ff;
        
        if(root(x)!=root(y)){
         
          minCost+=cost;
          union1(x,y);
            
        }
        
    
    }

    return minCost;

}

int main(){
   
   int x,y;
   
   ll weight,cost,minCost;
   
   initialize();
  
   printf("Enter number of vertices and number of edges\n");
   scanf("%d %d",&n,&m);
   
   for(int i=0;i<m;++i){
    
       cin>>x>>y>>weight;
       adjList.pb(mp(weight,mp(x,y)));

   }
   
   sort(adjList.begin(),adjList.end());
   
   minCost=kruskal(adjList);
   
   printf("%d\n",minCost);

   return 0;
}

