/*
 © 2021-06-06 09:35:01 Franco1010 All Rights Reserved
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
    lli n; cin >> n;
    set<lli> st;
    vi v;
    fore(i, 0, n){
      lli x; cin >> x;
      st.insert(x);
      v.pb(x);
    }
    bool yes = true;
    while(yes and sz(v) <= 300){
      yes = false;
      vi foo;
      fore(i, 0, sz(v)){
        fore(j, i + 1, sz(v)){
          if(!st.count(abs(v[i] - v[j]))){
            st.insert(abs(v[i] - v[j]));
            foo.pb(abs(v[i] - v[j]));
            yes = true;
          }
        }
      }
      for(auto i : foo) v.pb(i);
    }
    if(sz(v) > 300 or *(st.rbegin()) > lli(1e9)) cout << "NO" << ENDL;
    else{
      cout << "YES" << ENDL;
      cout << sz(v) << ENDL;
      for(auto i : v) cout << i << ' '; cout << ENDL;
    }
  }
  return 0;
}
