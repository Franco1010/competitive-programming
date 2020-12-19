/*
 © 2020-12-19 03:35:02 Franco1010 All Rights Reserved
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
const lli N = 1e3 + 5;
const vector<ii> ch = {{0, -1}, {0, +1}};
const vector<ii> cv = {{-1, 0}, {+1, 0}};
const vector<ii> cc = {{-1, 0}, {0, +1}, {+1, 0}, {0, -1}};
bool mat[5][2 * N][2 * N];
bool leaf[2 * N][2 * N];
bool valid(ii pos, lli dir){
  return 0 <= pos.f and pos.f < 2 * N and 0 <= pos.s and pos.s < 2 * N and !mat[dir][pos.f][pos.s];
}
lli dfs(ii pos = {N, N}, lli dir = 4, lli dis = 0){//up,right,down,left,ext
  if(dis == 0){
    auto aux = leaf[pos.f][pos.s];
    leaf[pos.f][pos.s] = true;
    return !aux;
  }
  lli res = 0;
  mat[dir][pos.f][pos.s] = true;
  {//right
    lli ndir = (dir + 1) % 4;
    ii npos = {pos.f + cc[ndir].f, pos.s + cc[ndir].s};
    if(valid(npos, ndir)){
      res += dfs(npos, ndir, dis - 1);
    }
  }
  {//left
    lli ndir = (dir + 3) % 4;
    ii npos = {pos.f + cc[ndir].f, pos.s + cc[ndir].s};
    if(valid(npos, ndir)){
      res += dfs(npos, ndir, dis - 1);
    }
  }
  return res;
}
int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  lli n; cin >> n;
  lli l = 2ll * ((n + 1ll) / 2ll) + 1ll;
  if(n&1) cout << (l * l) / 2ll << ENDL;
  else cout << ((l + 1ll) / 2ll) * ((l + 1ll) / 2ll) << ENDL;
  return 0;
}
