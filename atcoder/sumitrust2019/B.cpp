/*
 © 2021-02-01 01:57:52 Franco1010 All Rights Reserved
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
lli f(lli n, lli x){
  x *= 108ll;
  x -= x % 100ll;
  n *= 100ll;
  return x == n ? 1 : x > n ? 2 : 0;
}
lli bs(lli n){
  lli pos = 1;
  while(!f(n, pos)) pos *= 2;
  for(lli p = pos; p; p /= 2) while(pos - p >= 0 and f(n, pos - p)) pos -= p;
  return pos;
}
int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  lli n; cin >> n;
  if(f(n, bs(n)) == 1) cout << bs(n) << ENDL;
  else cout << ":(" << ENDL;
  return 0;
}
