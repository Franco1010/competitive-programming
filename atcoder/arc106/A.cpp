/*
 © 2020-10-24 07:00:00 Franco1010 All Rights Reserved
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
lli fpow(lli x, lli y){
  lli r = 1;
  while( y > 0 ){
    if( y & 1 ) r = r * x;
    x = x * x;
    y >>= 1;
  }
  return r;
}
const lli LIM = 1e18;
int main(){ _
  lli n; cin >> n;
  lli tres = 3;
  fore(i, 1, 40){
    lli cinco = 5;
    fore(j, 1, 40){
      if(tres + cinco == n){
        cout << i << ' ' << j << ENDL;
        return 0;
      }
      if(cinco * 5ll <= LIM - tres) cinco *= 5ll;
    }
    if(tres * 3ll <= LIM) tres *= 3ll;
    else break;
  }
  cout << -1 << ENDL;
  return 0;
}
