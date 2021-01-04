/*
 © 2021-01-04 08:35:01 Franco1010 All Rights Reserved
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
const lli N = 2e5 + 5;
lli dp[2][N];
lli vis[2][N];
lli curvis;
lli n;
lli solve(vi &v, lli pos = 0, bool turn = 0){
  if(pos == n) return 0;
  lli &ans = dp[turn][pos];
  if(vis[turn][pos] != curvis){
    vis[turn][pos] = curvis;
    if(turn){
      ans = 1e18;
      ans = min(ans, solve(v, pos + 1, !turn) - (v[pos] % 2ll == 1 ? v[pos] : 0));
      ans = min(ans, solve(v, pos + 1, turn) + (v[pos] % 2ll == 0 ? v[pos] : 0));
    }else{
      ans = -1e18;
      ans = max(ans, solve(v, pos + 1, !turn) + (v[pos] % 2ll == 0 ? v[pos] : 0));
      ans = max(ans, solve(v, pos + 1, turn) - (v[pos] % 2ll == 1 ? v[pos] : 0));
    }
  }
  return ans;
}
int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  lli t; cin >> t;
  while(t--){
    cin >> n;
    vi par, imp, v;
    fore(i, 0, n){
      lli x; cin >> x;
      if(x&1ll) imp.pb(x);
      else par.pb(x);
      v.pb(x);
    }
    sort(rbegin(v), rend(v));
    curvis++;
    if(solve(v) == 0) cout << "Tie" << ENDL;
    else if(solve(v) > 0) cout << "Alice" << ENDL;
    else cout << "Bob" << ENDL;
  }
  return 0;
}
