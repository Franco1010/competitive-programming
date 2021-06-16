/*
 © 2021-06-16 14:14:04 Franco1010 All Rights Reserved
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
const lli N = 5e3 + 5;
const lli M = 1e5 + 5;
lli v[N];
lli dp[N][N];
lli mxnum[M];
lli mxmod[10];
int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  lli n;
  while(cin >> n){
    memset(dp, 0, sizeof dp);
    fore(i, 0, n) cin >> v[i + 1];
    fore(i, 0, n + 1){
      memset(mxnum, 0, sizeof mxnum);
      memset(mxmod, 0, sizeof mxmod);
      fore(j, 0, i){
        mxnum[v[j]] = max(mxnum[v[j]], dp[j][i]);
        mxmod[v[j] % 7] = max(mxmod[v[j] % 7], dp[j][i]);
      }
      fore(j, i + 1, n + 1){
        dp[i][j] = max(dp[i][j], mxnum[v[j] - 1] + 1);
        dp[i][j] = max(dp[i][j], mxnum[v[j] + 1] + 1);
        dp[i][j] = max(dp[i][j], mxmod[v[j] % 7] + 1);
        dp[i][j] = max(dp[i][j], dp[0][i] + 1ll);
        mxnum[v[j]] = max(mxnum[v[j]], dp[i][j]);
        mxmod[v[j] % 7] = max(mxmod[v[j] % 7], dp[i][j]);
      }
    }
    lli ans = 0;
    fore(i, 0, n + 1) fore(j, i + 1, n + 1) ans = max(ans, dp[i][j]);
    cout << ans << ENDL;
  }
  return 0;
}
