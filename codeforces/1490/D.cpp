/*
 © 2021-02-16 08:35:01 Franco1010 All Rights Reserved
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
void solve(vi& v, int l, int r, int d = 0){
  if(l > r) return;
  ii mx = {-1e18, -1e18};
  fore(i, l, r + 1) mx = max(mx, {v[i], i});
  solve(v, l, mx.s - 1, d + 1);
  cout << d << ' ';
  solve(v, mx.s + 1, r, d + 1);
}
int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  lli t; cin >> t;
  while(t--){
    lli n; cin >> n;
    vi v(n); for(auto& i : v) cin >> i;
    solve(v, 0, n - 1); cout << ENDL;
  }
  return 0;
}
