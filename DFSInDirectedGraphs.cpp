/*  
   Mayank Pratap Singh
   MNNIT, 2nd year IT
         
   C++ Implementation Of Depth First Search ...  The code prints backward edges so it can be used to detect cycles.
   
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

int parent[100005];
int status[100005];
int n,m;

/* Bro Tip :- While using DFS or any other recursive function,iterator should be local */

void dfs_explore(int start){

   status[start]=1; // Goes into recursion stack

   list<int>::iterator it;

   for(it=adjList[start].begin();it!=adjList[start].end();it++){

       if(parent[*it]==-1){

           parent[*it]=start;
           dfs_explore(*it);
       }

       else{

           if(status[*it]==1)
           	   printf("%d ---> %d is a backward edge\n",start,*it);
       }
   }
   status[start]=0;
}

void dfs(){

   for(int i=1;i<=n;++i){
 
      if(parent[i]==-1){

          parent[i]=0;
          dfs_explore(i);

      }
   }

}

int main(){

    int x,y;

    scanf("%d %d",&n,&m);

    for(int i=1;i<=n;++i){

    	parent[i]=-1;

    }

    for(int i=1;i<=m;++i){

        scanf("%d %d",&x,&y);
        adjList[x].pb(y);
       
    }

    dfs();
    
    for(int i=1;i<=n;++i)
       printf("Parent of Vertex %d = %d\n",i,parent[i]);


	return 0;
}
