/*
 © 2020-09-14 09:35:01 Franco1010 All Rights Reserved
*/

#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("avx,avx2,fma")
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
const lli N = 2e5 + 5;
lli dp[N][2];
lli vis[N][2];
lli v[N];
lli n, curvis;
lli solve(lli pos = 0, bool turn = false){
  if(pos >= n){
    return 0;
  }
  lli &ans = dp[pos][turn];
  if(vis[pos][turn] != curvis){
    vis[pos][turn] = curvis;
    ans = 1e18;
    ans = min(ans, solve(pos + 1, !turn) + (!turn and v[pos]));
    if(pos + 1 < n){
      ans = min(ans, solve(pos + 2, !turn) + (!turn and v[pos]) + (!turn and v[pos + 1]));
    }
  }
  return ans;
}
int main(){ _
  lli t; cin >> t;
  while(t--){
    cin >> n;
    fore(i, 0, n) cin >> v[i];
    curvis++;
    cout << solve() << ENDL;
  }
  return 0;
}
