/*
 © 2021-02-27 05:57:52 Franco1010 All Rights Reserved
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
lli fpow(lli x, lli y){
  lli res = 1;
  while(y){
    if(y&1ll) res *= x;
    x *= x;
    y >>=1;
  }
  return res;
}
int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  lli k; cin >> k;
  string s, t; cin >> s >> t;
  s.pop_back();
  t.pop_back();
  map<lli,lli> ss, tt;
  for(auto i : s) ss[i - '0']++;
  for(auto i : t) tt[i - '0']++;
  lli sss = 0, ttt = 0;
  fore(i, 1, 10){
    sss += lli(i) * fpow(10, ss[i]);
    ttt += lli(i) * fpow(10, tt[i]);
  }
  lli cur = 0;
  lli den = 0;
  fore(i, 1, 10){
    fore(j, 1, 10){
      if(i == j and k < ss[i] + tt[j] + 2) continue;
      if(i != j and (k < ss[i] + 1 or k < tt[j] + 1)) continue;
      lli ssss = sss - lli(i) * fpow(10, ss[i]);
      ssss += lli(i) * fpow(10, ss[i] + 1);
      lli tttt = ttt - lli(j) * fpow(10, tt[j]);
      tttt += lli(j) * fpow(10, tt[j] + 1);
      if(ssss > tttt){
        if(i != j) cur += (k - ss[i] - tt[i]) * (k - tt[j] - ss[j]);
        else cur += (k - ss[i] - tt[i]) * (k - tt[j] - ss[j] - 1);
      }
      if(i != j) den += (k - ss[i] - tt[i]) * (k - tt[j] - ss[j]);
      else den += (k - ss[i] - tt[i]) * (k - tt[j] - ss[j] - 1);
    }
  }
  cout << fixed << setprecision(7);
  cout << ld(cur) / ld(den) << ENDL;
  return 0;
}
