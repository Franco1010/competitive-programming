/*
 © 2021-04-23 09:35:01 Franco1010 All Rights Reserved
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
    lli n, m; cin >> n >> m;
    vector<vi> v(n);
    multiset<lli> st;
    fore(i, 0, n){
      fore(j, 0, m){
        lli x; cin >> x;
        v[i].pb(x);
        st.insert(x);
      }
    }
    while(sz(st) > m){
      auto foo = st.end();
      foo--;
      st.erase(foo);
    }
    lli pos = 0;
    fore(i, 0, n){
      vi foo, bar;
      for(auto k : v[i]){
        if(st.count(k)){
          bar.pb(k);
          st.erase(st.find(k));
        }else foo.pb(k);
      }
      lli posfoo = 0;
      while(posfoo < pos) cout << foo[posfoo++] << ' ';
      for(auto k : bar) {cout << k << ' '; pos++;}
      while(posfoo < sz(foo)) cout << foo[posfoo++] << ' ';
      cout << ENDL;
    }
  }
  return 0;
}
