/*
 © 2020-09-24 09:35:01 Franco1010 All Rights Reserved
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
    map<lli,lli> mp;
    fore(i, 0, n){
      lli x; cin >> x;
      for(lli i = 33; i >= 0; i--){
        if(x & (1ll << i)){
          mp[i]++;
          break;
        }
      }
    }
    lli res = 0;
    for(auto i : mp){
      res += i.s * (i.s - 1ll) / 2ll;
    }
    cout << res << ENDL;
  }
  return 0;
}
