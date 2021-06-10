/*
 © 2021-06-10 09:35:02 Franco1010 All Rights Reserved
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
    lli n; cin >> n;
    vector<ii> v;
    fore(i, 0, n){
      lli x; cin >> x;
      v.pb({x, i + 1});
    }
    sort(all(v));
    lli ans = 1e18;
    if(v[0].s < v[n - 1].s){
      lli foo = v[n - 1].s;
      ans = min(ans, foo);
      foo = v[0].s + (n - v[n - 1].s + 1);
      ans = min(ans, foo);
      foo = (n - v[0].s + 1);
      ans = min(ans, foo);
    }else{
      lli foo = v[0].s;
      ans = min(ans, foo);
      foo = v[n - 1].s + (n - v[0].s + 1);
      ans = min(ans, foo);
      foo = (n - v[n - 1].s + 1);
      ans = min(ans, foo);
    }
    cout << ans << ENDL;
  }
  return 0;
}
