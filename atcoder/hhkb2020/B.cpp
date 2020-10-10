/*
 © 2020-10-10 06:54:50 Franco1010 All Rights Reserved
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
const lli N = 105;
string mat[N];
lli h, w;
const ii c[4] = {{-1, 0}, {+1, 0}, {0, +1}, {0, -1}};
bool valid(lli x, lli y){
  return 0 <= x and x < h and 0 <= y and y < w and mat[x][y] == '.';
}
lli solve(lli x, lli y){
  lli res = 0;
  for(auto cc : c){
    ii n = {x + cc.f, y + cc.s};
    if(valid(n.f, n.s)) res++;
  }
  return res;
}
int main(){ _
  cin >> h >> w;
  fore(i, 0, h) cin >> mat[i];
  lli res = 0;
  fore(i, 0, h){
    fore(j, 0, w){
      if(mat[i][j] == '#') continue;
      lli foo = solve(i, j);
      res += foo;
    }
  }
  cout << res/2ll << ENDL;
  return 0;
}
