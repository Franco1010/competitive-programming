/*
 © 2020-10-11 08:18:43 Franco1010 All Rights Reserved
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

int main(){ _
  vi v(4); fore(i, 0, 4) cin >> v[i];
  for(lli mask = 0; mask < (1ll << 4); mask++){
    lli foo = 0, bar = 0;
    for(lli i = 0; i < 4; i++){
      if(mask & (1ll << i)) foo += v[i];
      else bar += v[i];
    }
    if(foo == bar){
      cout << "Yes" << ENDL;
      return 0;
    }
  }
  cout << "No" << ENDL;
  return 0;
}
