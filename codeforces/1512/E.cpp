/*
 © 2021-04-10 15:30:02 Franco1010 All Rights Reserved
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
lli g(lli x){
  if(x <= 0) return 0;
  return x * (x + 1ll) / 2ll;
}
lli g(lli l, lli r){
  return g(r) - g(l - 1);
}
int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  lli t; cin >> t;
  while(t--){
    lli n, l, r, s; cin >> n >> l >> r >> s;
    lli pos = n, tam = r - l + 1;
    for(lli p = n; p; p /= 2ll) while((pos - tam + 1) - p >= 1 and g(pos - tam + 1 - p, pos - p) >= s) pos -= p;
    // fore(i, pos - tam + 1, pos + 1) cout << i << ' '; cout << " ---> " << g(pos - tam + 1, pos) << ENDL;
    vi v(n);
    vector<bool> used(n + 5, false);
    lli cur = g(pos - tam + 1, pos);
    lli lim = 1;
    lli pp = 0;
    fore(i, pos - tam + 1, pos + 1){
      lli elem = i;
      if(cur > s){
        lli foo = min(cur - s, elem - lim);
        cur -= foo;
        elem -= foo;
      }
      lim = elem + 1;
      v[pp + l - 1] = elem;
      used[elem] = true;
      pp++;
    }
    if(cur != s) cout << -1 << ENDL;
    else{
      lli curn = 1;
      fore(i, 0, l - 1){
        while(used[curn]) curn++;
        v[i] = curn;
        used[curn] = true;
      }
      fore(i, r, n){
        while(used[curn]) curn++;
        v[i] = curn;
        used[curn] = true;
      }
      for(auto i : v) cout << i << ' '; cout << ENDL;
    }
  }
  return 0;
}
