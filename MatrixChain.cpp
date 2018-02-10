#include<bits/stdc++.h>
using namespace std;

int memo[505][505];

int matrixChainMultiplication(int p[],int i,int j){

   if(i==j) return 0;

   if(memo[i][j]!=-1)
      return memo[i][j];

   int min=INT_MAX,count;

   for(int k=i;k<j;++k){

       count=matrixChainMultiplication(p,i,k)+matrixChainMultiplication(p,k+1,j)+p[i-1]*p[k]*p[j];

       if(count<min)
       	  min=count;

   }    

   return memo[i][j]=count;
	
}

int main(){
	
    int n,arr[500];

    printf("Enter number of matrices you want to multiply\n");

    scanf("%d",&n);

    printf("Enter sizes of matrices\n");

    for(int i=0;i<=n;++i){

        scanf("%d",&arr[i]);
    }

    for(int i=0;i<=n;++i)
        for(int j=0;j<=n;++j)
        	memo[i][j]=-1;


   

    printf("Minimum number of multiplications is %d\n",matrixChainMultiplication(arr,1,n-1));


	return 0;
}
