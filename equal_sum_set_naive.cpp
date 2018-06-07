#include <bits/stdc++.h>
using namespace std;
 
bool findSets(int arr[], int n, vector<int>& set1,vector<int>& set2, int sum1, int sum2, int pos)
{ 
    if (pos == n) 
        if (sum1 == sum2) 
           return true;
        else
            return false;        

    set1.push_back(arr[pos]);
    bool res = findSets(arr, n, set1, set2, sum1 + arr[pos], 
                                             sum2, pos + 1);
    if (res)
       return res;
    set1.pop_back();
    set2.push_back(arr[pos]);
    return findSets(arr, n, set1, set2, sum1, sum2 + arr[pos],
                                                    pos + 1);
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
   
   
    int sum = 0;
    bool res=true;
    vector<int> set1, set2;
    for (int i = 0; i < n; i++) 
        sum += arr[i];    
    if (sum % 2 != 0) 
        cout<<"not possible"<<endl; 
    else  
    {
        
        res= findSets(arr, n, set1, set2, 0, 0, 0);
    }
    if (!res) {
        cout << "-1";
    }
    else
    {
        cout<<set1.size()<<" "<<set2.size()<<endl;
      for (int i = 0; i < set1.size(); i++) 
    {
        cout << set1[i] << " ";
    }
    cout<<endl;
    for (int i = 0; i < set2.size(); i++) {
        cout << set2[i] << " ";
    }   
    }
    return 0;
}
