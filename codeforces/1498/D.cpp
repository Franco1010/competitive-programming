/*
 © 2021-03-29 08:35:40 Franco1010 All Rights Reserved
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
const lli M = 1e5 + 5;
const lli N = 2e2 + 5;
const lli B = 1e5;
lli dp[M];
lli rep[M];
lli vis[M];
struct Node{lli t, x, y;};
Node v[N];
lli up(lli x){ return (x + B - 1) / B; }
lli op1(lli a, lli b){
  return a + up(b);
}
lli op2(lli a, lli b){
  return up(a * b);
}
lli op(lli x, lli a, lli b){
  return x == 1 ? op1(a, b) : op2(a, b);
}
int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  lli n, m; cin >> n >> m;
  fore(i, 0, n) cin >> v[i].t >> v[i].x >> v[i].y;
  dp[0] = 1;
  fore(i, 0, n){
    fore(j, 0, m + 1){
      lli np = op(v[i].t, j, v[i].x);
      if(dp[j] and vis[j] != i + 1) rep[j] = v[i].y;
      if(dp[j] and rep[j] and j < np and np <= m and !dp[np]){
        dp[np] = i + 1;
        rep[np] = rep[j] - 1;
        vis[np] = i + 1;
      }
    }
  }
  fore(i, 1, m + 1) cout << (dp[i] ? dp[i] : -1) << ' '; cout << ENDL;
  return 0;
}
