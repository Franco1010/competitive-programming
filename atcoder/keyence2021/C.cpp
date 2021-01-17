/*
 © 2021-01-16 17:40:00 Franco1010 All Rights Reserved
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
const lli MOD = 998244353;
lli mat[N][N];
lli dp[N][N];
lli fpow(lli x, lli y){
  lli r = 1;
  while(y > 0){
    if(y&1) r = r * x % MOD;
    x = x * x % MOD;
    y >>= 1;
  }
  return r;
}
lli h, w, k;
lli inv;
lli solve(lli x = 0, lli y = 0){
  if(x == h - 1 and y == w - 1) return 1;
  if(x == h or y == w) return 0;
  lli &ans = dp[x][y];
  if(ans == -1){
    ans = 0;
    if(mat[x][y] & 1) ans = (ans + solve(x, y + 1)) % MOD;
    if(mat[x][y] & 2) ans = (ans + solve(x + 1, y)) % MOD;
    if(mat[x][y] == 7) ans = (ans * inv) % MOD;
    ans = (ans + MOD) % MOD;
  }
  return ans;
}
int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  fore(i, 0, N) fore(j, 0, N) dp[i][j] = -1, mat[i][j] = 7;
  inv = 2ll * fpow(3, MOD - 2) % MOD;
  cin >> h >> w >> k;
  fore(i, 0, k){
    char c;
    lli x, y;
    cin >> x >> y >> c; x--, y--;
    mat[x][y] = c == 'R' ? 1 : c == 'D' ? 2 : 3;
  }
  cout << (solve() * fpow(3, h * w - k)) % MOD << ENDL;
  return 0;
}
