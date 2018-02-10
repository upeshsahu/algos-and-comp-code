// Code for Longest Common Substring using suffix arrays

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

int sa[200005],pos[200005],tmp[200005],N,gap,LCP[200005];

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

    l=0;

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

    string str1,str2,str;

    cin>>str1;

    int n=str1.size();

    cin>>str2;

    int m=str2.size();

    int btostr1[100005]={0};   // belong to str1
    int btostr2[100005]={0};
   
    for(int i=0;i<str1.size();++i)
    	btostr1[i]=1;

    for(int i=0;i<str2.size();++i)
    	btostr2[i+n]=1;
 
    str=str1+str2;

    buildSA(str);

    LCPconstruct(str);

    int max=0;

    string lcs="";

    for(int i=0;i<N;++i){

         int len=LCP[sa[i]];

         if(len>max){
             
             if(btostr1[sa[i]] && btostr2[sa[i-1]]){


                  max=len;
                  lcs=str.substr(sa[i],len);


             }

             else if(btostr2[sa[i]] && btostr1[sa[i-1]]){

                  max=len;
                  lcs=str.substr(sa[i],len);
 

             }

              
         }


    }

    cout<<lcs<<"\n";


	return 0;
}
