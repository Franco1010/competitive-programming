/*
 © 2021-01-28 01:30:09 Franco1010 All Rights Reserved
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
const lli N = 55;
lli v[N];
lli dp[2][N];
lli vis[2][N];
lli curvis;
lli n, p;
lli solve(lli pos = 0, lli m = 0){
  if(pos == n) return 0;
  lli& ans = dp[m][pos];
  if(vis[m][pos] != curvis){
    vis[m][pos] = curvis;
    ans = 0;
    ans += solve(pos + 1, m);
    ans += solve(pos + 1, (m + v[pos]) % 2ll);
    ans += (m + v[pos]) % 2ll == p;
  }
  return ans;
}
int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  cin >> n >> p;
  fore(i, 0, n) cin >> v[i];
  curvis++;
  cout << solve() + lli(p == 0) << ENDL;
  return 0;
}
