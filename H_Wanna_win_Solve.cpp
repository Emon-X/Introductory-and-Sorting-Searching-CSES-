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

struct segtree
{
    vector<ll> sums;
    ll sz;

    void init(ll n)
    {
        sz = 1;
        while (sz < n)
            sz *= 2;
        sums.assign(2 * sz, LLONG_MAX);
    }

    void build(ll i, ll val, ll x, ll start, ll end)
    {
        if (start == end)
        {
            sums[x] = val;
            return;
        }
        ll mid = start + (end - start) / 2;
        if (i <= mid)
            build(i, val, 2 * x + 1, start, mid);
        else
            build(i, val, 2 * x + 2, mid + 1, end);
        sums[x] = min(sums[2 * x + 1], sums[2 * x + 2]);
    }

    void build(ll i, ll v)
    {
        build(i, v, 0, 0, sz - 1);
    }

    ll query(ll l, ll r, ll x, ll start, ll end)
    {
        if (l > end || r < start)
            return LLONG_MAX;
        if (l <= start && end <= r)
            return sums[x];

        ll mid = start + (end - start) / 2;
        return min(query(l, r, 2 * x + 1, start, mid), query(l, r, 2 * x + 2, mid + 1, end));
    }

    ll query(ll l, ll r)
    {
        return query(l, r, 0, 0, sz - 1);
    }
};

void domain_expension()
{
    ll n;
    cin >> n;
    segtree st;
    st.init(n + 2);
    vector<ll> arr(n);
    map<ll, set<ll>> ind;
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        arr[i] = x;
        st.build(i, x);
        ind[x].insert(i);
    }
    ll q;
    cin >> q;
    while (q--)
    {
        ll t;
        cin >> t;
        if (t == 1)
        {
            ll i, v;
            cin >> i >> v;
            i--;
            ind[arr[i]].erase(i);
            arr[i] = v;
            ind[v].insert(i);
            st.build(i, v);
        }
        else
        {
            ll i;
            cin >> i;
            i--;
            bool found = false;
            ll end = i + 1001;
            for (int start = i + 1; start < min(end, n); start++)
            {
                ll mn = st.query(start, n - 1);
                if (!ind[mn].empty())
                {
                    auto it = ind[mn].rbegin();
                    ll last = *it;
                    ll val = pow(abs(i - last), 3);
                    if (val >= mn)
                    {
                        cout << last + 1 << endl;
                        found = true;
                        break;;
                    }
                }
            }
            if (!found && (i - 1) > 0)
            {
                end = i - 1001;
                for (int start = i - 1; start >= max(0LL, end);start--)
                {
                    ll mn = st.query(0, start);
                    if (!ind[mn].empty())
                    {
                        auto it = ind[mn].begin();
                        ll last = *it;
                        ll val = pow(abs(i - last), 3);
                        if (val >= mn)
                        {
                            cout << last + 1 << endl;
                            found = true;
                            break;
                        }
                    }
                }
            }
            if (!found)
                cout << "-1\n";
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    domain_expension();
    return 0;
}