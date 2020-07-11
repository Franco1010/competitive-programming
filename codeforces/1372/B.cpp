/*
 © 2020-07-11 10:12:07 Franco1010 All Rights Reserved
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

int main(){ _
  lli t; cin >> t;
  while(t--){
    lli n; cin >> n;
    if(n % 2ll == 0) cout << n/2ll << ' ' << n/2ll << ENDL;
    else{
      lli best = n - 1ll;
      lli x = 1, y = n - 1ll;
      for(lli i = 2; i * i <= n; i++){
        if(n % i == 0){
          lli z = i;
          if((n - z) % z == 0 and max((n - z), z) < best){
            best = max(n - z, z);
            x = n - z, y = z;
          }
          z = n / i;
          if((n - z) % z == 0 and max((n - z), z) < best){
            best = max(n - z, z);
            x = n - z, y = z;
          }
        }
      }
      cout << x << ' ' << y << ENDL;
    }
  }
  return 0;
}
