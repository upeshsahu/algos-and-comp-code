// Returns true if there is a path from source 's' to sink 't' in residual graph. Also fills parent[] to store the path */

bool bfs(vector<map<int,int> >radj,int s,int t,int parent[]){
 
   bool visited[10002];
   memset(visited,0,sizeof(visited));

   //Create a queue , enqueue source vertex and mark source vertex
   // as visited

   queue<int>q;

   q.push(s);
   visited[s]=true;

   parent[s]=-1;

   while(!q.empty()){
 
      int u=q.front();
      q.pop();
      
      map<int,int>::iterator it;

      for(it=radj[u].begin();it!=radj[u].end();++it){

         int v=it->ff,w=it->ss;

         if(visited[v]==false && radj[u][v]>0){

             q.push(v);
             parent[v]=u;
             visited[v]=true;

         }

      }
      
   }

   return (visited[t]==true);

}

int fordFulkerson(vector<map<int,int> >adj,int s,int t){

   int u,v,w;
   // Create a residul graph and fill the residual graph with capacities in original graph as residula capacities
   vector<map<int,int> > radj(10002); // // residual graph 

   for(int i=s;i<=t;++i){
 
      map<int,int>::iterator it;

      u=i;

      for(it=adj[i].begin();it!=adj[i].end();++it){

          v=it->ff;
          w=it->ss;
          radj[u][v]=w;

      }

     

   }

   int parent[10002];  // this array is filled by bfs to store path

   int max_flow=0;  // There is no flow initially
   
   // Augment the flow while there is path from source to sink
   while(bfs(radj,s,t,parent)){

      // Find minimum residual capacity of edges along the path filled by BFS. Or we can say find the maximum flow through the path found.

      int path_flow=INT_MAX;

      for(int i=t;i!=s;i=parent[i]){

          u=parent[i];
          path_flow=min(path_flow,radj[u][i]);

      }

      // update residual capacities of the edges and reverse edges
      // along the path
      for(int i=t;i!=s;i=parent[i]){

         u=parent[i];
         radj[u][i]-=path_flow;
         radj[i][u]+=path_flow;

      }

      // add path flow to overall flow
      max_flow+=path_flow;
   }

   return max_flow;

}  
