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

}

void domain_expension()
{
    ll n, k;
    cin >> n >> k;
    vector<ll>s(n);
    for(int i=0;i<n;i++) cin >> s[i];

    map<ll,ll>m;
    // Use a max-heap for mode
    priority_queue<pair<ll,ll>> pq;
    for(auto [u,f]:m) {
        pq.push({f,u});
    }
    cout << pq.top().second << " ";
    pair<ll,ll> it = *st.rbegin();
    cout << it.second << " ";
    for(int i=k;i<n;i++) {
        // Add/update incoming element
        m[s[i]]++;
        pq.push({m[s[i]], s[i]});
        if(m[s[i-k]] > 0) st.insert({m[s[i-k]], s[i-k]});
        // Lazy deletion: pop outdated entries
        while(!pq.empty() && m[pq.top().second] != pq.top().first) pq.pop();
        cout << pq.top().second << " ";

        if(m.count(s[i])) st.erase({m[s[i]], s[i]});
        m[s[i]]++;
        st.insert({m[s[i]], s[i]});

        pair<ll,ll> it = *st.rbegin();
        cout << it.second << " ";
    }
    cout << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
    domain_expension();
    return 0;
}