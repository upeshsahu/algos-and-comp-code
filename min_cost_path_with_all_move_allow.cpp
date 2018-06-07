#include<bits/stdc++.h>
using namespace std;
int grid[100][100];
int n,m;

struct cll
{
  int x;
  int y;
  int distance;
  cll(int x,int y,int distance):
   x(x),y(y),distance(distance){}
};

int func_path()
{

   int dis[n][m];
   int dx[]={1,0,-1,0};
   int dy[]={0,-1,0,1};

   for(int i=0;i<n;i++)
     for(int j=0;j<m;j++)
     	dis[i][j]=INT_MAX;

     dis[0][0]=grid[0][0];
     set<cll> st;
     st.insert(cll(0,0,0));
     cll k=*st.begin();
     st.erase(st.begin());
  //dijistra comes to play
     while(!st.empty())
     {
     	int x,y;

          if(!(x>=0 && x<=n && y<=m && y>=0))
              continue;

     	for(int i=0;i<4;i++)
     	{
           x=k.x+dx[i];
           y=k.y+dy[i];

           if(dis[x][y]!=INT_MAX)
           {
           	st.erase(st.find(cll(x,y,dis[x][y])));
           }

           if(dis[x][y]>dis[k.x][k.y]+grid[x][y])
           {

           	    dis[x][y]=grid[x][y]+dis[k.x][k.y];
           	    st.insert(cll(x,y,dis[x][y]));
           }   
     	}
     }
     return dis[n-1][m-1];
}


int main()
{
    
    cin>>n>>m;
    int a[n][m];

    for(int i=0;i<n;i++)
    	for(int j=0;j<m;j++)
         {
         	cin>>a[i][j];
         }
         cout<<func_path()<<endl;
	return 0;
}