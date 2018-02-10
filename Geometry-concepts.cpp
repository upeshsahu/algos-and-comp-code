/* Now computing using Object Oriented Method */

#include<bits/stdc++.h>
using namespace std;


class Point{

   vector<int>cord;
   public:

      Point(){

         cord.resize(2,0);

      }

      int setX(int x){
        cord[0]=x;
      }

      int setY(int y){
        
        cord[1]=y;
      }
   	  
      Point operator-(const Point& b){
 
         Point point;
         point.cord[0]=this->cord[0]-b.cord[0];
         point.cord[1]=this->cord[1]-b.cord[1];
         return point;
      }
      
      int operator*(const Point& b){

         int dot=(this->cord[0]*b.cord[0])+(this->cord[1]*b.cord[1]);
         return dot;
      }

      int operator^(const Point& b){

         int cross=(this->cord[0]*b.cord[1])-(b.cord[0]*this->cord[1]);
         return cross;
      }
};
double linePointDist(Point A,Point B,Point C,bool isSegment){

   double dist=((B-A)^(C-A))/sqrt((B-A)*(B-A));

   if(isSegment){

      int dot1=(C-B)*(B-A);
      if(dot1>0) return sqrt((B-C)*(B-C));

      int dot2=(C-A)*(A-B);
      if(dot2>0) return sqrt((A-C)*(A-C));

   }

   return abs(dist);

}

int main(){

   Point A;
   Point B;
   Point C;

   A.setX(2);
   A.setY(3);
   B.setX(6);
   B.setY(7);
   C.setX(8);
   C.setY(11);

   cout<<sqrt((B-A)*(B-A))<<"\n";

   cout<<linePointDist(A,B,C,false)<<"\n";



}

/* Computing using procedural method 

// Compute the dot product AB.BC
int dot(vector<int>A,vector<int>B,vector<int>C){
	
   vector<int>AB(2);
   vector<int>BC(2);

   AB[0]=B[0]-A[0];
   AB[1]=B[1]-A[1];

   BC[0]=C[0]-B[0];
   BC[1]=C[1]-B[1];

   //AB=(x2-x1)i + (y2-y1)j
   //

   int dot=AB[0]*BC[0]+AB[1]*BC[1];
   return dot;
}

// AB * AC

int cross(vector<int>A,vector<int>B,vector<int>C){
 
   vector<int>AB(2);
   vector<int>AC(2);

   AB[0]=B[0]-A[0];
   AB[1]=B[1]-A[1];

   AC[0]=C[0]-A[0];
   AC[1]=C[1]-A[1];

   int cross=AB[0]*AC[1]-AC[0]*AB[1];

   return cross;
   
}

// Compute the distance from A to B

double distance(vector<int>A,vector<int>B){

   int d1=A[0]-B[0];
   int d2=A[1]-B[1];

   return sqrt(d1*d1+d2*d2);

}

// Compute the distance from AB to C
// if isSegment is true,  AB is a isSegment

double linePointDist(vector<int>A,vector<int>B,vector<int>C,int isSegment){
 
   double dist=cross(A,B,C)/distance(A,B); // Normal Perpendicular distance

   if(isSegment){

     int dot1=dot(A,B,C); // closest point outside line segment or not.
     if(dot1>0) return distance(B,C);

     int dot2=dot(B,A,C);
     if(dot2>0) return distance(A,C);

   }

   return abs(dist);


}

*/
