/*
 © 2021-07-30 09:35:01 Franco1010 All Rights Reserved
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
const lli INF = 1e18;
int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  lli t; cin >> t;
  while(t--){
    lli n, m; cin >> n >> m;
    ii a, b; cin >> a.f >> a.s >> b.f >> b.s;
    lli w, h; cin >> w >> h;
    lli ans = INF;
    bool yes = false;
    if(b.f - a.f + w <= n and h <= m){
      yes = true;
      ans = min(ans, max(0ll, w - a.f));
      ans = min(ans, max(0ll, w - (n - b.f)));
    }
    if(b.s - a.s + h <= m and w <= n){
      yes = true;
      ans = min(ans, max(0ll, h - a.s));
      ans = min(ans, max(0ll, h - (m - b.s)));
    }
    if(yes) cout << ans << ENDL;
    else cout << -1 << ENDL;
  }
  return 0;
}
