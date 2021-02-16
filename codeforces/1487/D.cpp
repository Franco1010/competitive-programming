/*
 © 2021-02-15 08:35:01 Franco1010 All Rights Reserved
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
bool f(lli n, lli x){
  return (x * x + 1ll) <= 2ll * n;
}
lli bs(lli n){
  lli pos = 0;
  for(lli p = 1e9; p ; p /= 2ll) while(2ll * (pos + p) + 1ll <= n and f(n, 2ll * (pos + p) + 1ll)) pos += p;
  return pos;
}
int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  lli t; cin >> t;
  while(t--){
    lli n; cin >> n;
    cout << bs(n) << ENDL;
  }
  return 0;
}
