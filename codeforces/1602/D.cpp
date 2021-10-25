/*
 © 2021-10-25 01:35:01 Franco1010 All Rights Reserved
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

const lli N = 3e5 + 6;
// const lli INF = 1e8;
lli a[N], b[N];
lli n;
void solve(){
  queue<lli> q;
  vi dp(n + 1, -1);
  vector<ii> pr(n + 1, {-1, -1});
  set<lli> ava;
  fore(i, 0, n + 1) ava.insert(i);
  q.push(n);
  dp[n] = 0;
  while(!q.empty()){
    auto u = q.front(); q.pop();
    if(u == 0){
      break;
    }
    while(!ava.empty()){// [u - a[u], u - 1]
      lli pos = u - a[u];
      auto foo = ava.lower_bound(pos);
      if(foo == end(ava) or *foo >= u){
        break;
      }
      if(dp[*foo + b[*foo]] == -1){
        q.push(*foo + b[*foo]);
        dp[*foo + b[*foo]] = dp[u] + 1;
        pr[*foo + b[*foo]] = {u, *foo};
      }
      ava.erase(foo);
    }
  }
  if(dp[0] == -1) cout << -1 << ENDL;
  else{
    cout << dp[0] << ENDL;
    lli cur = 0;
    vi ans;
    while(true){
      ans.pb(pr[cur].s);
      cur = pr[cur].f;
      if(cur == -1) break;
    }
    ans.pop_back();
    reverse(all(ans));
    for(auto i : ans) cout << i << ' '; cout << ENDL;
  }
}
int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  cin >> n;
  fore(i, 1, n + 1) cin >> a[i];
  fore(i, 1, n + 1) cin >> b[i];
  solve();
  return 0;
}
