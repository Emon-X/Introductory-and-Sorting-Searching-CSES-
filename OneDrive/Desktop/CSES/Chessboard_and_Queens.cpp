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

bool valid(ll i, ll j, vector<string> &s)
{
    for (int k = i; k < 8; k++)
    {
        if (s[k][j] == 'Q')
            return false;
    }
    for (int k = i; k >= 0; k--)
    {
        if (s[k][j] == 'Q')
            return false;
    }
    for (int k = j; k < 8; k++){
        if (s[i][k] == 'Q')
            return false;
    }
    for (int k = j; k >= 0; k--)
    {
        if (s[i][k] == 'Q')
            return false;
    }
    for (int n = i, m = j; n >= 0 && m >= 0; m--, n--)
    {
        if (s[n][m] == 'Q')
            return false;
    }
    for (int n = i, m = j; n < 8 && m < 8; m++, n++)
    {
        if (s[n][m] == 'Q')
            return false;
    }
    for (int n = i, m = j; n >= 0 && m < 8; m++, n--)
    {
        if (s[n][m] == 'Q')
            return false;
    }
    for (int n = i, m = j; n < 8 && m >= 0; m--, n++)
    {
        if (s[n][m] == 'Q')
            return false;
    }
    return true;
}

ll dfs(vector<string> &s, ll &Queen, ll row = 0)
{
    if (Queen == 8)
        return 1;
    if(row==8) return 0;

    ll ans = 0;
    for (int col = 0; col < 8; col++)
    {
        if (valid(row, col, s) && s[row][col] == '.')
        {
            s[row][col] = 'Q';
            Queen++;
            ans += dfs(s, Queen, row + 1);
            Queen--;
            s[row][col] = '.';
        }
    }
    return ans;
}

void domain_expension()
{
    vector<string> s(8);
    for (int i = 0; i < 8; i++)
        cin >> s[i];

    // cout << s[0] << endl;
    ll Q=0;
    cout << dfs(s, Q, 0) << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    domain_expension();
    return 0;
}