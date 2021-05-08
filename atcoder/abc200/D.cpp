/*
 © 2021-05-08 07:01:40 Franco1010 All Rights Reserved
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
const lli N = 205;
const lli MOD = 200;
lli v[N];
lli dp[2][N][N];
lli vis[2][N][N];
lli curvis;
lli goal;
lli n;
lli solve(lli pos = 0, lli mod = 0, lli st = 0){
  auto& ans = dp[st][pos][mod];
  auto& mem = vis[st][pos][mod];
  if(pos == n){
    mem = curvis;
    if(st and mod == goal) ans = 1;
    else ans = 0;
  }
  if(mem != curvis){
    mem = curvis;
    ans = 0;
    ans = min(2ll, ans + solve(pos + 1, mod, st));
    ans = min(2ll, ans + solve(pos + 1, (mod + v[pos]) % MOD, 1));
  }
  return ans;
}
lli done;
void get(vi& x, lli pos = 0, lli mod = 0, lli st = 0){
  // cout << pos << ' ' << mod << ENDL;
  if(pos == n){
    done++;
    cout << sz(x) << ' '; for(auto i : x) cout << i << ' '; cout << ENDL;
    if(done == 2) exit(0);
    return;
  }
  if(solve(pos + 1, mod, st)){
    get(x, pos + 1, mod, st);
  }
  if(solve(pos + 1, (mod + v[pos]) % MOD, 1)){
    x.pb(pos + 1);
    get(x, pos + 1, (mod + v[pos]) % MOD, 1);
    x.pop_back();
  }
}
int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  cin >> n;
  fore(i, 0, n) cin >> v[i], v[i] %= MOD;
  fore(i, 0, 200){
    curvis++;
    goal = i;
    auto foo = solve();
    if(foo >= 2){
      done = 0;
      cout << "Yes" << ENDL;
      vi x;
      get(x);
    }
  }
  cout << "No" << ENDL;
  return 0;
}
