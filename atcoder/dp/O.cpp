/*
 © 2020-09-23 19:55:52 Franco1010 All Rights Reserved
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
const lli N = 22;
const lli MOD = 1E9 + 7;
lli n;
bool mat[N][N];
lli dp[1ll << N][N];
bool vis[1ll << N][N];
lli solve(lli pos = 0, lli mask = 0){
  if(pos >= n) return (__builtin_popcountll(mask) == n);
  lli &ans = dp[mask][pos];
  if(!vis[mask][pos]){
    vis[mask][pos] = true;
    ans = 0;
    fore(i, 0, n){
      if(mat[pos][i] and !(mask & (1ll << i))){
        ans = (ans + solve(pos + 1, mask | (1ll << i)) + MOD) % MOD;
      }
    }
    ans = (ans + MOD) % MOD;
  }
  return ans;
}
int main(){ _
  cin >> n;
  fore(i, 0, n){
    fore(j, 0, n){
      cin >> mat[i][j];
    }
  }
  cout << solve() << ENDL;
  return 0;
}
