/*
 © 2020-12-30 08:35:01 Franco1010 All Rights Reserved
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
    lli s = 0;
    vi v(n); fore(i, 0, n) cin >> v[i], s += v[i];
    vi g(n);
    fore(i, 0, n - 1){
      lli u, v; cin >> u >> v; u--, v--;
      g[u]++;
      g[v]++;
    }
    vi ord;
    fore(i, 0, n) fore(j, 0, g[i] - 1) ord.pb(v[i]);
    sort(all(ord));
    cout << s << ' ';
    fore(i, 1, n - 1){
      s += ord.back();
      ord.pop_back();
      cout << s << ' ';
    }
    cout << ENDL;
  }
  return 0;
}
