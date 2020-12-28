/*
 © 2020-12-28 08:35:01 Franco1010 All Rights Reserved
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
void solve(){
  lli n, k; cin >> n >> k;
  vi ori(n);
  vector<ii> v(n); fore(i, 0, n) cin >> v[i].f, v[i].s = i, ori[i] = v[i].f;
  vi ans(n, -1);
  sort(all(v), [&](const ii& a, const ii &b){
    return tuple{-a.f, a.s} < tuple{-b.f, b.s};
  });
  for(auto i : v){
    lli mx = 0;
    if(i.s > 0) mx = max(mx, ans[i.s - 1]);
    if(i.s + 1 < n) mx = max(mx, ans[i.s + 1]);
    mx = mx + 1ll - k;
    if(i.f + k - 1ll < mx){
      cout << "NO" << ENDL;
      return;
    }
    ans[i.s] = max(mx, i.f);
  }
  if(ans[0] != ori[0] or ans[n - 1] != ori[n - 1]){
    cout << "NO" << ENDL;
    return;
  }
  cout << "YES" << ENDL;
}
int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  lli t; cin >> t;
  while(t--){
    solve();
  }
  return 0;
}
