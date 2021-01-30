/*
 © 2021-01-29 08:35:02 Franco1010 All Rights Reserved
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
map<string, vector<string>> g;
map<string, lli> deg;
map<string, lli> id;
void bad(){
  cout << "NO" << ENDL;
  exit(0);
}
int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  lli n, m, k; cin >> n >> m >> k;
  vector<string> v;
  fore(i, 0, n){
    string s; cin >> s;
    g[s] = {};
    v.pb(s);
    id[s] = i;
  }
  fore(i, 0, m){
    string s; lli x; cin >> s >> x; x--;
    bool yes = true;
    fore(j, 0, k) if(v[x][j] != '_' and v[x][j] != s[j]) yes = false;
    if(!yes) bad();
    for(lli mask = 0; mask < (1ll << k); mask++){
      string foo = s;
      fore(j, 0, k) if(mask & (1ll << j)) foo[j] = '_';
      if(g.count(foo) and foo != v[x]) g[v[x]].pb(foo), deg[foo]++;
    }
  }
  vi ans;
  queue<string> q;
  for(auto i : v) if(deg[i] == 0) q.push(i);
  while(!q.empty()){
    auto u = q.front(); q.pop();
    ans.pb(id[u] + 1);
    for(auto v : g[u]){
      deg[v]--;
      if(deg[v] == 0) q.push(v);
    }
  }
  if(sz(ans) == n){
    cout << "YES" << ENDL;
    for(auto i : ans) cout << i << ' ' ; cout << ENDL;
  }else bad();
  return 0;
}
