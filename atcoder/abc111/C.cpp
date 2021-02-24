/*
 © 2021-02-24 01:22:54 Franco1010 All Rights Reserved
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
  lli n; cin >> n;
  array<map<lli,lli>, 2> mp;
  fore(i, 0, n){
    lli x; cin >> x;
    mp[i%2][x]++;
  }
  vector<ii> a;
  for(auto i : mp[0]) a.pb(i);
  vector<ii> b;
  for(auto i : mp[1]) b.pb(i);
  a.pb({1e18, 0});
  b.pb({1e18, 0});
  sort(all(a), [&](const ii& a, const ii& b){
    return a.s > b.s;
  });
  sort(all(b), [&](const ii& a, const ii& b){
    return a.s > b.s;
  });
  lli res = 1e18;
  fore(i, 0, 2){
    fore(j, 0, 2){
      if(a[i].f != b[j].f) res = min(res, n - a[i].s - b[j].s);
    }
  }
  cout << res << ENDL;
  return 0;
}
