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

string s;
map<pair<ll, bool>, pair<ll, ll>> dp;

pair<ll, ll> digit_dp(ll pos, bool tight)
{
    if (pos == s.size())
        return {1, 0};
    auto key = make_pair(pos, tight);
    if (dp.count(key))
        return dp[key];
    ll limit = tight ? (s[pos] - '0') : 9;
    ll d_cnt = 0, d_sum = 0;
    for (int d = 0; d <= limit; d++)
    {
        bool nt = tight && (d == limit);
        auto nxt = digit_dp(pos + 1, nt);
        d_cnt += nxt.first;
        d_sum += nxt.second + d * nxt.first;
    }
    return dp[key] = {d_cnt, d_sum};
}

ll sumOfDigit(ll n)
{
    if (n <= 0)
        return 0;
    s = to_string(n);
    dp.clear();
    return digit_dp(0, true).second;
}

pair<ll, ll> number(ll k)
{
    ll d = 1;
    while (true)
    {
        ll cnt = 9 * (ll)pow(10, d - 1);
        if (k > cnt * d)
        {
            k -= cnt * d;
            d++;
        }
        else
        {
            ll start = (ll)pow(10, d - 1);
            ll offset = (k - 1) / d;
            ll pos = (k - 1) % d;
            return {start + offset, pos};
        }
    }
}

void domain_expension()
{
    ll k;
    cin >> k;
    auto last_num = number(k);

    ll n = last_num.first, pos = last_num.second;

    ll ans = sumOfDigit(n - 1);
    // cout << ans << endl;

    string s = to_string(n);
    for (int i = 0; i <= pos; i++)
        ans += (s[i] - '0');

    cout << ans << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        domain_expension();
    return 0;
}