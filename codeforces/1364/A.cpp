/*
 © 2020-06-13 10:05:01 Franco1010 All Rights Reserved
*/

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
typedef pair<int,int> ii;
#define deb(x) cout << #x": " << (x) << endl;

int main(){ _
  lli t; cin >> t;
  while(t--){
    lli n, x; cin >> n >> x;
    vector<lli> v(n), acu(n + 1, 0);
    vector<lli> m(x, 1e18);
    set<lli> s;
    m[0] = 0;
    s.insert(0);
    lli ans = 0;
    fore(i, 0, n){
      cin >> v[i];
      acu[i + 1] = (acu[i] + v[i]) % x;
      m[acu[i + 1]] = min(m[acu[i + 1]], lli(i + 1));
      s.insert(m[acu[i + 1]]);
      s.erase(m[(x - acu[i + 1] + x) % x]);
      if(!s.empty()) {
        ans = max(ans, i + 1 - *s.begin());
      }
      s.insert(m[(x - acu[i + 1] + x) % x]);
    }
    // if(acu[n] % x != 0) cout << n << ENDL;
    if(ans == 0) cout << -1 << ENDL;
    else cout << ans << ENDL;
  }
  return 0;
}
