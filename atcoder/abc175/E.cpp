/*
 © 2020-08-15 22:18:58 Franco1010 All Rights Reserved
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
const int N = 3005;
lli mat[N][N];
lli dp[N][N][4];
bool vis[N][N][4];
lli r, c, k;
lli solve(lli x, lli y, lli z){
  if(x == r and y == c) return mat[x][y] > 0 and z < 3? mat[x][y] : 0;
  lli &ans = dp[x][y][z];
  if(!vis[x][y][z]){
    vis[x][y][z] = true;
    ans = 0;
    if(y + 1 <= c){
      if(z < 3) ans = max(ans, solve(x, y + 1, z + 1) + mat[x][y]);
      ans = max(ans, solve(x, y + 1, z));
    }
    if(x + 1 <= r){
      if(z < 3) ans = max(ans, solve(x + 1, y, 0) + mat[x][y]);
      ans = max(ans, solve(x + 1, y, 0));
    }
  }
  return ans;
}
int main(){ _
  cin >> r >> c >> k;
  fore(i, 0, N) fore(j, 0, N) mat[i][j] = -1;
  fore(i, 0, k){
    lli x, y, v; cin >> x >> y  >> v;
    // if(v > 0)
    mat[x][y] = v;
    // else mat[x][y] = 0;
  }
  cout << solve(1, 1, 0) << ENDL;
  return 0;
}
