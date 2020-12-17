/*
 © 2020-12-17 08:35:02 Franco1010 All Rights Reserved
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
    lli par = 0, imp = 0;
    vi v(n); fore(i, 0, n){
      cin >> v[i];
      if(i&1) imp += v[i];
      else par += v[i];
    }
    fore(i, 0, n){
      cout << (imp > par ? i&1 ? v[i] : 1 : i&1 ? 1 : v[i]) << (i + 1 < n ? ' ' : ENDL);
    }
  }
  return 0;
}
