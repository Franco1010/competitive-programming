/*
 © 2021-03-21 07:20:01 Franco1010 All Rights Reserved
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
    vi v(n); for(auto& i : v) cin >> i;
    set<lli> st;
    vi dif; fore(i, 1, n) {
      dif.pb(v[i] - v[i - 1]);
      st.insert(v[i] - v[i - 1]);
    }
    if(sz(st) < 2){
      cout << 0 << ENDL;
    }else if(sz(st) == 2){
      if(st.count(0)) cout << -1 << ENDL;
      else{
        lli m = abs(*begin(st)) + abs(*rbegin(st));
        set<lli> cur;
        bool yes = true;
        fore(i, 1, n){
          cur.insert((v[i] - v[i - 1] + m) % m);
          if(v[i] >= m or v[i - 1] >= m) yes = false;
          if(!yes or sz(cur) > 1) break;
        }
        if(!yes or sz(cur) > 1) cout << -1 << ENDL;
        else cout << m << ' ' << (*begin(cur)) << ENDL;
      }
    }else cout << -1 << ENDL;
    // for(auto i : dif) cout << i << ' '; cout << ENDL;
  }
  return 0;
}
