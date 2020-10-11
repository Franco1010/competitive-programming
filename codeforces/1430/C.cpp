/*
 © 2020-10-11 04:05:01 Franco1010 All Rights Reserved
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
    cout << 2 << ENDL;
    if(n == 2){
      cout << 1 << ' ' << 2 << ENDL;
    }else{
      cout << n - 2ll << ' ' << n << ENDL;
      cout << n - 1ll << ' ' << n - 1ll << ENDL;
      n--;
      while(n > 2ll){
        cout << n << ' ' << n - 2ll << ENDL;
        n--;
      }
    }
  }
  return 0;
}
