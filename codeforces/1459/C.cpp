/*
 © 2020-12-19 03:35:02 Franco1010 All Rights Reserved
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
// #define bint __int128;
lli gcd(lli a, lli b){
  return b ? gcd(b, a % b) : a;
}
lli lcm(lli a, lli b){
  return a / gcd(a, b) * b;
}
int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  lli n, m; cin >> n >> m;
  vi v(n); fore(i, 0, n) cin >> v[i];
  lli g(0);
  fore(i, 1, n) g = gcd(abs(v[i] - v[0]), g);
  fore(i, 0, m){
    lli x; cin >> x;
    lli foo = v[0] + x;
    foo = gcd(foo, g);
    cout << foo << (i + 1 == m ? ENDL : ' ');
  }
  return 0;
}
