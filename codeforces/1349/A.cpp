/*
 © 2020-10-15 14:25:25 Franco1010 All Rights Reserved
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
lli gcd(lli a, lli b){
  return b ? gcd(b, a % b) : a;
}
lli lcm(lli a, lli b){
  return a / gcd(a, b) * b;
}
int main(){ _
  lli n; cin >> n;
  vi v(n), pref(n, 1), suff(n, 1);
  fore(i, 0, n) cin >> v[i];
  pref[0] = v[0];
  suff[n - 1] = v[n - 1];
  fore(i, 1, n) pref[i] = gcd(pref[i - 1], v[i]);
  for(lli i = n - 2; i >= 0; i--) suff[i] = gcd(suff[i + 1], v[i]);
  lli res = 1;
  fore(i, 0, n) res = lcm(res, i and i + 1 < n ? gcd(pref[i - 1], suff[i + 1]) : i ? pref[i - 1] : suff[i + 1]);
  cout << res << ENDL;
  return 0;
}
