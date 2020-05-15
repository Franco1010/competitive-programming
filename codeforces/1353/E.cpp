/*
 © 2020-05-14 09:35:01 Franco1010 All Rights Reserved
*/

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
typedef pair<int,int> ii;
#define deb(x) cout << #x": " << (x) << endl;
const lli INF = 1e18;
const int N = 1e6 + 5;
string v;
lli dp[N][3];
lli vis[N][3];
lli cur = 1;
lli solve(lli x = 0, lli state = 0){
  if(x >= sz(v)) return 0;
  lli &ans = dp[x][state];
  lli &done = vis[x][state];
  if(done != cur){
    done = cur;
    ans = INF;
    if(state == 0){
      ans = min(ans, solve(x + 1, 0) + (v[x] == '1'));
      ans = min(ans, solve(x + 1, 1) + (v[x] == '0'));
    }else if(state == 1){
      ans = min(ans, solve(x + 1, 1) + (v[x] == '0'));
      ans = min(ans, solve(x + 1, 2) + (v[x] == '1'));
    }else{
      ans = min(ans, solve(x + 1, 2) + (v[x] == '1'));
    }
  }
  return ans;
}
int main(){ _
  lli t; cin >> t;
  while(t--){
    lli n, k; cin >> n >> k;
    string s; cin >> s;
    map<lli,string> mp;
    map<lli,lli> cnt;
    lli tot = 0;
    fore(i, 0, n){
      mp[i % k].pb(s[i]);
      if(s[i] == '1') tot++, cnt[i % k]++;
    }
    lli ans = INF;
    fore(i, 0, k){
      v = mp[i];
      ans = min(ans, solve() + tot - cnt[i]);
      cur++;
    }
    cout << ans << ENDL;
  }
  return 0;
}
