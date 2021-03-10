/*
 © 2021-03-10 06:05:02 Franco1010 All Rights Reserved
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
lli mex(unordered_set<lli>& st){
  lli cur = 0;
  while(st.count(cur)) cur++;
  return cur;
}
int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  lli t; cin >> t;
  while(t--){
    lli n, k; cin >> n >> k;
    unordered_set<lli> st;
    lli foo = 0;
    fore(i, 0, n){
      lli x; cin >> x;st.insert(x);
      foo = max(foo, x);
    }
    lli bar = mex(st);
    if(k) st.insert((foo + bar + 1ll) / 2ll);
    if(bar > foo) cout << n + k << ENDL;
    else cout << sz(st) << ENDL;
  }
  return 0;
}
