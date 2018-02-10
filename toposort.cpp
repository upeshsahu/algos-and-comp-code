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

vl adjList(100005);

int parent[100005];
int status[100005];
int n,m;

stack<int>toposorted;

bool check;

void dfs_explore(int start){

   status[start]=1;  // Goes into recursion stack

   list<int>::iterator it;

   for(it=adjList[start].begin();it!=adjList[start].end();++it){

       if(parent[*it]==-1){

          parent[*it]=start;
          dfs_explore(*it);       
       }
       else{

          if(status[*it]==1)
          	 check=true;
       }

   }

   toposorted.push(start);

   status[start]=0;

}

void dfs(){

   for(int i=1;i<=n;++i){

       if(parent[i]==-1){

           check=false;

           parent[i]=0;
           dfs_explore(i);

           if(check==true)
           	  break;
       }
   }

}

int main(){
 
    int x,y;

    printf("Enter number of vertices and number of edges\n");

    scanf("%d %d",&n,&m);

    for(int i=1;i<=n;++i){

        parent[i]=-1;
    }

    printf("Enter edges in form u->v\n");

    for(int i=1;i<=m;++i){
   
       scanf("%d %d",&x,&y);
       adjList[x].pb(y);

    }

    dfs();

    if(check==true)
    	printf("Graph is not a DAG therefore Toposort not possible\n");


    else{

        printf("Printing Toposorted List\n");

        while(!toposorted.empty()){

            printf("%d ",toposorted.top());
            toposorted.pop();

        }   

        printf("\n");

    }


	return 0;
}
