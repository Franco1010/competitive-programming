/*
 © 2021-03-17 08:35:01 Franco1010 All Rights Reserved
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
  while(t--){
    lli n, m; cin >> n >> m;
    vi mp(m, 0);
    fore(i, 0, n){
      lli x; cin >> x; x %= m;
      mp[x]++;
    }
    lli ans = mp[0] != 0;
    for(lli l = 1, r = m - 1; l <= r; l++, r--){
      lli tot = mp[l] + mp[r];
      lli foo = min(mp[l], mp[r]);
      lli bar = max(mp[l], mp[r]);
      if(foo > 0){
        lli baz = foo + min(foo + 1ll, bar);
        ans += tot - baz + 1ll;
      } else ans += tot;
    }
    cout << ans << ENDL;
  }
  return 0;
}
