/*
 © 2020-08-29 06:57:42 Franco1010 All Rights Reserved
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
  string s, t; cin >> s >> t;
  lli res = 1e18;
  fore(i, 0, sz(s) - sz(t) + 1){
    lli foo = 0;
    fore(j, 0, sz(t)){
      if(s[i + j] != t[j]) foo++;
    }
    res = min(res, foo);
  }
  cout << res << ENDL;
  return 0;
}
