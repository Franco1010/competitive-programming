/*
 © 2020-09-04 09:35:02 Franco1010 All Rights Reserved
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
const int N = 205;
lli n, k;
string a, b;
lli dp[N][N][N];
lli vis[N][N][N];
lli curvis;
lli solve(lli k, lli pos = 0, lli x = 0){
  if(k < 0) return 0;
  if(pos >= n) return 0;
  lli &ans = dp[k][pos][x];
  if(vis[k][pos][x] != curvis){
    vis[k][pos][x] = curvis;
    ans = 0;
    if(a[pos] == b[0] or k) ans = max(ans, solve(k - (a[pos] != b[0]), pos + 1, x + 1));
    if(a[pos] == b[1] or k) ans = max(ans, solve(k - (a[pos] != b[1]), pos + 1, x + (b[0] == b[1])) + x);
    if(a[pos] != b[0] and a[pos] != b[1]) ans = max(ans, solve(k, pos + 1, x));
  }
  return ans;
}
int main(){ _
  cin >> n >> k;
  cin >> a >> b;
  curvis++;
  cout << solve(k) << ENDL;
  return 0;
}
