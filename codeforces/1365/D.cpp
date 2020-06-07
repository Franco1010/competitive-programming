/*
 © 2020-06-07 09:35:03 Franco1010 All Rights Reserved
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
const int N = 55;
lli n, m;
string g[N];
const int cx[4] = {0, 0, 1, -1};
const int cy[4] = {1, -1, 0, 0};
bool valid(int x, int y){
  return 0 <= x and x < n and 0 <= y and y < m;
}
bool block(int x, int y){
  bool yes = true;
  g[x][y] = '#';
  fore(i, 0, 4){
    int nx = x + cx[i];
    int ny = y + cy[i];
    if(valid(nx, ny)){
      if(g[nx][ny] == 'G') return false;
      else if(g[nx][ny] == 'B') yes &= block(nx, ny);
      else g[nx][ny] = '#';
    }
  }
  return yes;
}
int vis[N][N];
int curvis;
int bfs(set<ii> st){
  lli res = 0;
  curvis++;
  queue<ii> q;
  q.push({n - 1, m - 1});
  vis[n - 1][m - 1] = curvis;
  while(!q.empty()){
    auto u = q.front(); q.pop();
    if(st.count(u)) res++;
    fore(i, 0, 4){
      int nx = u.f + cx[i];
      int ny = u.s + cy[i];
      if(valid(nx, ny) and g[nx][ny] != '#' and vis[nx][ny] != curvis){
        vis[nx][ny] = curvis;
        q.push({nx, ny});
      }
    }
  }
  return res;
}
void solve(){
  cin >> n >> m;
  bool somebody = false;
  // bool good = false;
  set<ii> v;
  fore(i, 0, n){
    cin >> g[i];
    fore(j, 0, m){
      if(g[i][j] == 'B' or g[i][j] == 'G'){
        somebody = true;
        if(g[i][j] == 'G') v.insert({i, j});
      }
    }
  }
  if(!somebody or v.empty()) {
    cout << "Yes" << ENDL;
    return;
  }
  else{
    fore(i, 0, n){
      fore(j, 0, m){
        if(g[i][j] == 'B'){
          if(!block(i, j)){
            cout << "No" << ENDL;
            return;
          }
        }
      }
    }
  }
  // fore(i, 0, n) cout << g[i] << ENDL;
  // bool yes = true;
  // for(auto i : v) if(!bfs(i)){
  //   cout << "No" << ENDL;
  //   return;
  // }
  if((g[n - 1][m - 1] == '.' or g[n - 1][m - 1] == 'G') and bfs(v) == sz(v))cout << "Yes" << ENDL;
  else cout << "No" << ENDL;
}
int main(){ _
  lli t; cin >> t;
  while(t--){
    solve();
  }
  return 0;
}
