#include<bits/stdc++.h>
using namespace std;
#define ll long long

void domain_expension()
{
    string s;
    cin >> s;
    vector<ll> m(26,0);
    for(char c:s) m[c-'A']++;

    ll n = s.size();
    ll d = (n+1)/2;
    for(auto f:m){
        if(f>d){ 
            cout << -1 << "\n"; 
            return; 
        }
    }

    string r="";
    char prev='#';

    for(int pos=0;pos<n;pos++){
        bool ok=false;
        for(int i=0;i<26;i++){
            if(m[i]==0) continue;
            char ch='A'+i;
            if(ch==prev) continue;

            m[i]--;
            ll left=n-pos-1;
            ll mxleft=*max_element(m.begin(),m.end());

            if(mxleft <= (left+1)/2){
                r.push_back(ch);
                prev=ch;
                ok=true;
                break;
            }
            m[i]++; 
        }
        if(!ok){
            cout << -1 << "\n";
            return;
        }
    }
    cout << r << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    domain_expension();
}
