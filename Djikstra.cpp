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

const int N=100005;

vector<list<pair<int,int> > >adjList(N+1);    // Always give size of adjList
list<pair<int,int> >::iterator it;
int parent[N+1];
int level[N+1];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >pq; // priority queue    //Contains vertex and its distance

//  greater<pair<int,int> > is used to change std::priority queue to min heap

pair<int,int>p;    

int d[N+1];    //  distances from starting point

int n,m;

void dijkstra(int start){
    
    for(int i=1;i<=n;++i)
        d[i]=INF;

    d[start]=0;
    
    
 
    // Preparing my priority queue

    for(int i=1;i<=n;++i){
 
       pq.push(mp(d[i],i));
    }
    
   
    int u,v,w;
    
    int count=n;
    
    while(count--){
    
         int u=pq.top().ss;   //  get value of element ,leave its weight
         
      
         
           pq.pop();
         
       
    
          it=adjList[u].begin();
         
      
    
        
    
         while(it!=adjList[u].end()){
         
             int v=it->ff;
             int w=it->ss;
              
          
        
             if(d[u]+w<d[v]){
             
                d[v]=d[u]+w;
                pq.push(mp(d[v],v));
             
             }
             
          
             
             ++it;
        
         }
        
         
   
        
    }

}

int main(){
 
     int v1,v2,w;

     scanf("%d %d",&n,&m);

     for(int i=1;i<=m;++i){

          
      
           scanf("%d %d %d",&v1,&v2,&w);
           
           adjList[v1].pb(mp(v2,w));    
           
    
 
     }

     dijkstra(1);  // start vertex goes in dijkstra

     for(int i=1;i<=n;++i)
         printf("%d\n",d[i]);

     return 0;
}
