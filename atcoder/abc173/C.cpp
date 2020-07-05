/*
 © 2020-07-05 06:57:04 Franco1010 All Rights Reserved
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

int main(){ _
  lli h, w, k; cin >> h >> w >> k;
  vector<string> m(h);
  fore(i, 0, h){
    cin >> m[i];
  }
  lli ans = 0;
  fore(x, 0, 1ll << h){
    fore(y, 0, 1ll << w){
      lli aux = 0;
      fore(i, 0, h){
        fore(j, 0, w){
          if((x & (1ll << i)) and (y & (1ll << j))){
            if(m[i][j] == '#') aux++;
          }
        }
      }
      if(aux == k) ans++;
    }
  }
  cout << ans << ENDL;
  return 0;
}
