/*
 © 2020-09-08 09:35:38 Franco1010 All Rights Reserved
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
lli gcd(lli a, lli b){
  return b ? gcd(b, a % b) : a;
}
lli lcm(lli a, lli b){
  return a / gcd(a, b) * b;
}
int main(){ _
  lli t; cin >> t;
  while(t--){
    lli n; cin >> n;
    multiset<lli> st;
    fore(i, 0, n){
      lli x; cin >> x;
      st.insert(x);
    }
    auto foo = st.end();
    foo--;
    lli cur = *foo;
    vector<lli> res;
    res.pb(*foo);
    st.erase(foo);
    while(sz(res) < n){
      lli bar = 0;
      for(auto i : st) bar = max(bar, gcd(i, cur));
      vector<lli> aux;
      for(auto i : st) if(gcd(i, cur) == bar) aux.pb(i);
      for(auto i : aux){
        res.pb(i);
        st.erase(st.find(i));
      }
      cur = bar;
    }
    for(auto i : res) cout << i << ' '; cout << ENDL;
  }
  return 0;
}
