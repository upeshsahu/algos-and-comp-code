    /*
       Mayank Pratap Singh
       MNNIT, 3rd year IT
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
     
    vl adj(100005);
    pair<int,int> tr[100005];
    int level[100005];
    //int visited[100005];    // No need of visited as it is a tree :P
    vector<int> lev[100005];  // stores all the new indexes of nodes that are at level L.
     
    pair<int,ll> buffer[100005];
    int sz;   // sz will maintain size of buffer
    ll ans[100005]; // ans[x]= sum of values of all nodes in subtree[x]
     
    ll val[100005];   // Value at a particular level
     
    int counter;
     
    //  How many nodes in subtree of x are at level l?
     
    int how_many_at_level(int x,int l){   
     
       int lo=tr[x].ff;
       int hi=tr[x].ss;
     
       vector<int>::iterator lower=lower_bound(lev[l].begin(),lev[l].end(),lo),upper;
       upper=upper_bound(lev[l].begin(),lev[l].end(),hi);
       return upper-lower; 
     
    }
     
    void dfs1(int start,int l){   // dfs to form the indexes of start and end of a subtree
     
      // visited[start]=1;
     
       tr[start].ff=counter++;
     
       lev[l].pb(tr[start].ff);
     
       list<int>::iterator it;
     
       for(it=adj[start].begin();it!=adj[start].end();++it){
         
               dfs1(*it,l+1);
        
       }
     
       tr[start].ss=counter-1;
     
       
     
    }
     
    ll dfs2(int start,int l){   // For updating the tree after buffer is full, we have sent start node and level
     
     
       ans[start]=val[l];
     
       list<int>::iterator it;
     
       for(it=adj[start].begin();it!=adj[start].end();++it){
          
              ans[start]+=dfs2(*it,l+1);
       }    
     
       return ans[start];
    }
     
    /*void bfs1(int start){   // Which indexes of a tree are at a given level
     
       level[start]=0;
       queue<int>q;
       q.push(start);
     
       while(!q.empty()){
          int u=q.front();
          q.pop();
          lev[level[u]].pb(tr[u].ff);
          list<int>::iterator it;
     
          for(it=adj[u].begin();it!=adj[u].end();++it){    
              if(level[*it]==-1){
                level[*it]=level[u]+1;
                q.push(*it);
     
              }
          }
     
       }
     
    }  */
     
    int main(){
     
        int n,m;
        cin>>n>>m;
     
        int sqm=sqrt(n);
     
        for(int i=1;i<=n-1;++i){
     
            int u,v;
            cin>>u>>v;
     
            adj[u].pb(v);
           // adj[v].pb(u);
     
     
        }
     
     
      //  memset(level,-1,sizeof(level));
       // memset(visited,0,sizeof(visited));
        memset(ans,0,sizeof(ans));
        memset(val,0,sizeof(val));
     
      
        counter=1;
        dfs1(1,0);
        // bfs1(1);
        //bfs2(1);
     
        sz=0;
        
     
        while(m--){
     
           int type;
           cin>>type;
     
           if(type==1){   // update query
     
              int l;
              ll y;
              cin>>l>>y;  // level and value to increase
              
              buffer[sz++]=mp(l,y);
              val[l]+=y;
     
           }
     
           else{
     
              int x;
              cin>>x;
     
              ll prevans=ans[x];
     
              for(int i=0;i<sz;++i){
                 
                      
                 prevans+=how_many_at_level(x,buffer[i].ff)*buffer[i].ss;
    
     
              }
     
              cout<<prevans<<"\n";
     
           }
     
           if(sz>=sqm){
     
            //  memset(visited,0,sizeof(visited));
              dfs2(1,0);  // for updating ans(x) of each node
              sz=0; 
     
           }
     
     
        }
        
        
     
     
      return 0;
    } 
