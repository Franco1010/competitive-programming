/*
 © 2021-07-30 09:35:01 Franco1010 All Rights Reserved
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
const lli N = 5;
const lli M = 1e5 + 5;
lli mat[N][M];
int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  lli t; cin >> t;
  while(t--){
    lli m; cin >> m;
    fore(i, 0, 2) fore(j, 0, m) cin >> mat[i][j];
    vi pre(m + 1, 0), suf(m + 1, 0);
    fore(i, 0, m) pre[i + 1] = pre[i] + mat[1][i];
    for(lli i = m - 1; i >= 0; i--) suf[i] = suf[i + 1] + mat[0][i];
    // for(auto i : suf) cout << i << ' '; cout << ENDL;
    // for(auto i : pre) cout << i << ' ' ; cout << ENDL;
    lli ans = 1e18;
    fore(i, 0, m){
      ans = min(ans, max(pre[i], suf[i + 1]));
    }
    cout << ans << ENDL;
  }
  return 0;
}
