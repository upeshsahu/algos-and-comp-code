// Finding Area of a Polygon
// For any convex - concave polygon
// Given the coordinates as a 2D array

int area=0;
int N=P.size();

// We will triangulate the polygon 
// into triangles with points p[0],p[i],p[i+1]

for(int i=1;i<N-1;++i){
	

   int x1=p[i][0]-p[0][0];
   int y1=p[i][1]-p[0][1];

   int x2=p[i+1][0]-p[0][0];
   int y2=p[i+1][1]-p[0][1];

   int cross=x1*y2-x2*y1;
   area+=cross;
}

return abs(cross/2.0);

