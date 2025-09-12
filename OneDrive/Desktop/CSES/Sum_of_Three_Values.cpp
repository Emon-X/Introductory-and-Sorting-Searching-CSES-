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
    ll n,x;
    cin >> n >> x;
    vector<pair<ll,ll>>v;
    for(int i=0;i<n;i++){
        ll u;
        cin >> u;
        v.pb({u,i});
    }
    sort(all(v));
    ll l = 0, r = n-1;

    for(int i=0;i<n-2;i++)
    {
        ll l = i+1, r = n-1;
        while(l<r)
        {
            ll sum = v[i].first + v[l].first + v[r].first;
            if(sum==x){
                cout << v[i].second+1 << " " << v[l].second+1 << " " << v[r].second+1 << endl;
                return;
            }
            else if(sum<x) l++;
            else r--;
        }
    }
    cout << "IMPOSSIBLE" << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
    domain_expension();
    return 0;
}