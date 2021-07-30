/*
 © 2021-07-30 09:35:01 Franco1010 All Rights Reserved
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
const lli N = 1e3 + 5;
lli pre[N];
const map<lli,lli>mp = {{6, 15}, {8, 20}, {10, 25}};

int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  lli t; cin >> t;
  fore(i, 0, N) pre[i] = 1e18;
  pre[0] = 0;
  fore(i, 1, N){
    for(auto j : mp){
      lli foo = i - j.f;
      if(foo <= 0) pre[i] = min(pre[i], j.s);
      else pre[i] = min(pre[i], pre[foo] + j.s);
    }
  }
  while(t--){
    lli n; cin >> n;
    lli ans = 1e18;
    for(lli i = 0; i <= min(N - 1, n); i++){
      for(auto j : mp){
        lli foo = n - i;
        if(foo % j.f == 0){
          ans = min(ans, pre[i] + (foo / j.f) * j.s);
        }
      }
    }
    cout << ans << ENDL;
  }
  return 0;
}
