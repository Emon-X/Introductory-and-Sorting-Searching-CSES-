#include <bits/stdc++.h>
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
    ll n, m;
    cin >> n >> m;
    set<ll> s;
    s.insert(0);
    s.insert(n);

    ll l = 0 ,r = n;
    multiset<ll>st1;
    st1.insert(n);
    ll mx = 0;
    for(int i=0;i<m;i++)
    {
        ll x;
        cin >> x;
        auto it = s.lower_bound(x);

        ll val1 = *it;
        it--;
        ll val2 = *it;

        ll d = val1 - val2;
        st1.erase(st1.find(d));
        st1.insert(val1-x);
        st1.insert(x-val2);
        s.insert(x);

        cout << *st1.rbegin() << " ";

    }
    cout << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    domain_expension();
    return 0;
}