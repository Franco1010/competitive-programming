/*
 © 2021-05-18 21:24:29 Franco1010 All Rights Reserved
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
const lli N = 1e3 + 5;
const lli M = 1e4 + 5;
const lli INF = 1e18;
struct Node{
  lli w, s, v;
};
lli n;
Node v[N];
lli dp[2][N][M];
bool vis[2][N][M];
lli solve(lli pos = 0, lli left = 0, lli st = 0){
  if(pos == n){
    if(st == 0) return -INF;
    return 0;
  }
  auto& ans = dp[st][pos][left];
  auto& mem = vis[st][pos][left];
  if(!mem){
    mem = true;
    ans = st == 0 ? -INF : 0;
    ans = max(ans, solve(pos + 1, left, st));
    if(st and left >= v[pos].w) ans = max(ans, solve(pos + 1, min(left - v[pos].w, v[pos].s), st) + v[pos].v);
    if(!st) ans = max(ans, solve(pos + 1, v[pos].s, 1) + v[pos].v);
    // cout << pos << ' ' << left << ' ' << st << ": " << ans << ENDL;
  }
  return ans;
}
int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  cin >> n;
  fore(i, 0, n) cin >> v[i].w >> v[i].s >> v[i].v;
  sort(v, v + n, [&](const Node& a, const Node& b){
    return tuple{-(a.s + a.w), -a.s, a.w} < tuple{-(b.s + b.w), -b.s, b.w};
  });
  // fore(i, 0, n) cout << "(" << v[i].s << ' ' << v[i].w << ")" << ENDL;
  cout << solve() << ENDL;
  return 0;
}
