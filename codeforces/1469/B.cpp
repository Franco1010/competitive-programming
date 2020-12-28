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
const lli N = 105;
lli dp[N][N];
lli vis[N][N];
lli curvis;
lli solve(vi &r, vi &b, lli pr = 0, lli pb = 0){
  if(pr == sz(r) and pb == sz(b)) return 0;
  lli &ans = dp[pr][pb];
  if(vis[pr][pb] != curvis){
    vis[pr][pb] = curvis;
    ans = 0;
    if(pr < sz(r)){
      ans = max(ans, solve(r, b, pr + 1, pb) + r[pr]);
    }
    if(pb < sz(b)){
      ans = max(ans, solve(r, b, pr, pb + 1) + b[pb]);
    }
  }
  return ans;
}
int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  lli t; cin >> t;
  while(t--){
    lli n; cin >> n;
    vi r(n); fore(i, 0, n) cin >> r[i];
    lli m; cin >> m;
    vi b(m); fore(i, 0, m) cin >> b[i];
    curvis++;
    cout << solve(r, b) << ENDL;
  }
  return 0;
}
