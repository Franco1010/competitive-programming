/*
 © 2020-10-20 16:50:02 Franco1010 All Rights Reserved
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
lli g(lli x){
  return x * (x + 1ll) / 2ll;
}
int main(){ _
  lli t; cin >> t;
  while(t--){
    string s; cin >> s;
    lli res = s[0] - '0' - 1ll;
    res *= g(4);
    res += g(sz(s));
    cout << res << ENDL;
  }
  return 0;
}
