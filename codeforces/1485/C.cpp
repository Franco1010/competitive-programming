/*
 © 2021-02-12 08:50:01 Franco1010 All Rights Reserved
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
  lli t; cin >> t;
  fore(tc,1 , t + 1){
    lli x, y; cin >> x >> y;
    lli ans = 0;
    lli r = y;
    fore(l, 1, y + 1){
      if(l > r) break;
      lli pos = l;
      for(lli p = r - l + 1; p; p /= 2ll) while(pos + p <= r and (pos + p) * l + l <= x) pos += p;
      // cout << l << ' ' << pos << ENDL;
      ans += pos - l;
      r = pos;
    }
    cout << ans << ENDL;
  }
  return 0;
}
