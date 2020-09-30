/*
 © 2020-09-30 15:13:45 Franco1010 All Rights Reserved
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
typedef vector<ii> vii;
#define deb(x) cout << #x": " << (x) << endl;

int main(){ _
  lli n, m; cin >> n >> m;
  vii a(n), b(m);
  fore(i, 0, n) cin >> a[i].f >> a[i].s;
  fore(i, 0, m) cin >> b[i].f >> b[i].s;
  vi res(2e6 + 5);
  for(auto i : a){
    for(auto j : b){
      if(j.f >= i.f) res[j.f - i.f] = max(res[j.f - i.f], j.s - i.s + 1);
    }
  }
  lli ans = 1e18;
  for(lli i(sz(res) - 2); i >= 0; i--){
    res[i] = max(res[i], res[i + 1]);
    ans = min(ans, i + res[i]);
  }
  cout << ans << ENDL;
  return 0;
}
