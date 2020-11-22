/*
 © 2020-11-22 11:05:16 Franco1010 All Rights Reserved
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
const lli N = 105;
double dp[N][N][N];
bool vis[N][N][N];
double solve(lli a, lli b, lli c){
  if(a == 100 or b == 100 or c == 100) return 0;
  double &ans = dp[a][b][c];
  if(!vis[a][b][c]){
    vis[a][b][c] = true;
    ans = 1;
    double pa = double(1) - (double(b + c)/double(a + b + c));
    double pb = double(1) - (double(a + c)/double(a + b + c));
    double pc = double(1) - (double(a + b)/double(a + b + c));
    ans += solve(a + 1, b, c) * pa;
    ans += solve(a, b + 1, c) * pb;
    ans += solve(a, b, c + 1) * pc;
  }
  return ans;
}
int main(){ _
  lli a, b, c; cin >> a >> b >> c;
  cout << fixed << setprecision(7);
  cout << solve(a, b, c) << ENDL;
  return 0;
}
