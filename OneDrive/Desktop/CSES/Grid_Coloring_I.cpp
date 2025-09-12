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
ll n,m;
vector<string>s;

bool valid(ll i,ll j,char ch,vector<vector<char>>&r)
{
    if(s[i][j]==ch) return false;
     for(int k=0;k<4;k++){
        ll nx=i+dx[k];
        ll ny=j+dy[k];
        if(nx>=0 && nx<n && ny>=0 && ny<m){
           if(r[nx][ny]==ch) return false;
        }
    }
    return true;
}


void dfs(ll i,ll j,vector<vector<char>>&r)
{
    if(i==n && j==m){
        return;
    }
    for(char a='A';a<='D';a++)
    {
        if(valid(i,j,a,r)){
            r[i][j]=a;
        }
    }
    for(int k=0;k<4;k++){
        ll nx=i+dx[k];
        ll ny=j+dy[k];
        if(nx>=0 && nx<n && ny>=0 && ny<m && r[nx][ny]=='.'){
            dfs(nx,ny,r);
           //r[nx][ny]='.';
        }
    }
}

void domain_expension()
{
    cin >> n >> m;
    s.resize(n);
    for(int i=0;i<n;i++) cin >> s[i];
    
    vector<vector<char>>r (n,vector<char>(m,'.'));

    dfs(0,0,r);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) cout << r[i][j];cout << endl;
    }
    //cout << endl;

}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
    domain_expension();
    return 0;
}