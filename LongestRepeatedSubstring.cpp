#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

#define oo 1000000000
#define mod 1000000007

typedef long long ll;
typedef long double ld;

const ll INF64=(ll)(1e18);
const ld EPS=1e-9;
const ld PI=3.1415926535897932384626433832795;

int sa[1005],pos[1005],tmp[1005],N,gap,LCP[1001];

// sa is suffix array
// pos and temp are used to build suffix array
// N is the length of string 
// gap is a variable used in buildSA()
// LCP is LCP array.

bool sufCmp(int i,int j){

    if(pos[i]!=pos[j])
    	return pos[i]<pos[j];

    i+=gap;
    j+=gap;

    return (i<N && j<N)? pos[i]<pos[j]:i>j;

}

void buildSA(string str){

    N=str.size(); 

    for(int i=0;i<N;++i){
    	sa[i]=i;
        pos[i]=str[i];

    } 	

    /* Gap is the length of m-gram in each step,divided by 2
       We start with 2-grams,so gap is 1 initially,It then increases to 2,4,8 and so on. */
    for(gap=1;;gap*=2){
 
        /* We sort by (gap*2)-grams */
        sort(sa,sa+N,sufCmp);

        /* We compute the lexicographic rank
        of each m-gram we have sorted above */

        for(int i=0;i<N-1;++i){

        	 tmp[i+1]=tmp[i]+sufCmp(sa[i],sa[i+1]);
        }

        /* tmp contains the rank by position.Now we map 
        into pos,so that in next step we can look
        up per m-gram rather than by position. */

        for(int i=0;i<N;++i)
        	 pos[sa[i]]=tmp[i];

        if(tmp[N-1]==N-1) break;	

    }

}

 void LCPconstruct(string str)
{
    int i,C[1001],l;
    C[sa[0]] = N;


    for(i=1;i<N;i++)
    C[sa[i]] = sa[i-1];

    l = 0;

   for(i=0;i<N;i++)
   {
    if(C[i]==N)
        LCP[i] = 0;
    else
    {
        while(i+l<N && C[i]+l<N && str[i+l] == str[C[i]+l])
            l++;
        LCP[i] = l;

        l = max(l-1,0);
    }
  }

}

int main(){

    string str;
    cin>>str;

    buildSA(str);
    LCPconstruct(str);

    string lrs="";

    for(int i=0;i<N;++i){

        int len=LCP[sa[i]];

       // printf("%d %d\n",len,sa[i]);

        if(len>lrs.length()){

            lrs=str.substr(sa[i],len);

        }

    }

    cout<<lrs<<"\n";

    return 0;
}
