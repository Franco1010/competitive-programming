/*
 © 2021-02-05 20:51:04 Franco1010 All Rights Reserved
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
  vi acu(n + 1, 0), tin(n + 1, -1), tout(n + 1, -1);
  vector<vi> ocur(n + 1);
  vi v(n); fore(i, 0, n){
    lli x; cin >> x;
    acu[x]++;
    if(tin[x] == -1) tin[x] = i;
    tout[x] = i;
    ocur[x].pb(i);
    v[i] = x;
  }
  vi dp(n + 1, 0);
  for(lli i = n - 1; i >= 0; i--){
    dp[i] = dp[i + 1];
    lli foo = lower_bound(all(ocur[v[i]]), i) - begin(ocur[v[i]]);
    foo = sz(ocur[v[i]]) - foo;
    dp[i] = max(dp[i], foo);
    if(tin[v[i]] == i){
      dp[i] = max(dp[i], acu[v[i]] + dp[tout[v[i]] + 1]);
    }
  }
  cout << n - dp[0] << ENDL;
  return 0;
}
