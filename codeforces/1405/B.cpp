/*
 © 2020-09-07 15:00:02 Franco1010 All Rights Reserved
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
lli s3(vector<ii> pos, vector<ii> neg){
  lli res = 0, l = 0, r = 0;
  while(l < sz(pos) and r < sz(neg)){
    while(r < sz(neg) and neg[r].f < pos[l].f) r++;
    if(r == sz(neg)) break;
    lli aux = min(pos[l].s, -neg[r].s);
    pos[l].s -= aux;
    neg[r].s += aux;
    if(pos[l].s == 0) l++;
    if(neg[r].s == 0) r++;
  }
  for(auto i : pos) res += i.s;
  return res;
}
int main(){ _
  lli t; cin >> t;
  while(t--){
    lli n; cin >> n;
    vector<ii> neg, pos;
    fore(i, 0, n){
      lli x; cin >> x;
      if(x > 0) pos.pb({i, x});
      else if(x < 0) neg.pb({i, x});
    }
    // cout << min(s1(pos, neg), s2(pos, neg)) << ENDL;
    cout << s3(pos, neg) << ENDL;
  }
  return 0;
}
