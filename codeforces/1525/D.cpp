/*
 © 2021-05-16 03:28:00 Franco1010 All Rights Reserved
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
const lli INF = 1e18;
vi zeros, ones;
lli dp[N][N], vis[N][N];
lli solve(lli a = 0, lli b = 0){
  if(a == sz(ones)) return 0;
  if(b == sz(zeros)) return INF;
  auto& ans = dp[a][b];
  auto& mem = vis[a][b];
  if(!mem){
    mem = true;
    ans = INF;
    ans = min(ans, solve(a + 1, b + 1) + abs(ones[a] - zeros[b]));
    ans = min(ans, solve(a, b + 1));
  }
  return ans;
}
int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  lli n; cin >> n;
  fore(i, 0, n){
    lli x; cin >> x;
    if(x) ones.pb(i);
    else zeros.pb(i);
  }
  cout << solve() << ENDL;
  return 0;
}
