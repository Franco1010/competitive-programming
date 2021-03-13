/*
 © 2021-03-13 03:05:01 Franco1010 All Rights Reserved
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
    vector<ii> ab(n);
    fore(i, 0, n){
      cin >> ab[i].f >> ab[i].s;
    }
    vi v(n); fore(i, 0, n) cin >> v[i];
    lli acu = 0;
    lli last = 0;
    fore(i, 0, n){
      acu += v[i];
      lli w = (ab[i].s - ab[i].f + 1ll) / 2ll;
      lli arr = ab[i].f + acu;
      last = arr;
      lli dep = max(ab[i].s, arr + w);
      acu = dep - ab[i].s;
    }
    cout << last << ENDL;
  }
  return 0;
}
