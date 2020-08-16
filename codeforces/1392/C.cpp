/*
 © 2020-08-16 09:35:02 Franco1010 All Rights Reserved
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
  lli t; cin >> t;
  while(t--){
    lli n; cin >> n;
    vector<lli> v(n);
    lli mx = 0;
    fore(i, 0, n){
      lli x; cin >> x;
      mx = max(mx, x);
      v[i] = mx - x;
    }
    lli res = 0;
    lli acu = 0;
    // for(auto i : v) cout << i << ' '; cout << ENDL;
    for(auto &i : v){
      if(i == 0){
        // res += acu;
        acu = 0;
      }else{
        if(i > acu){
          res += i - acu;
          acu = i;
        }
        if(i < acu){
          acu= i;
        }
      }
    }
    cout << res << ENDL;
  }
  return 0;
}
