/*
 © 2021-02-18 08:35:02 Franco1010 All Rights Reserved
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
// #define ENDL '\n'
using namespace std;
typedef long double ld;
typedef long long lli;
typedef pair<lli,lli> ii;
typedef vector<lli> vi;
#define deb(x) cout << #x": " << (x) << endl;
map<ii,lli> mp;
lli q(lli l, lli r){
  if(mp.count({l, r})) return mp[{l, r}];
  cout << "? " << l << ' ' << r << endl;
  lli x; cin >> x;
  return mp[{l, r}] = x;
}
void ans(lli x){
  cout << "! " << x << endl;
}
int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  lli n; cin >> n;
  lli foo = q(1, n);
  if(foo != 1 and q(1, foo) == foo){
    lli l = 1, r = foo - 1;
    while(r - l > 1){
      lli m = (l + r) / 2;
      if(q(m, foo) == foo) l = m;
      else r = m;
    }
    if(q(r, foo) == foo) ans(r);
    else ans(l);
  }else{
    lli l = foo + 1, r = n;
    while(r - l > 1){
      lli m = (l + r) / 2;
      if(q(foo, m) == foo) r = m;
      else l = m;
    }
    if(q(foo, l) == foo) ans(l);
    else ans(r);
  }
  return 0;
}
//5 2 3 4 1
