/*
 © 2020-11-21 08:35:01 Franco1010 All Rights Reserved
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
lli div(lli x){
  lli mn = -1;
  for(lli i = 2; i * i <= x; i++){
    if(x % i == 0){
      if(mn == -1) mn = i;
      if(x % (x/i) == 0) mn = min(mn, x / i);
    }
  }
  return mn;
}
int main(){ _
  lli t; cin >> t;
  while(t--){
    lli x; cin >> x;
    if(x == 1) cout << 0 << ENDL;
    else if(x == 2) cout << 1 << ENDL;
    else if(x == 3) cout << 2 << ENDL;
    else cout << 2ll + (x&1ll) << ENDL;
  }
  return 0;
}
