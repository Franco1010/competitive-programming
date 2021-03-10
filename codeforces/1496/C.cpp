/*
 © 2021-03-10 06:05:02 Franco1010 All Rights Reserved
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
lli n;
ld solve(vi& a, vi& b){
  ld ans = 0;
  fore(i, 0, n){
    ans += sqrtl(a[i] * a[i] + b[i] * b[i]);
  }
  return ans;
}
int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  lli t; cin >> t;
  while(t--){
    cin >> n;
    vi a, b;
    fore(i, 0, 2ll * n){
      lli x, y; cin >> x >> y;
      if(x < 0) x *= -1ll;
      if(y < 0) y *= -1ll;
      if(x) a.pb(x);
      if(y) b.pb(y);
    }
    sort(all(a));
    sort(all(b));
    cout << fixed << setprecision(11);
    cout << solve(a, b) << ENDL;
  }
  return 0;
}
