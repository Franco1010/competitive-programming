/*
 © 2020-10-27 08:35:02 Franco1010 All Rights Reserved
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
const lli N = 2e5 + 5;
// lli v[N];
// lli pos[N];
// vi g[N];
int main(){ _
  lli t; cin >> t;
  while(t--){
    lli n; cin >> n;
    vi v;
    lli last = 0, cur = 0;
    fore(i, 0, n) {
      lli x; cin >> x;
      if(i == 0){
        v.pb(1);
        last = 0;
        cur = 0;
      }
      else if(x > last){
        cur++;
        last = x;
      }else{
        if(cur) v.pb(cur);
        cur = 1;
        last = x;
      }
    }
    if(cur) v.pb(cur);
    last = 0;
    // for(auto i : v) cout << i << ' '; cout << ENDL;
    lli res = 0;
    lli av = 1;
    lli nav = 0;
    bool yes = false;
    fore(i, 1, sz(v)){
      nav += v[i];
      av--; yes = true;
      if(av == 0){
        res++;
        av = nav;
        nav = 0;
        yes = false;
      }
    }
    cout << res + lli(yes) << ENDL;
  }
  return 0;
}
