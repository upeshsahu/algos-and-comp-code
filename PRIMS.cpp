/* Author:- Mayank Pratap Singh

   2nd year, MNNIT
   
   
   PRIMS Algorithm for Undirected Graphs using C++ STL for adjacency List and priority queue.
   
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

const int N=100005;

vector<list<pair<int,int> > >adjList(N+1);
vector<list<pair<int,int> > >spanning_tree(N+1);
list<pair<int,int> >::iterator it;
int parent[N+1];
int level[N+1];
int visited[N+1];
int n,m;

priority_queue<pair<int,pair<int,int> >,vector<pair<int,pair<int,int> > >,greater<pair<int,pair<int,int> > > >pq;

void prims(int start){

    int count=0,u=start;

    for(int i=1;i<=n;++i)
    	visited[i]=0;

    while(count<n){

        it=adjList[u].begin();

        ++count;

        visited[u]=1;

        while(it!=adjList[u].end()){

            int v=it->ff;
            int w=it->ss;
            pq.push(mp(w,mp(u,v)));
            ++it;
        }

        while(!pq.empty()){

             int w=pq.top().ff;
             int v1=pq.top().ss.ff;
             int v2=pq.top().ss.ss;

             pq.pop();

             if(visited[v2]==1)
                continue;
         
             else{
 
                spanning_tree[v1].pb(mp(v2,w));      
                u=v2;
                break;

             }  // else
        }   // close to pq.empty()

    }  // close to while(count<n)

}

int main(){

    int v1,v2,w;

    scanf("%d %d",&n,&m);

    for(int i=1;i<=m;++i){
 
        scanf("%d %d %d",&v1,&v2,&w);
        adjList[v1].pb(mp(v2,w));
        adjList[v2].pb(mp(v1,w));
    }

    prims(1);  // We can start from any vertex

    printf("Printing Spanning Tree\n");
 
    for(int i=1;i<=n;++i){

        it=spanning_tree[i].begin();

      //  printf("Hello\n");

        while(it!=spanning_tree[i].end()){

           printf("%d %d %d\n",i,it->ff,it->ss);

           ++it;    

        }


    }


    return 0; 

}
