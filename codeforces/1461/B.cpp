/*
 © 2020-12-11 08:35:08 Franco1010 All Rights Reserved
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
const lli N  = 5e3 + 5;
string mat[N];
lli acu[N][N];
lli n, m;
bool fila(lli h, lli l, lli r){
  lli tot = r - l + 1;
  if(l == 0){
    return acu[h][r] == tot;
  }else{
    return acu[h][r] - acu[h][l - 1] == tot;
  }
}
lli check(lli x, lli y){
  lli res = 0;
  lli h = x;
  lli l = y, r = y;
  bool yes = true;
  while(yes){
    yes = false;
    if(l < 0 or r >= m or h >= n) break;
    if(fila(h, l, r)){
      yes = true;
      res++;
      l--;r++;
      h++;
    }
  }
  return res;
}
int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  lli t; cin >> t;
  while(t--){
    fore(i, 0, N) fore(j, 0, N) acu[i][j] = 0;
    cin >> n >> m;
    fore(i, 0, n) cin >> mat[i];
    fore(i, 0, n){
      if(mat[i][0] == '*') acu[i][0] = 1;
      else acu[i][0] = 0;
      fore(j, 1, m){
        if(mat[i][j] == '*') acu[i][j] = acu[i][j - 1] + 1;
      }
    }
    lli res = 0;
    fore(i, 0, n){
      fore(j, 0, m){
        res += check(i, j);
      }
    }
    cout << res << ENDL;
  }
  return 0;
}
