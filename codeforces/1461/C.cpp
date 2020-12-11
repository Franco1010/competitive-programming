/*
 © 2020-12-11 08:35:08 Franco1010 All Rights Reserved
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
// (.6 * .3) + (.4 * .3)  + (.6 * .7)
const lli N = 1e5 + 5;
double dp[2][N];
lli vis[2][N];
lli curvis;
vector<double> probas;
double solve(lli pos = 0, bool done = false){
  if(pos == sz(probas)) return done;
  auto &ans = dp[done][pos];
  if(vis[done][pos] != curvis){
    vis[done][pos] = curvis;
    ans = 0;
    ans += solve(pos + 1, done) * (double(1) - probas[pos]);
    ans += solve(pos + 1, true) * probas[pos];
  }
  return ans;
}
int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  lli t; cin >> t;
  while(t--){
    probas.clear();
    lli n, m; cin >> n >> m;
    vi v(n);
    fore(i, 0, n){
      cin >> v[i];
    }
    vector<bool> sor(n + 1);
    sor[n] = true;
    for(lli i = n - 1; i >= 0; i--){
      if(i + 1 == v[i]){
        sor[i] = sor[i + 1] and (v[i] == i + 1);
      }
    }
    fore(i, 0, m){
      lli r; double p; cin >> r >> p;
      if(sor[r]){
        probas.pb(p);
      }
    }
    curvis++;
    cout << fixed << setprecision(7);
    if(sor[0]) cout << double(1) << ENDL;
    else cout << solve() << ENDL;
  }
  return 0;
}
