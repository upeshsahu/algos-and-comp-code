/*
   Mayank Pratap Singh
   MNNIT, 2nd year IT
   sudo ac
*/ 
#include<bits/stdc++.h>
#include<string.h>
#include<cstring>   
#include<ctype.h>   
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

vl adjList(100005);
vl tadjList(100005);  // transpose adjacency list -- transpose graph
bool visited[100005];
vl SCCs(100005);
stack<int>Stack;

int n,m;

vector<int>components[100005];
int compCount=0;

void DFSUtil(int v){

   // Mark the current node as visited and print it

   visited[v]=true;

   //cout<<v<<" ";

   components[compCount].pb(v);

   //Recus for all vertices adjacent to this vertex

   list<int>::iterator it;

   for(it=tadjList[v].begin();it!=tadjList[v].end();++it){

         if(!visited[*it]){

             DFSUtil(*it);

         }

   }	

}

void getTranspose(){

   for(int i=1;i<=n;++i){

       // Recur for all vertices adjacent to this vertex

   	   list<int>::iterator it;

   	   for(it=adjList[i].begin();it!=adjList[i].end();++it){

           tadjList[*it].pb(i);
   	   }

   }
}

void fillOrder(int v){

    // Mark the current node as visited

    visited[v]=true;

    list<int>::iterator it;

    for(it=adjList[v].begin();it!=adjList[v].end();++it){

       if(!visited[*it])
       	   fillOrder(*it);
    }

    Stack.push(v);

}



void printSCCs(){

   // Mark all the vertices as not visited (For First DFS) 
   for(int i=1;i<=n;++i)
   	  visited[i]=false;

   // Fill vertices in stack according to their finishing times
  
   for(int i=1;i<=n;++i)
   	  if(visited[i]==false)
   	  	  fillOrder(i);

   // Create a transpose graph	  	

   getTranspose();

   // Mark all the vertices as not visited(For second DFS)

   for(int i=1;i<=n;++i)
      visited[i]=false;

   while(!Stack.empty()){

        // Pop a vertex from stack

        int v=Stack.top();

        Stack.pop();

        // Print and store Strongly Connected component of popped vertexs 

        if(visited[v]==false){

             DFSUtil(v);
            // cout<<"\n";

             compCount++;

        }       

   }     

}

int main(){

    scanf("%d %d",&n,&m);
    int u,v;

    for(int i=0;i<m;++i){
        scanf("%d %d",&u,&v);
        adjList[u].pb(v);
    }
    
    cout<<"Following are strongly connected components of graph\n";
    printSCCs();
    
    for(int i=0;i<compCount;++i){
        for(int j=0;j<components[i].size();++j){

            printf("%d ",components[i][j]);
        }
        printf("\n");
    }
	  return 0;
}
