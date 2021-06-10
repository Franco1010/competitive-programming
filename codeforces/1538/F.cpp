/*
 © 2021-06-10 09:35:02 Franco1010 All Rights Reserved
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
const lli N = 10;
string s; 
lli dp[2][2][N];
lli vis[2][2][N];
lli curvis;
lli solve(lli pos = 0, lli ini = 0, lli less = 0){
  if(pos == sz(s)) return 0;
  auto& ans = dp[ini][less][pos];
  auto& mem = vis[ini][less][pos];
  if(mem != curvis){
    mem = curvis;
    ans = 0;
    if(!ini) ans = solve(pos + 1, ini, 1);
    fore(i, ini ? 0 : 1, (less ? 9 : s[pos] - '0') + 1){
      ans += solve(pos + 1, 1, less or (i < s[pos] - '0')) + 1;
    }
  }
  return ans;
}
int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  lli t; cin >> t;
  while(t--){
    lli l, r; cin >> l >> r;
    s = to_string(r);
    curvis++;
    auto rr = solve();
    s = to_string(l);
    curvis++;
    auto ll = solve();
    // cout << ll << ' ' << rr << ENDL;
    cout << rr - ll << ENDL;
  }
  return 0;
}
