/*
 © 2021-04-03 16:45:01 Franco1010 All Rights Reserved
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
  lli n; cin >> n;
  lli ans = 0;
  vector<ii> v(n); for(auto& i : v) cin >> i.f >> i.s, ans += i.s;
  sort(all(v));
  lli mx = v[0].f + v[0].s;
  fore(i, 1, n){
    ans += max(0ll, v[i].f - mx);
    mx = max(mx, v[i].f + v[i].s);
  }
  cout << ans << ENDL;
  return 0;
}
