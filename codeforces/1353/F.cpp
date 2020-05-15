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
const lli N = 1e2 + 5;
const lli INF = 1e18;
lli ori[N][N];
lli mat[N][N];
lli dp[N][N];
lli vis[N][N];
lli n, m, cur = 1;
lli solve(lli val, lli x = 0, lli y = 0){
  lli &ans = dp[x][y];
  lli &done = vis[x][y];
  if(done != cur){
    done = cur;
    ans = INF;
    lli aux = val + x + y;
    if(mat[x][y] >= aux){
      if(x + 1 < n) ans = min(ans, solve(val, x + 1, y) + (mat[x][y] - aux));
      if(y + 1 < m) ans = min(ans, solve(val, x, y + 1) + (mat[x][y] - aux));
      if(y + 1 == m and x + 1 == n) ans = mat[x][y] - aux;
    }
    ans = min(ans, INF);
  }
  return ans;
}
int main(){ _
  lli t; cin >> t;
  while(t--){
    cin >> n >> m;
    fore(i, 0, n){
      fore(j, 0, m){
        cin >> ori[i][j];
        mat[i][j] = ori[i][j];
      }
    }
    lli ans = INF;
    fore(i, 0, n) fore(j, 0, m) {
      ans = min(ans, solve(mat[i][j] - i - j));
      cur++;
    }
    cout << ans << ENDL;
  }
  return 0;
}
