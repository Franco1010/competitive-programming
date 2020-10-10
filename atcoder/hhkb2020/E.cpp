/*
 © 2020-10-10 07:14:00 Franco1010 All ris Reserved
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
const lli MOD = 1E9 + 7;
const lli N = 2e3 + 5;
string mat[N];
lli up[N][N], down[N][N], le[N][N], ri[N][N];
lli fpow(lli x, lli y){
  lli res = 1;
  while(y > 0){
    if(y & 1) res = res * x % MOD;
    x = x * x % MOD;
    y >>= 1ll;
  }
  return res;
}
int main(){ _
  lli tot = 0;
  lli h, w; cin >> h >> w;
  fore(i, 0, h) cin >> mat[i];
  fore(i, 0, h){
    fore(j, 0, w){
      tot = (tot + (mat[i][j] == '.') + MOD) % MOD;
    }
  }
  fore(j, 0, w) up[0][j] = mat[0][j] == '.'? 1 : 0;
  fore(j, 0, w) down[h - 1][j] = mat[h - 1][j] == '.'? 1 : 0;
  fore(i, 0, h) le[i][0] = mat[i][0] == '.'? 1 : 0;
  fore(i, 0, h) ri[i][w - 1] = mat[i][w - 1] == '.'? 1 : 0;
  fore(i, 0, h){
    fore(j, 1, w) le[i][j] = mat[i][j] == '#' ? 0 : le[i][j - 1] + 1;
    for(lli j = w - 2; j >= 0; j--) ri[i][j] = mat[i][j] == '#' ? 0 : ri[i][j + 1] + 1;
  }
  fore(j, 0, w){
    fore(i, 1, h) up[i][j] = mat[i][j] == '#' ? 0 : up[i - 1][j] + 1;
    for(lli i = h - 2; i >= 0; i--) down[i][j] = mat[i][j] == '#' ? 0 : down[i + 1][j] + 1;
  }
  lli res = 0;
  fore(i, 0, h){
    fore(j, 0, w){
      lli foo = max(0ll, up[i][j] + down[i][j] + le[i][j] + ri[i][j] - 3ll) % MOD;
      lli bar = (fpow(2, foo) - 1 + MOD) % MOD;
      bar = bar * fpow(2, (tot - foo + MOD) % MOD) % MOD;
      res = ( res + bar + MOD) % MOD;
    }
  }
  cout << res << ENDL;
  return 0;
}
