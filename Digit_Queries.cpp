#include <bits/stdc++.h>
using namespace std;
#define ll long long


pair<ll, int> numbers(long long k)
{
    ll d = 1;
    while (true)
    {
        ll cnt = 9 * (ll)pow(10, d - 1);

        // Check for potential overflow without using __int128
        if (k > cnt * d)
        {
            k -= cnt * d;
            d++;
        }
        else
        {
            ll start = (ll)pow(10, d - 1);
            ll offset = (k - 1) / d;
            int pos = (k - 1) % d;
            return {start + offset, pos};
        }
    }
}

void domain_expension()
{

    ll k;
    cin >> k;
    auto p = numbers(k);
    ll num = p.first;
    // cout << num << " " << p.second << endl;
    int pos = p.second;
    // ll ans = sumOfDigitsUpto(num-1);
    string last = to_string(num);
    cout << last[pos] << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        domain_expension();
    }
}