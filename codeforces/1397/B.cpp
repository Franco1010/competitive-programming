/*
 © 2020-08-30 15:55:01 Franco1010 All Rights Reserved
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
lli pos(vector<lli> &v, lli x){
  lli res = 0;
  lli pot = 1;
  fore(i, 0, sz(v)){
    res += abs(pot - v[i]);
    if(i + 1 != sz(v) and lli(1e18) / x < pot) return 1e18;
    pot *= x;
  }
  return res;
}
lli ternary(vector<lli> &v){
  lli l = 1, r = 1e18;
  while(r - l > 2){
    lli m1 = l + (r - l) / 3ll;
    lli m2 = r - (r - l) / 3ll;
    lli f1 = pos(v, m1);
    lli f2 = pos(v, m2);
    if(f1 <= f2) r = m2;
    else l = m1;
  }
  lli res = 1e18;
  fore(x, l, r + 1){
    res = min(res, pos(v, x));
  }
  return res;
}
int main(){ _
  lli n; cin >> n;
  vector<lli> v(n);
  fore(i, 0, n) cin >> v[i];
  sort(all(v));
  cout << ternary(v) << ENDL;
  return 0;
}
