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
int m,n,k;
// A DFS based recursive function that returns true if a
// matching for vertex u is possible
bool bpm(bool bpGraph[m][n],int u,bool seen[],int matchR[]){

   // Try every job one by one
   for(int v=0;v<N;++v){

     // If applicant u is interested in job v and v 
   	 // is not visited

   	if(bpGraph[u][v] && !seen[v]){

      seen[v]=true; // mark v as visited
      
      // If job 'v' is not assigned to an applicant  
      // OR previously assigned applicant has an alternate job
      // Since v is marked as visited above , matchR[v] will not 
      // get job 'v' again.

      if(matchR[v]<0 || bpm(bpGraph,matchR[v],seen,matchR)){

          matchR[v]=u;
          return true;

      }



   	}


   }
 
   return false;
}
// Returns maximum number of matching from M to N
int maxBPM(bool bpGraph[m][n]){
  
  // An array to keep track of applicants assigned to jobs. The value of matchR[i] is 
  // the applicant number assigned to job i, the value -1 indicated nobody
  // is assigned.
  
  int matchR[n];

  // Initially all jobs are available
  memset(matchR,-1,sizeof(matchR));

  int result=0; // Count of jobs assigned to applicants

  for(int u=0;u<m;++u){
   
    // Mark all jobs as not seen for next applicant
    bool seen[N];
    memset(seen,0,sizeof(seen));

    // Find if the applicant 'u' can get a job
    if(bpm(bpGraph,u,seen,matchR))
    	result++;
  }
   
   
  return result;

}

int main(){
	//lets rock
	
	cin>>m>>n>>k;

    bool bpGraph[m][n];

    memset(bpGraph,0,sizeof(bpGraph));

    for(int i=0;i<k;++i){

       int u,v;
       cin>>u>>v;

       bpGraph[u-1][v-1]=1;


    }

    int count=maxBPM(bpGraph);

    

	return 0;
}
