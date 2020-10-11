/*
 © 2020-10-11 04:05:01 Franco1010 All Rights Reserved
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
    string s; cin >> s;
    vi v;
    lli acu = 0;
    char x = '$';
    for(auto i : s){
      if(i != x){
        if(acu) v.pb(acu);
        acu = 1;
        x = i;
      }else acu++;
    }
    if(acu) v.pb(acu);
    // for(auto i : v) cout << i << ' '; cout << ENDL;
    lli l = 0, r = 0;
    lli res = 0;
    while(l < sz(v) and l <= r){
      while(r < sz(v) and v[r] == 1) r++;
      if(r == sz(v)) l++;
      else v[r]--;
      if(l == r) r++;
      l++;
      res++;
    }
    cout << res << ENDL;
  }
  return 0;
}
