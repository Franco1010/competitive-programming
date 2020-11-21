/*
 © 2020-11-21 08:35:01 Franco1010 All Rights Reserved
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
    lli n, q; cin >> n >> q;
    string s; cin >> s;
    vector<ii> pref(n + 1, {0, 0}), suff(n + 1, {0, 0});
    fore(i, 1, n + 1){
      pref[i] = pref[i - 1];
      if(s[i - 1] == '0') pref[i].f++;
      else pref[i].s++;
    }
    for(lli i = n - 1; i >= 0; i--){
      suff[i] = suff[i + 1];
      if(s[i] == '0') suff[i].f++;
      else suff[i].s++;
    }
    while(q--){
      lli l, r; cin >> l >> r;
      l--, r--;
      bool yes = false;
      if(s[l] == '0') yes |= pref[l].f;
      if(s[l] == '1') yes |= pref[l].s;
      if(s[r] == '0') yes |= suff[r + 1].f;
      if(s[r] == '1') yes |= suff[r + 1].s;
      if(yes) cout << "YES" << ENDL;
      else cout << "NO" << ENDL;
    }
  }
  return 0;
}
