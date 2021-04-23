/*
 © 2021-04-23 09:35:01 Franco1010 All Rights Reserved
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
const lli N = 5e2 + 5;
const lli K = 25;
const lli INF = 1e9;
lli hor[N][N], ver[N][N];
lli dp[K][N][N];
lli vis[K][N][N];
lli curvis;
lli n, m, k;
ii ori;
lli solve(lli z, lli x, lli y){
  if(z == 0){
    return 0;
  }
  auto& ans = dp[z][x][y];
  auto& mem = vis[z][x][y];
  if(mem != curvis){
    mem = curvis;
    ans = INF;
    if(x + 1 < n) ans = min(ans, solve(z - 1, x + 1, y) + 2 * ver[x][y]);
    if(y + 1 < m) ans = min(ans, solve(z - 1, x, y + 1) + 2 * hor[x][y]);
    if(x > 0) ans = min(ans, solve(z - 1, x - 1, y) + 2 * ver[x - 1][y]);
    if(y > 0) ans = min(ans, solve(z - 1, x, y - 1) + 2 * hor[x][y - 1]);
  }
  return ans;
}
int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  cin >> n >> m >> k;
  fore(i, 0, n){
    fore(j, 0, m - 1){
      cin >> hor[i][j];
    }
  }
  fore(i, 0, n - 1){
    fore(j, 0, m){
      cin >> ver[i][j];
    }
  }
  curvis++;
  fore(i, 0, n){
    fore(j, 0, m){
      ori = {i, j};
      if(k&1l) cout << -1 << ' ';
      else cout << solve(k / 2, i, j) << ' ';
    }
    cout << ENDL;
  }
  return 0;
}
