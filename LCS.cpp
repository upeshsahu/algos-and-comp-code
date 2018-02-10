#include<bits/stdc++.h>
using namespace std;

int L[500][500],m,n;

string lcs;

int lenLcs(string X,string Y,int m,int n){

   if(m==0 || n==0)
      return 0;

   if(L[m][n]!=-1)
      return L[m][n];

   if(X[m-1]==Y[n-1])
      return L[m][n]=1+lenLcs(X,Y,m-1,n-1);

   else
      return L[m][n]=max(lenLcs(X,Y,m,n-1),lenLcs(X,Y,m-1,n));         

}

void findLCS(string X,string Y,int m,int n){
 
    if(m==0 || n==0)
        return;

    if(X[m-1]==Y[n-1]){
        lcs=X[m-1]+lcs;
        findLCS(X,Y,m-1,n-1);
    }    

    
    else
       if(L[m-1][n]>=L[m][n-1])
            findLCS(X,Y,m-1,n);
       else
         	findLCS(X,Y,m,n-1);

 //   return lcs;     
}


int main(){
	
    string X,Y;

    lcs="";

    printf("Enter strings whose LCS you want to find\n");

    cin>>X>>Y;

    m=X.size();
    n=Y.size();

    for(int i=0;i<=m;++i)
       for(int j=0;j<=n;++j)
          L[i][j]=-1;   

    printf("LCS of two strings is %d\n",lenLcs(X,Y,m,n));

    printf("2D array L[m][n] : \n");

    for(int i=0;i<=m;++i){

       for(int j=0;j<=n;++j)
       	  printf("%d ",L[i][j]);

       printf("\n");	
    }

    findLCS(X,Y,m,n);
   
    cout<<lcs<<"\n";



	return 0;
}
