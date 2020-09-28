/*
 © 2020-09-28 16:00:39 Franco1010 All Rights Reserved
*/

#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("avx,avx2,fma")
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
lli f(vi a, vi b, vector<ii> &v){
  lli foo = 0;
  for(auto i : v){
    lli bar = min(a[i.f], b[i.s]);
    a[i.f] -= bar;
    b[i.s] -= bar;
    foo += bar;
  }
  return foo;
}
int main(){ _
  lli n; cin >> n;
  vector<lli> a(3), b(3);
  cin >> a[0] >> a[2] >> a[1];
  cin >> b[0] >> b[2] >> b[1];
  vector<ii> v = {{0, 0}, {0, 1}, {1, 1}, {1, 2}, {2, 2}, {2, 0}};
  sort(all(v));
  lli mx = min(a[0], b[2]) + min(a[1], b[0]) + min(a[2], b[1]);
  lli mn = 0;
  do mn = max(mn, f(a, b, v)); while(next_permutation(all(v)));
  cout << n - mn << ' ' << mx << ENDL;
  return 0;
}
