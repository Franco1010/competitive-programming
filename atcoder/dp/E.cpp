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
const int N = 1e5 + 5;
lli dp[N];
int main(){ _
  lli n, w; cin >> n >> w;
  vector<ii> v(n);
  fore(i, 0, n){
    cin >> v[i].f >> v[i].s;
  }
  lli mx = 0;
  fore(i, 0, N) dp[i] = INF;
  dp[0] = 0;
  for(auto i : v){
    for(lli j = N; j >= i.s; j--){
      dp[j] = min(dp[j], dp[j - i.s] + i.f);
    }
  }
  fore(i, 0, N) if(dp[i] <= w) mx = max(mx, lli(i));
  cout << mx << ENDL;
  return 0;
}
