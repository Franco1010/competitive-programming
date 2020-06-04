/*
 © 2020-06-04 09:35:19 Franco1010 All Rights Reserved
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
const int N = 5e5 + 5;
struct Node{
  int label;
  int def = -1;
  vector<int> next;
};
Node g[N];
vector<int> order[N];
int mex(unordered_set<int> &st){
  int x = 1;
  while( st.count(x) ) x++;
  return x;
}
bool check(int u){
  bool res = true;
  unordered_set<int> st;
  for(auto v : g[u].next) {
    if(g[v].def != -1) st.insert(g[v].def);
  }
  return mex(st) == g[u].label;
}
int main(){ _
  lli n, m; cin >> n >> m;
  fore(i, 0, m){
    int u, v; cin >> u >> v;
    g[u].next.pb(v);
    g[v].next.pb(u);
  }
  fore(i, 0, n){
    cin >> g[i + 1].label;
    order[g[i + 1].label].pb(i + 1);
  }
  vector<int> res;
  fore(i, 1, N){
    for(auto j : order[i]){
      g[j].def = g[j].label;
      if(not check(j)){
        cout << -1 << ENDL;
        return 0;
      }
      res.pb(j);
    }
  }
  for(auto i : res) cout << i << ' '; cout << ENDL;
  return 0;
}
