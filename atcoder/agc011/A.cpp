/*
 © 2021-03-09 01:16:13 Franco1010 All Rights Reserved
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
lli gcd(lli x, lli y){ return y ? gcd(y, x % y) : x; }
int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  lli n, c, k; cin >> n >> c >> k;
  vi v(n); for(auto& i : v) cin >> i;
  sort(all(v));
  lli last = -1;
  lli cur = 0;
  lli ans = 0;
  fore(i, 0, n){
    if(last != -1){
      if(v[i] - last > k){
        cur = 1;
        last = v[i];
        ans++;
        continue;
      }
      cur++;
      if(cur > c){
        cur = 1;
        last = v[i];
        ans++;
      }
    }else last = v[i], cur = 1;
  }
  cout << ans + 1 << ENDL;
  return 0;
}
