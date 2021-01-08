/*
 © 2021-01-08 16:45:10 Franco1010 All Rights Reserved
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
const lli N = 3;
const lli INF = 1e18;
int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  vi n(N); fore(i, 0, N) cin >> n[i];
  vector<vi> v(N);
  vi s(N + 1, 0);
  fore(i, 0, N){
    v[i].resize(n[i]);
    fore(j, 0, n[i]) cin >> v[i][j], s[i] += v[i][j];
    s[3] += s[i];
    sort(all(v[i]));
  }
  lli res = -INF;
  res = max(res, s[3] - 2ll * (v[0][0] + v[1][0]));
  res = max(res, s[3] - 2ll * (v[0][0] + v[2][0]));
  res = max(res, s[3] - 2ll * (v[1][0] + v[2][0]));
  fore(i, 0, N) res = max(res, s[3] - 2ll * s[i]);
  cout << res << ENDL;
  return 0;
}
