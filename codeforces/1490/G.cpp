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
int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  lli t; cin >> t;
  while(t--){
    lli n, m; cin >> n >> m;
    vector<ii> ord = {{0, 0}};
    lli acu = 0;
    lli mx = 0;
    fore(i, 1, n + 1){
      lli x; cin >> x;
      acu += x;
      if(ord.back().f < acu) ord.pb({acu, i});
      mx = max(mx, acu);
    }
    fore(rep, 0, m){
      lli x; cin >> x;
      auto foo = lower_bound(all(ord), ii{x, -1});
      if(foo != end(ord)){
        cout << (*foo).s - 1 << ' ';
      }else if(acu > 0){
        lli pos = 0;
        lli lim = 1;
        while(lim * acu <= x - mx) lim *= 2ll;
        for(lli p = lim; p ; p /= 2ll) while(pos + p <= lim and (pos + p) * acu < x - mx) pos += p;
        if(pos * acu + mx < x) pos++;
        x -= pos * acu;
        foo = lower_bound(all(ord), ii{x, -1});
        cout << pos * n + (*foo).s - 1 << ' ';
      }else cout << -1 << ' ';
    }
    cout << ENDL;
  }
  return 0;
}
