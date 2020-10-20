/*
 © 2020-10-20 16:50:02 Franco1010 All Rights Reserved
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
typedef unsigned long long lli;
typedef pair<lli,lli> ii;
typedef vector<lli> vi;
#define deb(x) cout << #x": " << (x) << endl;
lli fac(lli n){
  lli res = 1;
  fore(i, 1, n + 1) res *= lli(i);
  return res;
}
int main(){ _
  lli n; cin >> n;
  lli res = fac(n);
  res /= fac(n / 2);
  res /= fac(n / 2);
  res /= 2ll;
  res *= fac(n / 2 - 1);
  res *= fac(n / 2 - 1);
  cout << res << ENDL;
  return 0;
}
