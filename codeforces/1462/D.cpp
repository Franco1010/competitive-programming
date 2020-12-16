/*
 © 2020-12-16 02:25:26 Franco1010 All Rights Reserved
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
const lli INF = 1e18;
lli solve(lli sum, lli x, map<lli,lli>&mp){
  lli foo = 0;
  lli lastp = 0;
  lli cur = x;
  while(cur <= sum){
    if(!mp.count(cur)) return INF;
    foo += (mp[cur] - lastp - 1);
    lastp = mp[cur];
    cur += x;
  }
  return foo;
}
int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  lli t; cin >> t;
  while(t--){
    lli n; cin >> n;
    lli sum = 0;
    map<lli,lli> acu;
    acu[0] = 0;
    vi v(n); fore(i, 0, n) cin >> v[i], sum += v[i], acu[sum] = i + 1;
    lli mn = n - 1;
    for(lli i = 1; i * i <= sum; i++){
      if(sum % i == 0){
        mn = min(mn, solve(sum, i, acu));
        if(sum % (sum / i) == 0 and (sum / i) != i) {
          mn = min(mn, solve(sum, sum/i, acu));
        }
      }
    }
    cout << mn << ENDL;
  }
  return 0;
}
