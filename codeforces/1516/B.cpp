/*
 © 2021-04-21 08:35:01 Franco1010 All Rights Reserved
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
void solve(){
  lli n; cin >> n;
  vi v(n); for(auto& i : v) cin >> i;
  lli foo = 0;
  fore(i, 0, n - 1){
    foo = foo xor v[i];
    {
      lli bar = 0;
      fore(j, i + 1, n){
        if(v[j] == 0) continue;
        if(bar == foo) bar = 0;
        bar = bar xor v[j];
      }
      if(bar == foo){
        cout << "YES" << ENDL;
        return;
      }
    }
  }
  cout << "NO" << ENDL;
}
int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  lli t; cin >> t;
  while(t--){
    solve();
  }
  return 0;
}
