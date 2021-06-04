/*
 © 2021-06-04 09:35:01 Franco1010 All Rights Reserved
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
const lli N = 2e5 + 5;
string s;
lli dp[2][3][N], vis[2][3][N];
lli curvis;
lli solve(lli pos = 0, lli ini = 0, lli last = 2){
  if(pos == sz(s)) return 0;
  auto& ans = dp[ini][last][pos];
  auto& mem = vis[ini][last][pos];
  if(mem != curvis){
    mem = curvis;
    ans = 0;
    if(!ini){
      ans += solve(pos + 1, ini, last);
      if(s[pos] == '?') ans += solve(pos + 1, 1, 0) + solve(pos + 1, 1, 1) + 2ll;
      else ans += solve(pos + 1, 1, s[pos] - '0') + 1ll;
    }else{
      if(s[pos] == '?') ans += solve(pos + 1, ini, last == 0 ? 1 : 0) + 1ll;
      else if(last != s[pos] - '0') ans += solve(pos + 1, ini, s[pos] - '0') + 1ll;
    }
  }
  return ans;
}
int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  lli t; cin >> t;
  while(t--){
    cin >> s;
    lli cnt = 0;
    lli foo = 0;
    for(auto i : s){
      if(i == '?') cnt++;
      else{
        cnt++;
        foo += (cnt * (cnt - 1ll)) / 2ll;
        cnt = 0;
      }
    }
    cnt++;
    foo += (cnt * (cnt - 1ll)) / 2ll;
    curvis++;
    cout << solve() - foo << ENDL;
  }
  return 0;
}
