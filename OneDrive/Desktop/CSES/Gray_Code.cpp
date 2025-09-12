#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) (x).begin(), (x).end()

string toBinary(ll x, ll n) {
    string r = "";
    for (int i = n - 1; i >= 0; i--) {
        r += ((x >> i) & 1) ? '1' : '0';
    }
    return r;
}

void domain_expansion() {
    ll n;
    cin >> n;
    ll size = 1LL << n; 

    for (ll i = 0; i < size; i++) {
        ll gray = i ^ (i >> 1); // Binary to Gray conversion
        //cout << gray<<endl;
        string g = toBinary(gray, n);
        cout << g << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    domain_expansion();
    return 0;
}
