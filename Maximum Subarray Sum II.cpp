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

void domain_expension()
{
    ll n,a,b;
    cin >> n >> a >> b;
    vector<ll>s(n),prefix(n+1);
    for(int i=0;i<n;i++) cin >> s[i];

    
    for(int i=1;i<=n;i++) prefix[i]=prefix[i-1]+s[i-1];

    multiset<ll>mp;
    ll max_sum=LLONG_MIN;

    for(int i=a;i<=n;i++){
        if(i>b){
            mp.erase(mp.find(prefix[i-b-1]));
        }
        mp.insert(prefix[i-a]);
        max_sum = max(max_sum,prefix[i]-*mp.begin());
    }
    cout << max_sum << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
    domain_expension();
    return 0;
}