/*
 © 2020-07-01 08:35:02 Franco1010 All Rights Reserved
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

int main(){ _
  lli t; cin >> t;
  while(t--){
    lli n, k; cin >> n >> k;
    vector<lli> r(n), c(n);
    vector<vector<lli>> m(n, vector<lli> (n, 0));
    fore(i, 0, k) c[i % n]++;
    lli cur = 0;
    fore(i, 0, n){
      fore(j, 0, c[i]){
        r[cur%n]++;
        m[cur % n][i] = 1;
        cur++;
      }
    }
    lli ans = 0;
    lli mn = 1e18, mx = -1e18;
    for(auto i : c) mn = min(mn, i), mx = max(mx, i);
    ans += (mx - mn) * (mx - mn);
    mn = 1e18, mx = -1e18;
    for(auto i : r) mn = min(mn, i), mx = max(mx, i);
    ans += (mx - mn) * (mx - mn);
    cout << ans << ENDL;
    fore(i, 0, n){
      fore(j, 0, n) cout << m[i][j]; cout << ENDL;
    }
  }
  return 0;
}
