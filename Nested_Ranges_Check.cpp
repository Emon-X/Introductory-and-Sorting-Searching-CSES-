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

bool cmp(const pair<ll,pair<ll,ll>>&a,const pair<ll,pair<ll,ll>>&b)
{
    if(a.first==b.first) return a.second.first>b.second.first;
    return a.first<b.first;
}

void domain_expension()
{
    ll n;
    cin >> n;
    vector<pair<ll,pair<ll,ll>>>v;
    for(int i=0;i<n;i++){
        ll x, y;
        cin >> x >> y;
        v.pb({y,{x,i}});
    }
    multiset<ll>mp;
    for(auto [i,j]:v) mp.insert(j.first);

    vector<ll>a(n,0),b(n,0);
    sort(rall(v),cmp);

    //for(auto [i,j]:v) cout << i << " " << j.first<<endl;
    
    for(int i=0;i<n;i++){
        ll idx = v[i].second.second;
        ll x= v[i].second.first;
        mp.erase(mp.find(x));

        auto it = mp.lower_bound(x);
        if(it!=mp.end()) a[idx] = 1;

    }
    for(auto u:a) cout << u << " "; cout << endl;
    
    multiset<ll,greater<ll>>mp1;
    for(int i=0;i<n;i++) mp1.insert(v[i].second.first);

    for(int i=n-1;i>=0;i--){
        ll idx = v[i].second.second;
        ll x= v[i].second.first;
        mp1.erase(mp1.find(x));

        auto it = mp1.lower_bound(x);
        if(it!=mp1.end()) b[idx] = 1;

    }
    for(auto u:b) cout << u << " "; cout << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
    domain_expension();
    return 0;
}