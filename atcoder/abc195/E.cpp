/*
 © 2021-03-12 13:07:10 Franco1010 All Rights Reserved
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
const lli INF = 1e18;
const lli N = 2e5 + 5;
const lli MOD = 7;
lli n;
string s, x;
lli pot[N];
bool dp[8][N], vis[8][N];
bool solve(lli pos = 0, lli m = 0){
  if(pos == n){
    return m == 0;
  }
  auto& ans = dp[m][pos];
  if(!vis[m][pos]){
    vis[m][pos] = true;
    ans = false;
    if(x[pos] == 'T'){
      ans = solve(pos + 1, (m * 10ll + (s[pos] - '0')) % 7ll) or
            solve(pos + 1, (m * 10ll) % 7ll);
    }else{
      ans = solve(pos + 1, (m * 10ll + (s[pos] - '0')) % 7ll) and
            solve(pos + 1, (m * 10ll) % 7ll);
    }
  }
  return ans;
}
int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  cin >> n >> s >> x;
  lli p = 1;
  for(lli i = n - 1; i >= 0; i--){
    pot[i] = p;
    p = (p * 10ll) % MOD;
  }
  cout << (solve() ? "Takahashi" : "Aoki") << ENDL;
  return 0;
}
