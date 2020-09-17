/*
 © 2020-09-17 12:15:32 Franco1010 All Rights Reserved
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
lli g(lli n){
  return (n * (n + 1ll)) / 2ll;
}
int main(){ _
  lli n, k; cin >> n >> k;
  lli lim = 60ll * 4ll;
  lli pos = 0;
  for(lli p = n; p > 0; p /= 2){
    while(pos + p <= n and g(pos + p) * 5 <= lim - k) pos += p;
  }
  cout << pos << ENDL;
  return 0;
}
