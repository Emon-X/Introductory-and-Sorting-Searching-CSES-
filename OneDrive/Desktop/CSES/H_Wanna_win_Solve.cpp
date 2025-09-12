#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ll long long int

struct segtree {
    vector<ll> sums;
    ll sz;

    void init(ll n) {
        sz = 1;
        while (sz < n) sz *= 2;
        sums.assign(2 * sz, LLONG_MAX);
    }

    void update(ll i, ll val, ll x, ll start, ll end) {
        if (start == end) {
            sums[x] = val;
            return;
        }
        ll mid = (start + end) / 2;
        if (i <= mid) update(i, val, 2 * x + 1, start, mid);
        else update(i, val, 2 * x + 2, mid + 1, end);
        sums[x] = min(sums[2 * x + 1], sums[2 * x + 2]);
    }

    void update(ll i, ll v) {
        update(i, v, 0, 0, sz - 1);
    }

    ll query(ll l, ll r, ll x, ll start, ll end) {
        if (l > end || r < start) return LLONG_MAX;
        if (l <= start && end <= r) return sums[x];
        ll mid = (start + end) / 2;
        return min(query(l, r, 2 * x + 1, start, mid), query(l, r, 2 * x + 2, mid + 1, end));
    }

    ll query(ll l, ll r) {
        return query(l, r, 0, 0, sz - 1);
    }
};

void domain_expension() {
    ll n;
    cin >> n;
    segtree st;
    st.init(n + 2);
    vector<ll> arr(n);
    map<ll, set<ll>> ind;

    for (int i = 0; i < n; i++) {
        ll x; cin >> x;
        arr[i] = x;
        st.update(i, x);
        ind[x].insert(i);
    }

    ll q; cin >> q;
    while (q--) {
        ll t; cin >> t;
        if (t == 1) {
            ll i, v; cin >> i >> v;
            i--;
            ind[arr[i]].erase(i);
            arr[i] = v;
            ind[v].insert(i);
            st.update(i, v);
        } else {
            ll i; cin >> i;
            i--;
            bool found = false;


            if (i + 2 < n) {
                ll mn = st.query(i + 2, n - 1);
                if (mn != LLONG_MAX && !ind[mn].empty()) {
                    auto it = ind[mn].rbegin();
                    ll last = *it;
                    ll d = abs(i - last);
                    ll val = 1LL * d * d * d;
                    if (val >= mn) {
                        cout << last + 1 << "\n";
                        found = true;
                    }
                }
            }

            if (!found && i - 2 >= 0) {
                ll mn = st.query(0, i - 2);
                if (mn != LLONG_MAX && !ind[mn].empty()) {
                    auto it = ind[mn].begin();
                    ll last = *it;
                    ll d = abs(i - last);
                    ll val = 1LL * d * d * d;
                    if (val >= mn) {
                        cout << last + 1 << "\n";
                        found = true;
                    }
                }
            }

            if (!found) {
                if (i + 1 < n && arr[i + 1] == 1) {
                    cout << i + 2 << "\n";
                    found = true;
                } else if (i - 1 >= 0 && arr[i - 1] == 1) {
                    cout << i << "\n";
                    found = true;
                }
            }

            if (!found) cout << "-1\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    domain_expension();
    return 0;
}
