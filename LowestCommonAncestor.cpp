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


int n,q;
const int MAX=100005;
vl adjList(MAX);

vector<int>eulerCircuit;
int depth[2*MAX];
int pos[2*MAX];  // Kaun si position me kaun sa vertex
int firstOccur[MAX];

struct seg{   // Defining node of segment tree

   int val;
   int index;

};

struct seg faltoomin; // For invalid ranges return values
struct seg mintree[800011];

void dfs(int u,int level){

   pos[(int)eulerCircuit.size()]=u;
   firstOccur[u]=(int)eulerCircuit.size();
   depth[(int)eulerCircuit.size()]=level;
   eulerCircuit.pb(u);
   list<int>::iterator it;

   for(it=adjList[u].begin();it!=adjList[u].end();++it){

      dfs(*it,level+1);
      pos[(int)eulerCircuit.size()]=u;
      eulerCircuit.pb(u);
   }

}

void build_mintree(int node,int start,int end){

    if(start>end) return;

    if(start==end){

       mintree[node].val=depth[start];
       mintree[node].index=start;
      return;
    }

    build_mintree(node*2,start,(start+end)/2);
    build_mintree(node*2+1,(start+end)/2+1,end);

    if(mintree[node*2].val<=mintree[node*2+1].val){

       mintree[node].val=mintree[node*2].val;
       mintree[node].index=mintree[node*2].index;
    }

    else{

       mintree[node].val=mintree[node*2+1].val;
       mintree[node].index=mintree[node*2+1].index;

    }



}

struct seg range_min(int node,int start,int end,int left,int right){

   if(start>end || start>right || end<left) return faltoomin;

   if(start>=left && end<=right)
     return mintree[node];

  struct seg q1=range_min(node*2,start,(start+end)/2,left,right);
  struct seg q2=range_min(node*2+1,(start+end)/2+1,end,left,right);

  if(q1.val<=q2.val)
    return q1;

  else
    return q2;

}

int main(){

   int u,v;
   scanf("%d",&n);

   for(int i=0;i<n-1;++i){

      scanf("%d %d",&u,&v);
      adjList[u].pb(v);

   }


   dfs(1,0);

   vi::iterator it;

  /* for(it=eulerCircuit.begin();it!=eulerCircuit.end();++it){

      cout<<*it<<"\n";

   }  */

   for(int i=0;i<2*n-1;++i){

    // cout<<pos[i]<<" "<<depth[firstOccur[pos[i]]]<<"\n";
     depth[i]=depth[firstOccur[pos[i]]];
   }

   faltoomin.val=INF;
   faltoomin.index=-1;

   build_mintree(1,0,2*n-2);

   int q;

   scanf("%d",&q);

   for(int i=0;i<q;++i){

      scanf("%d %d",&u,&v);

      int l=firstOccur[u];
      int r=firstOccur[v];

      if(l<r){

          struct seg q1=range_min(1,0,2*n-2,l,r);

          if(q1.val<depth[l] && q1.val<depth[r]){

              printf("No idea\n");

          }

          else if(depth[l]<depth[r] && depth[l]<q1.val){

              printf("%d taught %d\n",v,u);

          }

          else{


             printf("%d taught %d\n",u,v);
          }

      }

      else{

        struct seg q1=range_min(1,0,2*n-2,r,l);

        if(q1.val<depth[l] && q1.val<depth[r]){

            printf("No idea\n");

        }

        else if(depth[l]<depth[r] && depth[l]<q1.val){

            printf("%d taught %d\n",u,v);

        }

        else{


           printf("%d taught %d\n",v,u);
        }


      }

   }

   return 0;
}
