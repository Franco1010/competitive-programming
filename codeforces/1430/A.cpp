/*
 © 2020-10-11 04:05:01 Franco1010 All Rights Reserved
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
  fore(i, 0, n / 7ll + 5ll){
    fore(j, 0, n / 5ll + 5ll){
      lli foo = lli(i) * 7ll + lli(j) * 5ll;
      if(n - foo >= 0 and (n - foo) % 3 == 0){
        cout << (n - foo) / 3ll << ' ' << j << ' ' << i << ENDL;
        return;
      }
    }
  }
  cout << -1 << ENDL;
}
int main(){ _
  lli t; cin >> t;
  while(t--){
    solve();
  }
  return 0;
}
