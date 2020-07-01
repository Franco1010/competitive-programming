/*
 © 2020-07-01 08:35:02 Franco1010 All Rights Reserved
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
  if(n % 2 == 0) return (n / 2ll) * (n + 1ll);
  else return ((n + 1ll) / 2ll) * n;
}
int main(){ _
  lli t; cin >> t;
  while(t--){
    lli n, r; cin >> n >> r;
    lli k = min(n - 1ll, r);
    k = g(k);
    if(r >= n)k++;
    cout << k << ENDL;
  }
  return 0;
}
