/*
 © 2020-11-15 08:35:02 Franco1010 All Rights Reserved
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
int main(){ _
  lli t; cin >> t;
  while(t--){
    lli n, w; cin >> n >> w;
    lli l = (w + 1ll) / 2ll, r = w;
    lli sum = 0;
    lli mn = 1e18;
    set<lli> st;
    vector<ii> v(n);
    fore(i, 0, n){
      cin >> v[i].f;
      v[i].s = i;
      st.insert(i);
      sum += v[i].f;
      mn = min(mn, v[i].f);
    }
    sort(all(v));
    if(sum < l or mn > r) cout << -1 << ENDL;
    else if(l <= sum and sum <= r){
      cout << n << ENDL;
      fore(i, 1, n + 1) cout << i << ' '; cout << ENDL;
    }else{
      lli pos = n - 1;
      while(sum > r and pos >= 0){
        if(sum - v[pos].f >= l) sum -= v[pos].f, st.erase(v[pos].s);
        pos--;
      }
      if(sum > r) cout << -1 << ENDL;
      else{
        cout << sz(st) << ENDL;
        for(auto i : st) cout << i + 1 << ' '; cout << ENDL;
      }
    }
  }
  return 0;
}
