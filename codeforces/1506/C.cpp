/*
 © 2021-03-25 08:35:02 Franco1010 All Rights Reserved
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
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  lli t; cin >> t;
  while(t--){
    string a, b; cin >> a >> b;
    lli res = sz(a) + sz(b);
    fore(i, 0, sz(a)){
      fore(j, i, sz(a)){
        fore(k, 0, sz(b)){
          if(b[k] != a[i] or k + j - i >= sz(b)) continue;
          bool yes = true;
          fore(l, 0, j - i + 1){
            if(b[k + l] != a[i + l]){
              yes = false;
              break;
            }
          }
          if(yes) res = min(res, sz(a) + sz(b) - 2ll * (j - i + 1ll));
        }
      }
    }
    cout << res << ENDL;
  }
  return 0;
}
