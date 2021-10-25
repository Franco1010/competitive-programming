/*
 © 2021-10-25 01:35:01 Franco1010 All Rights Reserved
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
map<lli,lli> mp;
void f(lli x){
  lli pos = 0;
  while(x){
    if(x & 1ll) mp[pos]++;
    x >>= 1ll;
    pos++;
  }
}
lli gcd(lli a, lli b){
  return b ? gcd(b, a % b) : a;
}
int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  lli t; cin >> t;
  while(t--){
    lli n; cin >> n;
    mp.clear();
    fore(i, 0, n){
      lli x; cin >> x;
      f(x);
    }
    // for(auto i : mp) cout << "(" << i.f << ',' << i.s << ") "; cout << ENDL;
    if(mp.empty()) {
      fore(i, 1, n + 1) cout << i << ' '; cout << ENDL;
    }
    else{
      lli ans = 0;
      for(auto i : mp) ans = gcd(ans, i.s);
      vi res;
      for(lli i = 1; i * i <= ans; i++){
        if(ans % i == 0){
          if(ans / i != i) res.pb(ans / i);
          res.pb(i);
        }
      }
      sort(all(res));
      for(auto i : res) cout << i << ' '; cout << ENDL;
    }
  }
  return 0;
}
