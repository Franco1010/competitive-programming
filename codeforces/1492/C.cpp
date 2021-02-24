/*
 © 2021-02-23 19:45:02 Franco1010 All Rights Reserved
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
int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  lli n, m; cin >> n >> m;
  string s, t; cin >> s >> t;
  vi l(m,-1), r(m,-1);
  lli cur = 0;
  fore(i, 0, n) {
    if(s[i] == t[cur]) l[cur++] = i;
    if(cur >= m) break;
  }
  cur = m - 1;
  for(lli i = n - 1; i >= 0; i--){
    if(s[i] == t[cur]) r[cur--] = i;
    if(cur < 0) break;
  }
  lli mx = 0;
  fore(i, 1, m){
    if(r[i] > l[i - 1]) mx = max(mx, r[i] - l[i - 1]);
  }
  cout << mx << ENDL;
  return 0;
}
