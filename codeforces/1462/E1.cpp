/*
 © 2020-12-16 02:25:26 Franco1010 All Rights Reserved
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
  lli m = 3, k = 2;
  while(t--){
    lli n; cin >> n;
    vi v(n); fore(i, 0, n) cin >> v[i];
    sort(all(v));
    lli res = 0;
    fore(i, 0, n){
      auto foo = lower_bound(all(v), v[i] - k);
      if(foo != end(v)){
        lli pos = foo - begin(v);
        if(pos <= i and i - pos + 1 >= m){
          lli bar = i - pos;
          res += bar * (bar - 1ll) / 2ll;
        }
      }
    }
    cout << res << ENDL;
  }
  return 0;
}
