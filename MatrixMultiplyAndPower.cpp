typdef vector<vector<ll> > matrix 

matrix matMultiply(matrix mat1,int p,int q,matrix mat2,int r){

   matrix mat3;
   vector<ll>row;

   /* Preparing answer matrix */

   for(int i=0;i<p;++i){
     row.clear();
     for(int j=0;j<r;++j){
        row.pb(0);
     }
     mat3.pb(row);

   }

   /* Matrix Multiplication Step */

   for(int i=0;i<p;++i){
      for(int j=0;j<r;++j){
         mat3[i][j]=0;
         for(int k=0;k<q;++k){
              mat3[i][j]=(mat3[i][j]+mat1[i][k]*mat2[k][j])%MOD;
         }
      }
   }

  return mat3;

}

matrix matPower(matrix T,int p,int q,int expo){

   if(expo==1)
     return T;

   matrix F(p+1,vector<ll>(q+1));

   F=matPower(T,p,q,expo/2);
   F=matMultiply(F,p,q,F,q);   // F*F

   if(expo%2==0)
    return F;
   else
     return matMultiply(F,p,q,T,q);

}
