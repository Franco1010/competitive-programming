/*
 © 2021-01-25 01:59:18 Franco1010 All Rights Reserved
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
  lli n, k; cin >> n >> k;
  vector<ii> v(n); fore(i, 0, n) cin >> v[i].f >> v[i].s;
  sort(all(v), [&](const ii& a, const ii& b){
    return a.f < b.f;
  });
  lli acu = 0;
  for(auto [a, b] : v){
    acu += b;
    if(acu >= k){
      cout << a << ENDL;
      return 0;
    }
  }
  return 0;
}
