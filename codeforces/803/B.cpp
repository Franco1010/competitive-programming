/*
 © 2021-05-16 01:45:21 Franco1010 All Rights Reserved
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
int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  lli n; cin >> n;
  vi v(n); for(auto& i : v) cin >> i;
  vi l(n, INF),  r(n, INF);
  lli last = -INF;
  fore(i, 0, n){
    if(v[i] == 0) last = i;
    l[i] = min(l[i], i - last);
  }
  last = INF;
  for(lli i = n - 1; i >= 0; i--){
    if(v[i] == 0) last = i;
    r[i] = min(r[i], last - i);
  }
  fore(i, 0, n) cout << min(l[i], r[i]) << ' '; cout << ENDL;
  return 0;
}
