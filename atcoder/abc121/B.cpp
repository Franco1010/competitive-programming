/*
 © 2021-02-01 01:57:52 Franco1010 All Rights Reserved
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
  lli n, m, c; cin >> n >> m >> c;
  vi v(m); for(auto& i : v) cin >> i;
  lli res = 0;
  fore(i, 0, n){
    lli foo = c;
    fore(j, 0, m){
      lli x; cin >> x;
      foo += x * v[j];
    }
    res += foo > 0;
  }
  cout << res << ENDL;
  return 0;
}
