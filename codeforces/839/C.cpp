/*
 © 2020-05-18 15:39:37 Franco1010 All Rights Reserved
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
const int N = 1e5 + 5;
vector<int> g[N];
ld l[N];
void dfs(int u = 1, int pr = 1, ld p = 1, int dis = 0){
  lli ch = sz(g[u]);
  if(u != 1) ch--;
  if(ch == 0) l[dis] += p;
  for(auto v : g[u]){
    if(v != pr) dfs(v, u, p / ld(ch), dis + 1);
  }
}
int main(){ _
  lli n; cin >> n;
  fore(i, 1, n){
    lli u, v; cin >> u >> v;
    g[u].pb(v);
    g[v].pb(u);
  }
  dfs();
  ld res = 0;
  fore(i, 0, N) res += ld(i) * l[i];
  cout << fixed << setprecision(6);
  cout << res << ENDL;
  return 0;
}
