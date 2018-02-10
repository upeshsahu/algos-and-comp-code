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

int arr[50005];
struct seg{
   
   int ans,sum,suf,pref;
};
seg tree[200000];
int n;
seg faltoo;

seg make_node(int v){
   
   seg ret;

   ret.ans=ret.sum=ret.suf=ret.pref=v;
   return ret;
}
seg combineSegments(seg left,seg right){
   
   seg ret;
   ret.sum=left.sum+right.sum;
   ret.pref=max(left.sum+right.pref,left.pref);
   ret.suf=max(right.suf,left.suf+right.sum);
   ret.ans=max(max(left.ans,right.ans),left.suf+right.pref);
   return ret;
}
void buildTree(int a[],int node,int l,int r){  
    if(l==r)
       tree[node]=make_node(a[l]);
    else{
        int mid=(l+r)/2;
        buildTree(a,node*2,l,mid);
        buildTree(a,node*2+1,mid+1,r);
        tree[node]=combineSegments(tree[node*2],tree[node*2+1]);
    }
}

void update(int node,int a,int b,int idx,int val){

   if(a==b){
      arr[idx]=val;
      tree[node]=make_node(arr[idx]);
      return;
   }
   else{
      int mid=(a+b)/2;
      // If idx is in left child , recurse on left child
      if(a<=idx && idx<=mid){
         update(2*node,a,mid,idx,val);
      }
      else{
         update(2*node+1,mid+1,b,idx,val);
      }
      tree[node]=combineSegments(tree[node*2],tree[node*2+1]);

   }
}

seg queryTree(int node,int a,int b,int i,int j){
    
   if(i>b || j<a){
      // range represented by a node is completely outside the 
      // given range
      return faltoo;
   }
   // range represented by a node is completely inside the given range
   if(a>=i && b<=j) return tree[node];
   int mid=(a+b)/2;
   
   // Agar poora range left child me hai

   if(j<=mid)
     return queryTree(node*2,a,mid,i,j);
   
   // Agar poora range right child me hai

   if(i>mid)
     return queryTree(node*2+1,mid+1,b,i,j);

   // Agar range ka kuch part left child me hai and kuch part right child me hai

   seg q1=queryTree(node*2,a,mid,i,j);
   seg q2=queryTree(node*2+1,mid+1,b,i,j);

   return combineSegments(q1,q2);    

}


int main(){
   
   scanf("%d",&n);
 
   for(int i=1;i<=n;++i) scanf("%d",&arr[i]);
  
   buildTree(arr,1,1,n);
  
   int m,x,y,type;
   scanf("%d",&m);
 
   faltoo=make_node(-INF);

   for(int i=0;i<m;++i){
      

      scanf("%d %d %d",&type,&x,&y);
      if(type==0){
         update(1,1,n,x,y);
        // printf("%d\n",arr[x]);
      }
      else
         printf("%d\n",queryTree(1,1,n,x,y).ans);


   }


}
