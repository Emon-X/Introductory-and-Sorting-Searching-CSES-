#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ll long long int
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define pp pop_back()
#define mod 1000000007
#define endl "\n"
#define N 200005
ll dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
ll dy[] = {0, 0, 1, -1, 1, -1, 1, -1};
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void domain_expension()
{
    ll n;
    cin >> n;
    ll sum = n*(n+1)/2;
    if(sum%2){
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    ll x = sum / 2;
    vector<ll>v (n+1,0);
    for(int i=n;i>=1;i--){
        if(x-i>=0){
            v[i]=1;
            x-=i;
        }
    }
    cout << accumulate(all(v),0LL) << endl;
    for(int i=1;i<=n;i++){
        if(v[i]) cout << i <<" ";
    }
    cout << endl;
    cout << n - accumulate(all(v),0LL) << endl;
    for(int i=1;i<=n;i++){
        if(v[i]==0) cout <<i<<" ";
    }
    cout << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
    domain_expension();
    return 0;
}