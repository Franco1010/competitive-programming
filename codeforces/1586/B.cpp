/*
 © 2021-10-17 06:05:02 Franco1010 All Rights Reserved
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

int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  lli t; cin >> t;
  while(t--){
    lli n, m; cin >> n >> m;
    vector<bool> v(n, true);
    fore(i, 0, m){
      lli x, y, z; cin >> x >> y >> z; y--;
      v[y] = false;
    }
    lli op = 0;
    fore(i, 0, n){
      if(v[i] == true){
        op = i;
        break;
      }
    }
    fore(i, 0, n){
      if(i == op) continue;
      cout << op + 1 << ' ' << i + 1 << ENDL;
    }
  }
  return 0;
}
