/*
 © 2020-08-15 21:07:12 Franco1010 All Rights Reserved
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
  lli x, k, d; cin >> x >> k >> d;
  x = labs(x);
  lli foo = x / d;
  if(k < foo) cout << labs(x - k * d) << ENDL;
  else if((k - foo) % 2 == 0) cout << labs(x - foo * d) << ENDL;
  else if(k >= foo + 1) cout << labs(x - (foo + 1ll) * d) << ENDL;
  else cout << x << ENDL;
  return 0;
}
