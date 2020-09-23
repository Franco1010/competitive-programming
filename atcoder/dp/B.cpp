/*
 © 2020-09-23 12:51:37 Franco1010 All Rights Reserved
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
const lli INF = 1e18;
int main(){ _
  lli n, k; cin >> n >> k;
  vector<lli> v(n);
  fore(i, 0, n) cin >> v[i];
  vector<lli> dp(n, INF);
  dp[0] = 0;
  fore(i, 0, n){
    fore(j, 1, k + 1){
      if(i + j < n) dp[i + j] = min(dp[i + j], dp[i] + abs(v[i] - v[i + j]));
    }
  }
  cout << dp[n - 1] << ENDL;
  return 0;
}