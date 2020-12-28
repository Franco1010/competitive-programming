/*
 © 2020-12-28 08:35:01 Franco1010 All Rights Reserved
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
#define deb(x) cout << #x": " << (x) << endl;

int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  lli t; cin >> t;
  // fore(n, 3, 10000)
  while(t--)
  {
    lli n; cin >> n;
    // lli n = 100000;
    lli p = 2;
    vi pot = {1};
    while(pot.back() * p < n) pot.pb(pot.back() * p);
    vector<ii> ans;
    lli cur = n;
    for(lli i = n - 1; i >= 3; i--){
      if(i == pot.back()){
        lli foo = ceil(double(cur) / double(i));
        if(foo >= i){
          cur = foo;
          ans.pb({n, i});
        }
        pot.pop_back();
        ans.pb({i, n});
      }else{
        ans.pb({i, n});
      }
    }
    while(cur > 1) {
      ans.pb({n, 2});
      lli foo = ceil(double(cur) / double(2));
      cur = foo;
    }
    // if(sz(ans) > n + 5) deb(n);
    cout << sz(ans) << ENDL;
    for(auto i : ans) cout << i.f << ' ' << i.s << ENDL;
  }
  return 0;
}
