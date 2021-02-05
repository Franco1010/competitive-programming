/*
 © 2021-02-05 08:35:01 Franco1010 All Rights Reserved
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
    ii p; cin >> p.f >> p.s;
    ii cur = {0, 0};
    string s; cin >> s;
    map<char,lli> mp;
    for(auto i : s){
      mp[i]++;
      if(i == 'U') cur.s++;
      if(i == 'D') cur.s--;
      if(i == 'R') cur.f++;
      if(i == 'L') cur.f--;
    }
    ii dif = ii{p.f - cur.f, p.s - cur.s};
    while(dif.f > 0 and mp['L']) dif.f--, mp['L']--;
    while(dif.f < 0 and mp['R']) dif.f++, mp['R']--;
    while(dif.s > 0 and mp['D']) dif.s--, mp['D']--;
    while(dif.s < 0 and mp['U']) dif.s++, mp['U']--;
    if(dif == ii{0, 0}) cout << "YES" << ENDL;
    else cout << "NO" << ENDL;
  }
  return 0;
}
