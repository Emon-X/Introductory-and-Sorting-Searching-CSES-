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

bool cmp(const pair<ll,ll>&a,const pair<ll,ll>&b)
{
    if(a.first==b.first){
        return a.second<b.second;
    }
    return a.first<b.first;
}

void domain_expension()
{
    ll n;
    cin >> n;
    vector<pair<ll,ll>>v;
    for(int i=0;i<n;i++){
        ll x,y;
        cin >> x >> y;
        v.pb({y,x});
    }
    sort(all(v),cmp);
    ll ans = 1;
    ll pre = v[0].first;
    for(int i=1;i<v.size();i++)
    {
        if(v[i].second>=pre){
            ans++;
            pre= v[i].first;
        }
    }
    cout << ans << endl;

    //for(auto [i,j] :v) cout << i << " " << j << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
    domain_expension();
    return 0;
}