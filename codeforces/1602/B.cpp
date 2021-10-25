/*
 © 2021-10-25 01:35:01 Franco1010 All Rights Reserved
*/

// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
#define f first
#define s second
#define fore(i,a,b) for(int i = (a), ThxMK = (b); i < ThxMK; ++i)
#define pb push_back
#define all(s) begin(s), end(s)
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define sz(s) int(s.size())
#define ENDL '\n'
using namespace std;
typedef long double ld;
typedef long long lli;
typedef pair<lli,lli> ii;
typedef vector<lli> vi;
#define deb(x) cout << #x": " << (x) << endl;

int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  lli t; cin >> t;
  while(t--){
    lli n; cin >> n;
    vi v(n); for(auto& i : v) cin >> i;
    vector<vi> tm;
    tm.pb(v);
    bool yes = true;
    while(yes){
      yes = false;
      map<lli,lli> mp, rem;
      for(auto i : tm.back()) mp[i]++;
      for(auto i : mp){
        if(i.f != i.s){
          yes = true;
          rem[i.f] = i.s;
        }
      }
      if(yes){
        tm.pb(tm.back());
        for(auto& i : tm.back()){
          if(rem.count(i)) i = rem[i];
        }
      }
    }
    lli q; cin >> q;
    while(q--){
      lli x, k; cin >> x >> k; x--; k = min(k, lli(sz(tm) - 1));
      cout << tm[k][x] << ENDL;
    }
  }
  return 0;
}
