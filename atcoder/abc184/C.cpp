/*
 © 2020-11-22 11:05:16 Franco1010 All Rights Reserved
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
  lli a, b; cin >> a >> b;
  lli c, d; cin >> c >> d;
  lli x = labs(a - c), y = labs(b - d);
  // if(y < x) swap(a, c), swap(b, d);

  if(x == 0 and y == 0) cout << 0 << ENDL;
  else if(x + y <= 3 or x == y) cout << 1 << ENDL;
  else if(x + y <= 6 or abs(x - y) <= 3 or (x + y) % 2 == 0) cout << 2 << ENDL;
  else cout << 3 << ENDL;
  return 0;
}
