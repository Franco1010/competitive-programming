/*
 © 2021-04-12 09:35:01 Franco1010 All Rights Reserved
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
lli pot[15];
lli until(lli x, lli d, lli m){
  do{
    x *= m;
  }while(x / pot[d] == 0);
  return x;
}
int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  pot[1] = 1; fore(i, 2, 15) pot[i] = pot[i - 1] * 10ll;
  lli t; cin >> t;
  while(t--){
    lli a, b, c; cin >> a >> b >> c;
    lli g = until(1, c, 2);
    lli x = until(g, a, 2);
    lli y = until(g, b, 3);
    cout << x << ' ' << y << ENDL;
  }
  return 0;
}
