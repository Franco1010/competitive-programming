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
lli acu[N];
lli cur = 1;
lli n, k;
lli s(lli l, lli r){
  if(l > r) return 0;
  return acu[min(n, r)] - acu[max(0ll, l - 1)];
}
lli solve(lli x = 0, lli state = 0){
  if(x >= sz(v)) return 0;
  lli &ans = dp[x][state];
  lli &done = vis[x][state];
  if(done != cur){
    done = cur;
    ans = INF;
    if(state == 0){
      ans = min(ans, solve(x + k, 0) + (v[x] == '1'));
      ans = min(ans, solve(x + k, 1) + (v[x] == '0'));
    }else if(state == 1){
      ans = min(ans, solve(x + k, 1) + (v[x] == '0'));
      ans = min(ans, solve(x + k, 2) + (v[x] == '1'));
    }else{
      ans = min(ans, solve(x + k, 2) + (v[x] == '1'));
    }
    ans += s(x + 2, x + k);
  }
  return ans;
}
int main(){ _
  lli t; cin >> t;
  while(t--){
    cin >> n >> k;
    cin >> v;
    fore(i, 0, n) acu[i + 1] = acu[i] + (v[i] == '1');
    lli ans = INF;
    fore(i, 0, k){
      ans = min(ans, solve(i) + s(0, i));
      cur++;
    }
    cout << ans << ENDL;
  }
  return 0;
}
