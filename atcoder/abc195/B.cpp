/*
 © 2021-03-12 13:07:10 Franco1010 All Rights Reserved
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
const ld eps = 1e-9;
bool leq(ld a, ld b){ return b - a >= -eps; }
int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  ld a, b, w; cin >> a >> b >> w;
  w *= ld(1000);
  lli mn = 1e18, mx = -1e18;
  bool yes = false;
  fore(i, 1, 1e6 + 1){
    ld foo = w / ld(i);
    if(leq(a, foo) and leq(foo, b)){
      mn = min(mn, lli(i)), mx = max(mx, lli(i));
      yes = true;
    }
  }
  if(yes) cout << mn << ' ' << mx << ENDL;
  else cout << "UNSATISFIABLE" << ENDL;
  return 0;
}
