/*
 © 2021-01-08 08:35:02 Franco1010 All Rights Reserved
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
lli f(lli a, lli b, lli c){
  if(a > b and c > b) return 1;
  if(a < b and c < b) return 1;
  return 0;
}
int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  lli t; cin >> t;
  while(t--){
    lli n; cin >> n;
    lli res = 0;
    vi v(n); fore(i, 0, n) cin >> v[i];
    fore(i, 1, n - 1){
      res += f(v[i - 1], v[i], v[i + 1]);
    }
    lli ans = res;
    fore(i, 1, n - 1){
      fore(j, -2, +3){
        if(i + j >= 0 and i + j < n){
          lli tmp = v[i + j];
          lli foo = res;
          foo -= f(v[i - 1], v[i], v[i + 1]);
          foo += f(v[i - 1], tmp, v[i + 1]);
          if(i > 1){
            foo -= f(v[i - 2], v[i - 1], v[i]);
            foo += f(v[i - 2], v[i - 1], tmp);
          }
          if(i + 2 < n){
            foo -= f(v[i], v[i + 1], v[i + 2]);
            foo += f(tmp, v[i + 1], v[i + 2]);
          }
          ans = min(ans, foo);
        }
      }
    }
    cout << ans << ENDL;
  }
  return 0;
}
