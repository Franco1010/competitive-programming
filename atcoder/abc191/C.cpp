/*
 © 2021-02-06 05:57:57 Franco1010 All Rights Reserved
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
vector<ii> dir = {{-1, 0}, {0, +1}, {+1, 0}, {0, -1}};
lli n, m;
vector<string> mat;
bool val(lli x, lli y){
  return 0 <= x and x < n and 0 <= y and y <= m and mat[x][y] != '#';
}
lli dfs(ii u, int d = 1, bool ini = false){
  // cout << u.f << ' ' << u.s << ": " << d << ENDL;
  // for(auto i : mat) cout << i << ENDL;
  // cout << ENDL;
  if(!ini and mat[u.f][u.s] == '*') return 0;
  {//right
    ii ndir = {dir[(d + 1 + 4)%4].f + u.f, dir[(d + 1 + 4)%4].s + u.s};
    if(val(ndir.f, ndir.s)){
      return dfs(ndir, (d + 1 + 4)%4) + 1;
    }
  }
  {
    ii ndir = {dir[d].f + u.f, dir[d].s + u.s};
    if(val(ndir.f, ndir.s)){
      return dfs(ndir, d);
    }
  }
  {//left
    ii ndir = {dir[(d - 1 + 4)%4].f + u.f, dir[(d - 1 + 4)%4].s + u.s};
    if(val(ndir.f, ndir.s)){
      return dfs(ndir, (d - 1 + 4)%4) + 1;
    }
  }
  {//back
    ii ndir = {dir[(d + 2 + 4)%4].f + u.f, dir[(d + 2 + 4)%4].s + u.s};
    if(val(ndir.f, ndir.s)){
      return dfs(ndir, (d + 2 + 4)%4) + 2;
    }
  }
  return 0;
}
int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  cin >> n >> m;
  mat.resize(n);
  fore(i, 0, n) cin >> mat[i];
  fore(i, 0, n){
    fore(j, 0, m){
      if(mat[i][j] == '#'){
        mat[i - 1][j] = '*';
        cout << dfs({i - 1, j}, 1, true) << ENDL;
        return 0;
      }
    }
  }
  return 0;
}
