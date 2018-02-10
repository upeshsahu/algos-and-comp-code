#include<bits/stdc++.h>
#include<ext/pb_ds/detail/standard_policies.hpp>
#include<ext/pb_ds/assoc_container.hpp> // Common file
#include<ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace __gnu_pbds;
using namespace std;
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

#define oo 1000000000

typedef long long ll;
typedef long double ld;


const ll INF64=(ll)(1e18);
const ld EPS=1e-9;
const ld PI=3.1415926535897932384626433832795;

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;

ordered_set X;

int main(){

    X.insert(1);
    X.insert(2);
    X.insert(4);
    X.insert(8);
    X.insert(16);

    cout<<*X.find_by_order(1)<<"\n";
    cout<<*X.find_by_order(2)<<"\n";
    cout<<*X.find_by_order(4)<<"\n";

    cout<<X.order_of_key(-5)<<"\n";
    cout<<X.order_of_key(1)<<"\n";
    cout<<X.order_of_key(3)<<"\n";
    cout<<X.order_of_key(4)<<"\n";
    cout<<X.order_of_key(400)<<"\n";




	return 0;
}
