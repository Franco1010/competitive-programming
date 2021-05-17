/*
 © 2021-05-16 01:45:21 Franco1010 All Rights Reserved
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
const lli INF = 1e18;
int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  lli n, m; 
  string a, b;
  cin >> n >> m >> a >> b;
  lli ans = 1e18;
  vi res;
  fore(i, 0, m){
    if(i + n - 1 >= m) break;
    vi cur;
    fore(j, 0, n){
      if(a[j] != b[i + j]) cur.pb(j + 1);
    }
    if(sz(cur) < ans){
      ans = sz(cur);
      res = cur;
    }
  }
  cout << ans << ENDL;
  if(ans){
    for(auto i : res) cout << i << ' '; cout << ENDL;
  }
  return 0;
}
