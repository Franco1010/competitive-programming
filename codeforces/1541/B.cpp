/*
 © 2021-06-25 10:35:01 Franco1010 All Rights Reserved
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
    lli n; cin >> n;
    vi mp(2ll * n + 5, -1);
    fore(i, 0, n){
      lli x; cin >> x;
      mp[x] = i + 1;
    }
    lli ans = 0;
    for(lli x = 1; x <= 2ll * n + 1ll; x++){
      for(lli i = 1; i * i <= x; i++){
        if(x%i == 0){
          lli bar = x / i;
          if(i != bar and mp[i] != -1 and mp[bar] != -1){
            if(x == mp[i] + mp[bar]) ans++;
          }
        }
      }
    }
    cout << ans << ENDL;
  }
  return 0;
}
