/*
 © 2020-10-24 09:05:01 Franco1010 All Rights Reserved
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
const lli N = 1e7;
bool p[N];
int main(){ _
  lli t; cin >> t;
  while(t--){
    lli n ;cin >> n;
    vector<vector<lli>> mat(n, vi(n, 0));
    fore(i, 0, n) {
      mat[i][i] = 1;
      if(i + 1 < n) mat[i + 1][i] = 4;
    }
    mat[0][n - 1] = 4;
    for(auto i : mat){
      for(auto j : i) cout << j << ' ';cout << ENDL;
    }
  }
  return 0;
}
