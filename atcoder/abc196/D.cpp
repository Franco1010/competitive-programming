/*
 © 2021-03-20 12:38:11 Franco1010 All Rights Reserved
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
lli h, w;
lli mat[20][20];
lli solve(lli a, lli b){
  lli res = 0;
  fore(i, 0, h){
    fore(j, 0, w){
      if(mat[i][j] == 0){
        if(a and j + 1 < w and mat[i][j + 1] == 0){ // hor
          mat[i][j] = mat[i][j + 1] = 1;
          res += solve(a - 1, b);
          mat[i][j] = mat[i][j + 1] = 0;
        }
        if(a and i + 1 < h and mat[i + 1][j] == 0){ // ver
          mat[i][j] = mat[i + 1][j] = 1;
          res += solve(a - 1, b);
          mat[i][j] = mat[i + 1][j] = 0;
        }
        if(b){
          mat[i][j] = 1;
          res += solve(a, b - 1);
          mat[i][j] = 0;
        }
        return res;
      }
    }
  }
  return 1;
}
int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  lli a, b; cin >> h >> w >> a >> b;
  cout << solve(a, b) << ENDL;
  return 0;
}
