/*
 © 2021-02-28 07:35:23 Franco1010 All Rights Reserved
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
string d2b(lli x){
  string res = "";
  while(x){
    res.pb(x%2ll + '0');
    x /= 2ll;
  }
  reverse(all(res));
  return res;
}
int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  lli q; cin >> q;
  while(q--){
    lli u, v; cin >> u >> v;
    if(v >= u){
      lli a = 0, b = 0;
      bool yes = true;
      fore(i, 0, 30){
        if(u&(1ll << lli(i))) a++;
        if(v&(1ll << lli(i))) b++;
        if(a < b){
          yes = false;
          break;
        }
      }
      if(yes) cout << "YES" << ENDL;
      else cout << "NO" << ENDL;
    }
    else cout << "NO" << ENDL;
  }
  return 0;
}
