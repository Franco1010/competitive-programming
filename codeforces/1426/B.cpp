/*
 © 2020-09-28 03:05:02 Franco1010 All Rights Reserved
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
lli mat[2][2];
int main(){ _
  lli t; cin >> t;
  while(t--){
    lli n, m; cin >> n >> m;
    bool yes = false;
    fore(k, 0, n){
      fore(i, 0, 2){
        fore(j, 0, 2){
          cin >> mat[i][j];
        }
      }
      if(mat[0][1] == mat[1][0]) yes = true;
    }
    if(yes and m % 2 == 0) cout << "YES" << ENDL;
    else cout << "NO" << ENDL;
  }
  return 0;
}
