/*
 © 2020-09-04 09:35:02 Franco1010 All Rights Reserved
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
    lli a, b, x, y; cin >> a >> b >> x >> y;
    lli n; cin >> n;
    if(b - min(b - y, n) < a - min(a - x, n)){
      swap(a, b);
      swap(x, y);
    }
    lli foo = min(a - x, n);
    a -= foo;
    n -= foo;
    foo = min(b - y, n);
    b -= foo;
    n -= foo;
    cout << a * b << ENDL;
  }
  return 0;
}
