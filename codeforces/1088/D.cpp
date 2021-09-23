/*
 © 2021-09-23 13:00:20 Franco1010 All Rights Reserved
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
// #define ENDL '\n'
using namespace std;
typedef long double ld;
typedef long long lli;
typedef pair<lli,lli> ii;
typedef vector<lli> vi;
#define deb(x) cout << #x": " << (x) << endl;
lli q(lli x, lli y){
  cout << "? " << x << ' ' << y << endl;
  cin >> x;
  return x;
}
int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  lli st = q(0, 0);
  lli a(0), b(0);
  for(lli i = 29; i >= 0; i--){
    lli aa(q(a ^ (1ll << i), b)), bb(q(a, b ^ (1ll << i)));
    if(aa == bb){
      if(st == 1) a ^= (1ll << i);
      else b ^= (1ll << i);
      st = aa;
    }else if(aa == -1){
      a ^= (1ll << i);
      b ^= (1ll << i);
    }
  }
  cout << "! " << a << ' ' << b << endl;
  return 0;
}
