// Determination of number of different substrings in a string
// Complexity O(n^2log(n))

string s; // input string
int n=(int)s.size();

// Calculate all powers of p

const int p=31;

vector<unsigned long long>p_pow(s.length());

p_pow[0]=1;

for(size_t i=1;i<p_pow.size();++i)
  p_pow[i]=p_pow[i-1]*p;


// Calculate hashes of all prefixes

vector<unsigned long long>h(s.length());

for(size_t i=0;i<s.length();++i){
	
  h[i]=(s[i]-'a'+1)*p_pow[i];
  if(i) h[i]+=h[i-1];

}

int result=0;  // stores the final answer
// Iterate over length of substrings from 1 to n
for(int l=1;l<=n;++l){
	
   // need to find the number of distinct substrings of length l

   // Get the hashes of all substrings of length l

   vector<long long>hs(n-l+1);

   for(int i=0;i<n-l+1;++i){

      long long cur_h=h[i+l-1];

      if(i) cur_h-=h[i-1];

      // Get all the hashes to same degree

      cur_h*=p_pow[n-i];

      hs[i]=cur_h;



   }

   // Count the number of different hashes

   sort(hs.begin(),hs.end());

   hs.erase(unique(hs.begin(),hs.end()),hs.end());

   result+=(int)hs.size();






}

cout<<result;
