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
    string s;
    cin >> s;
    map<char,ll>m;
    for(auto u:s) m[u]++;

    char c='#' ;
    ll odd=0;
    for(auto [ch,f]:m){
        if(f%2){
            odd++;
            c = ch;
        }
    }
    if(odd>1){
        cout << "NO SOLUTION\n";
        return;
    }
    ll l = 0,r=s.size()-1;
    for(auto [ch,f]:m)
    {
        if(f%2==0){
            for(int i=0;i<f;i+=2){
                s[l]=ch;
                s[r]=ch;
                l++,r--;
            }
        }
    }
    if(c!='#'){
        for(int i=0;i<m[c];i++) s[l]=c,l++;
    }

    cout << s << endl;


}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
    domain_expension();
    return 0;
}