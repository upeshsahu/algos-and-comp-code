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
typedef unsigned long long ull;
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

int get_digit(int num,int place){

   return (num/place)%10;
}

bool counting_sort(vector<int>&nums,int place){

   vector<int>count(10);
   bool more_digits=false;

   int i;

   //Divide numbers using buckets using the place vlaue

   for(i=0;i<nums.size();++i){

      if(nums[i]/place>0)
        more_digits=true;

      count[get_digit(nums[i],place)]++;

   }

   if(more_digits){

      for(i=1;i<10;++i)
        count[i]+=count[i-1];

      // Use a temp array to store the sorted list

      vector<int>temp(nums.size());
      for(i=nums.size()-1;i>=0;--i){

         int ind=get_digit(nums[i],place);

         if(count[ind]>0){

           temp[count[ind]-1]=nums[i];
           count[ind]--;

         }
      }

      nums=temp; //

   }

   return more_digits;

}

void radix_sort(vector<int>&nums){

    //Edge Case
    if(nums.size()<2)
      return;

    int place=1;

    // For each place,sort numbers using counting sort
    // Stop when there are no more digits at given place

    while(counting_sort(nums,place))
       place*=10;


}
int main(){

     int n;
     cin>>n;
     vector<int>nums(n);

     int i;

     for(i=0;i<n;++i){

        cin>>nums[i];
     }

     radix_sort(nums);

     for(i=0;i<n;++i)
        cout<<nums[i]<<" ";

      cout<<"\n";  

     return 0;

}
