/*
 © 2020-07-11 10:53:54 Franco1010 All Rights Reserved
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
  lli n; cin >> n;
  lli mx = -1e18, mn =1e18;
  lli cnt = 0;
  lli l = 1;
  vector<lli> v(n);
  fore(i, 0, n) cin >> v[i];
  fore(i, 1, n + 1){
    lli x = v[i - 1];
    if(x != i){
      mx = max(mx, x);
      mn = min(mn, x);
    }else {
      if(l < i){
        if(mn < l or mx >= i){
          cout << 2 << ENDL;
          return;
        }
        cnt++;
        mx = -1e18, mn =1e18;
      }
      l = i + 1;
    }
  }
  if(l < n + 1){
    if(mn < l or mx >= n + 1){
      cout << 2 << ENDL;
      return;
    }
    cnt++;
  }
  if(cnt == 0) cout << 0 << ENDL;
  else cout << 1 << ENDL;
}
int main(){ _
  lli t; cin >> t;
  while(t--){
    solve();
  }
  return 0;
}
