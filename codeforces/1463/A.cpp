/*
 © 2020-12-17 08:35:02 Franco1010 All Rights Reserved
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
lli f(lli n){
  return n + (n / 7ll) * 2ll;
}
lli bs(lli x){
  lli pos = 3e8;
  for(lli p = 3e8; p > 0; p/=2ll) while(pos - p >= 0 and f(pos - p) >= x) pos -= p;
  return pos;
}
int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  lli t; cin >> t;
  while(t--){
    lli a, b, c; cin >> a >> b >> c;
    auto foo = bs(a + b + c);
    if(f(foo) == a + b + c and foo % 7ll == 0){
      if(foo / 7ll > a or foo / 7ll > b or foo / 7ll > c) cout << "NO" << ENDL;
      else cout << "YES" << ENDL;
    }else cout << "NO" << ENDL;
  }
  return 0;
}
