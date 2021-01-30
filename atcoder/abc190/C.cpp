/*
 © 2021-01-30 05:58:27 Franco1010 All Rights Reserved
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
  lli n, m; cin >> n >> m;
  vector<ii> cond;
  fore(i, 0, m){
    lli a, b; cin >> a >> b;
    cond.pb({a, b});
  }
  lli k; cin >> k;
  vector<ii> opt;
  fore(i, 0, k){
    lli c, d; cin >> c >> d;
    opt.pb({c, d});
  }
  lli mx = 0;
  for(lli mask = 0; mask < (1ll << k); mask++){
    vi foo(n + 1, 0);
    fore(i, 0, k){
      if(mask & (1ll << lli(i))) foo[opt[i].f] = 1;
      else foo[opt[i].s] = 1;
    }
    lli bar = 0;
    for(auto i : cond) if(foo[i.f] and foo[i.s]) bar++;
    mx = max(mx, bar);
  }
  cout << mx << ENDL;
  return 0;
}
