/*
 © 2020-09-04 09:35:02 Franco1010 All Rights Reserved
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
void solve(){
  lli n, x, y; cin >> n >> x >> y;
  fore(i, 1, 51){
    fore(j, 1, 51){
      bool y1 = false, y2 = false;
      lli cnt = n;
      for(lli k = j; cnt--; k += i){
        // cout << k << ' ';
        if(k == x) y1 = true;
        if(k == y) y2 = true;
      }
      // cout << ENDL;
      if(y1 and y2){
        cnt = n;
        for(lli k = j; cnt--; k += i) cout << k << ' '; cout << ENDL;
        return;
      }
    }
  }
}
int main(){ _
  lli t; cin >> t;
  while(t--){
    solve();
  }
  return 0;
}
