/*
 © 2020-09-24 09:35:01 Franco1010 All Rights Reserved
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
lli bs(vector<lli> &v, lli x){
  if(v.empty()) return 0;
  lli pos = 0;
  for(lli pot = sz(v); pot > 0; pot /= 2ll) while(pos + pot < sz(v) and v[pos + pot] < x) pos += pot;
  if(v[pos] > x) return 0;
  return pos + 1;
}
int main(){ _
  lli t; cin >> t;
  while(t--){
    lli n; cin >> n;
    bool yes = false;
    lli last = 0;
    fore(i, 0, n){
      lli x; cin >> x;
      if(!last) last = x;
      else if(x >= last) yes = true;
      last = x;
    }
    if(yes) cout << "YES" << ENDL;
    else cout << "NO" << ENDL;
  }
  return 0;
}
