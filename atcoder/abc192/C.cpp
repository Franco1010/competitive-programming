/*
 © 2021-02-20 06:01:23 Franco1010 All Rights Reserved
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
lli g1(lli n){
  string foo = to_string(n);
  sort(rbegin(foo), rend(foo));
  return stoll(foo);
}
lli g2(lli n){
  string foo = to_string(n);
  sort(all(foo));
  return stoll(foo);
}
lli f(lli n){
  return g1(n) - g2(n);
}
int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  lli n, k; cin >> n >> k;
  while(k--){
    n = f(n);
  }
  cout << n << ENDL;
  return 0;
}
