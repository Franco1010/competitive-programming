/*
 © 2020-12-17 08:35:02 Franco1010 All Rights Reserved
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
  fore(tc, 1, t + 1){
    lli n; cin >> n;
    vector<ii> v(n); fore(i, 0, n) cin >> v[i].f >> v[i].s;
    // if(tc != 3) continue;
    lli cur = 0;
    lli dest = 0;
    lli prev = 0;
    lli res = 0;
    v.pb({1e18, 0});
    fore(i, 0, n){
      auto [a, b] = v[i];
      if(cur < dest) cur += min(a - prev, dest - cur);
      else if(cur > dest) cur -= min(a - prev, cur - dest);
      // cout << cur << ' ' << dest << ' ' << prev << ENDL;
      if(cur != dest){ // no ejecuta
        if(cur < dest and cur <= b and b <= dest and v[i + 1].f - a >= b - cur) res++;
        else if(cur > dest and dest <= b and b <= cur and v[i + 1].f - a >= cur - b) res++;
      }else{
        // cout << "aqui" << ENDL;
        dest = b;
        if(cur <= dest and v[i + 1].f - a >= dest - cur) res++;
        else if(cur >= dest and v[i + 1].f - a >= cur - dest) res++;
      }
      prev = a;
      // cout << res << ENDL;
    }
    cout << res << ENDL;
  }
  return 0;
}
