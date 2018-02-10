/* 
    Author:- Mayank Pratap Singh
    2nd year, MNNIT   
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
typedef map<int,int> mi;
typedef map<string,int> ms;
typedef set<int> si;

const int N=9;

bool findUnassignedLocation(int grid[N][N],int &row,int &col){
   
  for(row=0;row<N;++row)
     for(col=0;col<N;++col)
         if(grid[row][col]==0)
             return true;

  return false;

}

bool usedInRow(int grid[N][N],int row,int num){

   for(int col=0;col<N;++col)
      if(grid[row][col]==num)
          return true;
   
   return false;
  
}

bool usedInCol(int grid[N][N],int col,int num){

   for(int row=0;row<N;++row)
      if(grid[row][col]==num)
          return true;
    
   return false; 

}

bool usedInBox(int grid[N][N],int boxStartRow,int boxStartCol,int num){

   for(int row=0;row<3;++row)
      for(int col=0;col<3;++col)
          if(grid[row+boxStartRow][col+boxStartCol]==num)
                return true;

   return false;

}

bool isSafe(int grid[N][N],int row,int col,int num){

  return !usedInRow(grid,row,num) && !usedInCol(grid,col,num) && !usedInBox(grid,row-row%3,col-col%3,num);

}

bool solveSudoku(int grid[N][N]){

   int row,col;

   if(!findUnassignedLocation(grid,row,col))
      return true;  // We have solved sudoku
   
   // Consider digits 1 to 9

   for(int num=1;num<=9;++num){

       if(isSafe(grid,row,col,num)){

           grid[row][col]=num;

           if(solveSudoku(grid))
              return true;
           grid[row][col]=0;

       }

   } 
     
   return false;  // Backtrack
} 

int printSudoku(int grid[N][N]){
  
  for(int row=0;row<N;++row){

     for(int col=0;col<N;++col)
        printf("%d ",grid[row][col]);

     printf("\n"); 

  }

}

int main(){

   int grid[N][N];      

   printf("Enter grid elements for sudoku\n");

   for(int i=0;i<N;++i){

      for(int j=0;j<N;++j){

        scanf("%d",&grid[i][j]);
      }

   }

   if(solveSudoku(grid)==true){
  
      printf("Solved Sudoku:\n");

      printSudoku(grid);

   }   

   else
      printf("No solution exists\n"); 

   return 0;
}
