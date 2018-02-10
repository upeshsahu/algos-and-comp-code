/*
   Mayank Pratap Singh
   MNNIT, 2nd year IT
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
const ld PI=3.1415926535897932384626433832795;
typedef vector<int> vi;
typedef vector<pair<int,int> > vii;
typedef vector<list<int> > vl;
typedef vector<list<pair<int,int> > > vlp;
typedef vector<list<pair<int,double> > >vld;
typedef map<int,int> mi;
typedef map<string,int> ms;
typedef set<int> si;

// Convex hull
pair<int,int>p0; // A global point needed for sorting points with reference

// A utility function to find next to top in a stack
pair<int,int> nextToTop(stack<pair<int,int> >&S){
  pair<int,int> p=S.top();
  S.pop();
  pair<int,int> res=S.top();
  S.push(p);
  return res;
}

// A utility function to swap two points

int swap(pair<int,int> &p1,pair<int,int> &p2){

   pair<int,int>temp=p1;
   p1=p2;
   p2=temp;
}

// A utility function to return square of distance between p1 annd p2
int distSq(pair<int,int>p1,pair<int,int>p2){

  return (p2.ff-p1.ff)*(p2.ff-p1.ff)+(p2.ss-p1.ss)*(p2.ss-p1.ss);

}

// To find orientation of ordered triplet(p,q,r)

int orientation(pair<int,int>p,pair<int,int>q,pair<int,int>r){

   int val=(q.ss-p.ss)*(r.ff-q.ff)-(r.ss-q.ss)*(q.ff-p.ff);
   if(val==0) return 0;  // Collinear
   return (val>0)?1:2; // Clock or Counterclockwise

}

bool compare(const pair<int,int>&p1,const pair<int,int>&p2){

   int o=orientation(p0,p1,p2);
   if(o==0)
      return distSq(p0,p2)>=distSq(p0,p1);
   return o==2;

}

vii convexHull(vii points,int n){

   // Find the bottommost point
   int ymin=points[0].ss,pos=0;

   for(int i=1;i<n;++i){

      int y=points[i].ss;

      // Pick the bottom most and choose the leftmost in triplet

      if((y<ymin) || (ymin==y && points[i].ff<points[pos].ff))
        ymin=points[i].ss,pos=i;

   }

   // Place the bottom-most point at first position
   swap(points[0],points[pos]);
   p0=points[0];  // bottom most

   vii::iterator it;

   it=points.begin();
   it++;

   sort(it,points.end(),compare);
   

   // If two or more points make same angle with p0
   // Remove all but the one that is farthest from p0
   // Remember that,in above sorting our criteria was
   // to keep the farthest point at the end when more than
   // one points have same angle
   int m=1; // Initialize size of modified vector

   for(int i=1;i<n;++i){
       // keep removing i while angle of i and i+1 is same
       // with respect to p0
       while(i<n-1 && orientation(p0,points[i],points[i+1])==0)
         i++;
       points[m]=points[i];
       m++; // update size of modified vector
   }

   // If modified array of points has less than 3 points

   vii convex_hull;
   if(m<3) return convex_hull;
   // Create an empty stack and push first three points
   // to it
   stack<pair<int,int> >S;
   S.push(points[0]);
   S.push(points[1]);
   S.push(points[2]);
   // Process remaining m-3 points

   for(int i=3;i<m;++i){

      // Keep removing top while the angle formed by
      // points next-to-top,top,and points[i] makes a
      // non-left-turn
      while(orientation(nextToTop(S),S.top(),points[i])!=2){
         S.pop();
      }
      S.push(points[i]);
   }

   // Now stack has output points,

   while(!S.empty()){

      pair<int,int>p=S.top();
      convex_hull.pb(p);
      S.pop();

   }

   return convex_hull;

}

int main(){

   int n;
   scanf("%d",&n);

   vii points;
   vii convex_hull;

   for(int i=0;i<n;++i){
     int x,y;
     scanf("%d %d",&x,&y);
     points.pb(mp(x,y));
   }

   convex_hull=convexHull(points,n);

   cout<<"\n";

   for(int i=0;i<convex_hull.size();++i){
      cout<<convex_hull[i].ff<<" "<<convex_hull[i].ss<<endl;
   }

}
