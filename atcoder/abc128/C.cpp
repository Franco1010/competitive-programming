/*
 © 2021-01-25 01:59:18 Franco1010 All Rights Reserved
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
  lli n, m; cin >> n >> m;
  vector<vector<bool>> mat(m, vector<bool>(n, false));
  fore(i, 0, m){
    lli k; cin >> k;
    while(k--){
      lli x; cin >> x; x--;
      mat[i][x] = true;
    }
  }
  vi p(m); fore(i, 0, m) cin >> p[i];
  lli res = 0;
  for(lli mask = 0; mask < 1ll << n; mask++){
    lli foo = 0;
    fore(b, 0, m){
      lli bar = 0;
      fore(s, 0, n){
        if(mask & (1ll << lli(s)) and mat[b][s]){
          bar++;
        }
      }
      if(bar % 2ll == p[b]) foo++;
    }
    if(foo == m) res++;
  }
  cout << res << ENDL;
  return 0;
}
