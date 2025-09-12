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
ll dx[] = {2, 2, -2, -2, 1, -1, 1, -1};
ll dy[] = {1, -1, 1, -1, 2, 2, -2, -2};

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void domain_expension()
{
    ll n;
    cin >> n;
    vector<vector<ll>> g(n + 1, vector<ll>(n + 1, LLONG_MAX));

    priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>, greater<pair<ll, pair<ll, ll>>>> p;
    p.push({0, {0, 0}});
    g[0][0]=0;

    while (p.size() > 0)
    {
        auto it = p.top();
        p.pop();
        ll d = it.first, i = it.second.first, j = it.second.second;

        for (int x = 0; x < 8; x++)
        {
            ll nx = i + dx[x];
            ll ny = j + dy[x];
            if (nx >= n or ny >= n or nx < 0 or ny < 0)
                continue;

            if (g[i][j] + 1 < g[nx][ny])
            {
                g[nx][ny] = g[i][j] + 1;
                p.push({g[nx][ny], {nx, ny}});
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << g[i][j] << " ";
        cout << endl;
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