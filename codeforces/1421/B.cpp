/*
 © 2020-10-18 04:07:56 Franco1010 All Rights Reserved
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
const lli N = 205;
string mat[N];
int main(){ _
  lli t; cin >> t;
  while(t--){
    lli n; cin >> n;
    vector<ii> pos = {{0, 1}, {1, 0}, {n - 2, n - 1}, {n - 1, n - 2}};
    fore(i, 0, n){
      cin >> mat[i];
    }
    vi res1;
    fore(i, 0, 2){
      auto x = pos[i];
      if(mat[x.f][x.s] != '0') res1.pb(i);
    }
    fore(i, 2, 4){
      auto x = pos[i];
      if(mat[x.f][x.s] != '1') res1.pb(i);
    }
    vi res2;
    fore(i, 0, 2){
      auto x = pos[i];
      if(mat[x.f][x.s] != '1') res2.pb(i);
    }
    fore(i, 2, 4){
      auto x = pos[i];
      if(mat[x.f][x.s] != '0') res2.pb(i);
    }
    if(sz(res1) < sz(res2)){
      cout << sz(res1) << ENDL;
      for(auto i : res1) cout << pos[i].f + 1 << ' ' << pos[i].s + 1 << ENDL;
    }else{
      cout << sz(res2) << ENDL;
      for(auto i : res2) cout << pos[i].f + 1 << ' ' << pos[i].s + 1 << ENDL;
    }
  }
  return 0;
}
