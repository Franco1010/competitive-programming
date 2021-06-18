/*
 © 2021-06-18 09:35:01 Franco1010 All Rights Reserved
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
struct Node{
  ii a;
  ii b;
  lli dis;
};
int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  lli t; cin >> t;
  while(t--){
    lli n, m, x, y; cin >> n >> m >> x >> y;
    vector<Node> v;
    v.pb({{n, m}, {1, 1}, 2ll*abs(n - x) + 2ll*abs(m - y) + 2ll*abs(x - 1) + 2ll*abs(y - 1)});
    v.pb({{n, 1}, {1, m}, 2ll*abs(n - x) + 2ll*abs(1 - y) + 2ll*abs(x - 1) + 2ll*abs(y - m)});
    v.pb({{n, m}, {1, m}, 2ll*abs(n - x) + 2ll*abs(1 - x) + 2ll*abs(m - y)});
    v.pb({{1, 1}, {1, m}, 2ll*abs(1 - x) + 2ll*abs(1 - y) + 2ll*abs(m - y)});
    v.pb({{1, 1}, {n, 1}, 2ll*abs(1 - x) + 2ll*abs(n - x) + 2ll*abs(1 - y)});
    v.pb({{n, m}, {n, 1}, 2ll*abs(n - x) + 2ll*abs(1 - y) + 2ll*abs(m - y)});
    sort(all(v), [&](const Node& a, const Node& b){
      return a.dis > b.dis;
    });
    cout << v.front().a.f << ' ' << v.front().a.s << ' ' << v.front().b.f << ' ' << v.front().b.s << ENDL;
  }
  return 0;
}
