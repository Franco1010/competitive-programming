/*
 © 2021-01-29 08:35:02 Franco1010 All Rights Reserved
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
    vi c(n), a(n), b(n);
    fore(i, 0, n) cin >> c[i];
    fore(i, 0, n) cin >> a[i];
    fore(i, 0, n) cin >> b[i];
    fore(i, 0, n) if(a[i] > b[i]) swap(a[i], b[i]);
    vi dp(n + 1, 0);
    dp[n - 1] = c[n - 1];
    dp[n - 2] = dp[n - 1] + (b[n - 1] - a[n - 1] + 1ll);
    lli res = dp[n - 2];
    for(lli i = n - 3; i >= 0; i--){
      if(a[i + 2] != b[i + 2])
      dp[i] = dp[i + 1] - (b[i + 2] - a[i + 2] + 1ll) + (a[i + 2] + (c[i + 1] - b[i + 2] + 1ll));
      dp[i] = max(dp[i], c[i + 1]);
      dp[i] += b[i + 1] - a[i + 1] + 1;
      res = max(res, dp[i]);
    }
    cout << res << ENDL;
  }
  return 0;
}
