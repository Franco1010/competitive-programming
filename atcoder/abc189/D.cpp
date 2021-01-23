/*
 © 2021-01-23 05:54:10 Franco1010 All Rights Reserved
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
struct DSU{
  vi pr, rank;
  DSU(int n): pr(n), rank(n, 1) {
    iota(all(pr), 0);
  }
  lli find(lli u){
    return pr[u] == u ? u : pr[u] = find(pr[u]);
  }
  void unite(lli u, lli v){
    u = find(u), v = find(v);
    if(u != v){
      if(rank[u] < rank[v]) swap(u, v);
      rank[u] += rank[v];
      pr[v] = u;
    }
  }
};
const lli N = 65;
lli dp[2][N];
int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  lli n; cin >> n;
  vector<string> v(n + 1);
  dp[0][0] = 1;
  dp[1][0] = 1;
  fore(i, 1, n + 1){
    cin >> v[i];
    if(v[i] == "AND"){
      dp[0][i] = 2ll * dp[0][i - 1] + dp[1][i - 1];
      dp[1][i] = dp[1][i - 1];
    }else{
      dp[1][i] = dp[0][i - 1] + 2ll * dp[1][i - 1];
      dp[0][i] = dp[0][i - 1];
    }
  }
  cout << dp[1][n] << ENDL;
  return 0;
}
