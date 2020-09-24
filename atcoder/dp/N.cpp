/*
 © 2020-09-23 19:37:44 Franco1010 All Rights Reserved
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
const lli N = 4e2 + 5;
const lli INF = 1e18;
lli v[N];
ii dp[N][N];
bool vis[N][N];
ii solve(lli l, lli r){
  if(l == r) return {0, v[l]};
  if(l + 1 == r) return {v[l] + v[r], v[l] + v[r]};
  auto &ans = dp[l][r];
  if(!vis[l][r]){
    vis[l][r] = true;
    ans = {INF, 0};
    fore(i, l, r){
      ans = min(ans, ii{solve(l, i).f + solve(i + 1, r).f + solve(l, i).s + solve(i + 1, r).s,
                        solve(l, i).s + solve(i + 1, r).s}
      );
    }
  }
  return ans;
}
int main(){ _
  lli n; cin >> n;
  fore(i, 0, n) cin >> v[i];
  cout << solve(0, n - 1).f << ENDL;
  return 0;
}
