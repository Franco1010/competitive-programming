/*
 © 2021-01-19 08:35:02 Franco1010 All Rights Reserved
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
bool ok(vi& v, lli cur){
  multiset<lli> st;
  for(auto i : v) st.insert(i);
  while(!st.empty()){
    auto foo = end(st);
    foo--;
    st.erase(foo);
    if(!st.count(cur - *foo)) return false;
    else{
      st.erase(st.find(cur - *foo));
      cur = max(*foo, cur - *foo);
    }
  }
  return true;
}
int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  lli t; cin >> t;
  while(t--){
    lli n ;cin >> n;
    vi v;
    fore(i, 0, 2 * n){
      lli x; cin >> x;
      v.pb(x);
    }
    sort(all(v));
    bool yes = false;
    fore(i, 0, 2 * n - 1){
      if(ok(v, v.back() + v[i])){
        multiset<lli> st;
        for(auto i : v) st.insert(i);
        yes = true;
        cout << "YES" << ENDL;
        lli cur = v.back() + v[i];
        cout << cur << ENDL;
        while(!st.empty()){
          auto foo = end(st);
          foo--;
          st.erase(foo);
          st.erase(st.find(cur - *foo));
          cout << *foo << ' ' << cur - *foo << ENDL;
          cur = max(*foo, cur - *foo);
        }
        break;
      }
    }
    if(!yes) cout << "NO" << ENDL;
  }
  return 0;
}
