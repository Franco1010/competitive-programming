/*
 © 2021-01-14 08:35:01 Franco1010 All Rights Reserved
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
lli gcd(lli a, lli b){
  return b ? gcd(b, a % b) : a;
}
lli lcm(lli a, lli b){
  return a / gcd(a, b) * b;
}
void solve(){
  string a, b; cin >> a >> b;
  string foo = "";
  lli pos = 0;
  while(pos < sz(a) * sz(b)){
    if(a[pos%sz(a)] != b[pos%sz(b)]){
      cout << -1 << ENDL;
      return;
    }
    foo.pb(a[pos%sz(a)]);
    pos++;
    if(pos%sz(a) == 0 and pos%sz(b) == 0) break;
  }
  if(pos%sz(a) == 0 and pos%sz(b) == 0) cout << foo << ENDL;
  else cout << -1 << ENDL;
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
