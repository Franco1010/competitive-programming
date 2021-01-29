/*
 © 2021-01-29 08:35:02 Franco1010 All Rights Reserved
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
    string s; cin >> s;
    vector<array<lli,2>> l(n + 1, {0, 0}), r(n + 1, {0, 0}); // l, r
    fore(i, 0, n){
      if(s[i] == 'L') l[i][0]++;
      else l[i][1]++;
      if(i){
        if(s[i] != s[i - 1]){
          if(s[i] == 'L') l[i][0] = l[i - 1][1] + 1;
          else l[i][1] = l[i - 1][0] + 1;
        }
      }
    }
    for(lli i = n - 1; i >= 0; i--){
      if(s[i] == 'L') r[i][0]++;
      else r[i][1]++;
      if(i <= n - 2){
        if(s[i] != s[i + 1]){
          if(s[i] == 'L') r[i][0] = r[i + 1][1] + 1;
          else r[i][1] = r[i + 1][0] + 1;
        }
      }
    }
    // fore(i, 0, n) cout << l[i][0] << ' '; cout << ENDL;
    // fore(i, 0, n) cout << l[i][1] << ' '; cout << ENDL;
    fore(i, 0, n + 1){
      lli foo = 0, bar = 0;
      if(i > 0) foo = l[i - 1][0];
      if(i < n) bar = r[i][1];
      // cout << foo << ' ' << bar << ENDL;
      cout << foo + bar + 1ll << ' ';
    }cout << ENDL;
  }
  return 0;
}
