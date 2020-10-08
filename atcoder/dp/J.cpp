/*
 © 2020-10-07 23:45:15 Franco1010 All Rights Reserved
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
const lli N = 3e2 + 5;
lli n;
ld dp[N][N][N];
bool vis[N][N][N];
ld solve(lli a, lli b, lli c){
  if(a + b + c == 0) return 0;
  ld &ans = dp[a][b][c];
  if(!vis[a][b][c]){
    vis[a][b][c] = true;
    ans = 1;
    ld pa = ld(a) / ld(n);
    ld pb = ld(b) / ld(n);
    ld pc = ld(c) / ld(n);
    ld pd = ld(n - a - b - c) / ld(n);
    if(a) ans += pa * solve(a - 1, b, c);
    if(b) ans += pb * solve(a + 1, b - 1, c);
    if(c) ans += pc * solve(a, b + 1, c - 1);
    ans /= ld(1) - pd;
  }
  return ans;
}
int main(){ _
  cin >> n;
  lli a = 0, b = 0, c = 0;
  fore(i, 0, n){
    lli x; cin >> x;
    if(x == 1) a++;
    if(x == 2) b++;
    if(x == 3) c++;
  }
  cout << fixed << setprecision(9);
  cout << solve(a, b, c) << ENDL;
  return 0;
}
