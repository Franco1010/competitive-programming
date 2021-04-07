/*
 © 2021-04-07 04:10:41 Franco1010 All Rights Reserved
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
// #define ENDL '\n'
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
  vi v(n); for(auto& i : v) cin >> i;
  vector<ii> ord;
  fore(i, 0, n){
    fore(j, i + 1, n){
      ord.pb({i, j});
    }
  }
  sort(all(ord), [&](const ii& a, const ii& b){
    return abs(v[a.f] - v[a.s]) > abs(v[b.f] - v[b.s]);
  });
  for(auto i : ord){
    if(v[i.s] > v[i.f]) swap(i.f, i.s);
    cout << "? " << i.f + 1 << ' ' << i.s + 1 << endl;
    string foo; cin >> foo;
    if(foo == "Yes"){
      cout << "! " << i.f + 1 << ' ' << i.s + 1 << endl;
      exit(0);
    }
  }
  cout << "! 0 0" << endl;
  return 0;
}
