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
const ld EPS=1e-12;
const ld PI=3.1415926535897932384626433832795;
typedef vector<int> vi;
typedef vector<pair<int,int> > vii;
typedef vector<list<int> > vl;
typedef vector<list<pair<int,int> > > vlp;
typedef vector<list<pair<int,double> > >vld;
typedef map<int,int> mi;
typedef map<string,int> ms;
typedef set<int> si;

vl adj(100005);
int disc[100005]; // Discovery
int low[100005]; // Lowest discovery time that is either in dfs subtree rooted at v or by backedge
bool ap[100005]; // Tells whether a vertex is articulation point or not
int n,m;
int parent[100005];
int cnt;

/*********************************************************************
  Low(v) is lowest discovery time that is either in DFS subtree rooted
  at v(including v) or connected to a vertex in that subtree by a
  back edge.

  Low(v)=min(Low(w)|w is children of v) or disc(x)|{v,x} is a backedge from v

  A vertex u can be an articulation point if it satisfies one of two condition:-

  1) Its a root and has more than 2 children.
  2) It is not a root and has some children's low[*it]>=disc[u]

  An edge (u,v) is an articulation edge or a bridge if
     low[v]>disc[u]


**********************************************************************/

void dfs(int u){

   disc[u]=++cnt;
   low[u]=disc[u];
   list<int>::iterator it;

   int children=0; // Count of children of u

   for(it=adj[u].begin();it!=adj[u].end();++it){

      if(parent[*it]==-1){
         parent[*it]=u;
         ++children;
         dfs(*it);
         low[u]=min(low[u],low[*it]);

      }

      else   // In case of back edge we have to update u.
        if(parent[u]!=*it)
           low[u]=min(low[u],disc[*it]);
   }
}

int main(){

   cin>>n>>m;
   int x,y;

   set<pair<int,int> >edges;
   set<pair<int,int> >::iterator it;

   for(int i=1;i<=m;++i){

      cin>>x>>y;
      adj[x].pb(y);
      adj[y].pb(x);

      edges.insert(mp(x,y));

   }

   for(int i=1;i<=100000;++i)
     disc[i]=-1;
   for(int i=1;i<=100000;++i)
     ap[i]=false;

    for(int i=1;i<=100000;++i)
       parent[i]=-1;

    parent[1]=0;
    cnt=0;
    dfs(1);

    for(it=edges.begin();it!=edges.end();++it){

       int u=it->ff,v=it->ss;
       if(low[v]>disc[u])
          cout<<"Edge "<<u<<" "<<v<<" is a Bridge\n";
    }



   return 0;
}
