/*
 © 2020-10-17 08:05:17 Franco1010 All Rights Reserved
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
    string s; cin >> s;
    string res = "";
    for(auto i : s){
      if(!res.empty() and res.back() == 'A' and i == 'B') res.pop_back();
      else res.pb(i);
    }
    lli ans = sz(res);
    lli cur = 0;
    for(auto i : res){
      if(i == 'B') cur++;
      else{
        ans -= 2ll * (cur / 2ll);
        cur = 0;
      }
    }
    ans -= 2ll * (cur / 2ll);
    cout << ans << ENDL;
  }
  return 0;
}
