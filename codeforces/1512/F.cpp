/*
 © 2021-04-10 15:30:02 Franco1010 All Rights Reserved
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
    lli n, c; cin >> n >> c;
    vi a(n); for(auto& i : a) cin >> i;
    vi b(n - 1); for(auto& i : b) cin >> i;
    vector<ii> dm(n, {0, 0});
    lli ans = 1e18;
    fore(i, 0, n){
      lli foo = max(0ll, c - dm[i].s);
      lli bar = foo / a[i] + lli(foo % a[i] != 0);
      ans = min(ans, bar + dm[i].f);
      if(i + 1 < n){
        foo = max(0ll, b[i] - dm[i].s);
        bar = foo / a[i] + lli(foo % a[i] != 0);
        lli mm = bar * a[i] + dm[i].s;
        dm[i + 1] = {dm[i].f + bar + 1, mm - b[i]};
      }
    }
    cout << ans << ENDL;
  }
  return 0;
}
