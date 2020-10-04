/*
 © 2020-10-04 11:05:01 Franco1010 All Rights Reserved
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
lli mat[N][N];
vector<lli> mm[N][N];
lli f(vector<lli> &v, lli x){
  lli res = 0;
  for(auto i : v) res += abs(i - x);
  return res;
}
lli test(vector<lli> &v){
  lli l = 0, r = 1e9;
  while(r - l > 2){
    lli m1 = l + (r - l) / 3;
    lli m2 = r - (r - l) / 3;
    if(f(v, m1) < f(v, m2)) r = m2;
    else l = m1;
  }
  lli res = 1e18;
  for(lli i = l; i <= r; i++) res = min(res, f(v, i));
  return res;
}
int main(){ _
  lli t; cin >> t;
  while(t--){
    lli n, m; cin >> n >> m;
    fore(i, 0, n){
      fore(j, 0, m){
        cin >> mat[i][j];
        mm[i][j].clear();
      }
    }
    for(lli i = n - 1; i >= 0; i--){
      for(lli j =  m - 1; j >= 0; j--){
        if(i >= (n + 1ll) / 2ll or j >= (m + 1ll) / 2ll){
          if(i >= (n + 1ll) / 2ll and j >= (m + 1ll) / 2ll) mm[n - i - 1][m - j - 1].pb(mat[i][j]);
          else if(i >= (n + 1ll) / 2ll) mm[n - i - 1][j].pb(mat[i][j]);
          else if(j >= (m + 1ll) / 2ll) mm[i][m - j - 1].pb(mat[i][j]);
          mat[i][j] = 0;
        }else mm[i][j].pb(mat[i][j]);
      }
    }
    lli res = 0;
    fore(i, 0, n){
      fore(j, 0, m) res += test(mm[i][j]);
    }
    cout << res << ENDL;
  }
  return 0;
}
