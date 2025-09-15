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
    ll n, a, b;
    cin >> n >> a >> b;
    ll t1 = a, t2 = b;

    if ((a + b) > n)
    {
        cout << "NO\n";
        return;
    }
    vector<ll> s(n + 1,0), v(n + 1);
    for (int i = 1; i <= n; i++)
    {
        v[i] = i;
    }
    ll d = n - (a+b);
    for(int j=n;j>=1 && d >0 ;j--){
        s[j]=j;
        d--;
    }
    ll l = 1;
    for(int i=a+1;s[i]==0;i++)
    {
        s[i] = l;
        l++;
    }
    for(int i=1;s[i]==0;i++){
        s[i]=l;
        l++;
    }
    ll c1=0, c2=0;
    for(int i=1;i<=n;i++){
        if(s[i]>v[i]) c1++;
        else if(s[i]<v[i]) c2++;
    }
    if(c1!=a or c2!=b){
        cout << "NO\n";
        return;
    }
    cout <<"YES\n";
    for (int i = 1; i <= n; i++)
        cout << s[i] << " ";
    cout << endl;
    for (int i = 1; i <= n; i++)
        cout << v[i] << " ";
    cout << endl;
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