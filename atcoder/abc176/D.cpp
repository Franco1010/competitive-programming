/*
 © 2020-08-22 12:40:23 Franco1010 All Rights Reserved
*/

#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("avx,avx2,fma")
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
const int cx[4] = {0, 0, 1, -1};
const int cy[4] = {1, -1, 0, 0};
const int N = 1e3 + 5;
const lli INF = 1e18;
char mat[N][N];
lli vis[N][N];
lli h, w;
bool valid(ii pos, ii npos){
  auto [x, y] = npos;
  return 0 <= x and x < h and 0 <= y and y <= w and mat[x][y] == '.' and
        (vis[x][y] > vis[pos.f][pos.s] or vis[x][y] == -1);
}
struct Node{
  ii pos;
  lli dis;
  bool operator < (const Node & n) const {
    return dis > n.dis;
  }
};
void dijkstra(ii pos){
  priority_queue<Node> pq;
  fore(i, 0, N) fore(j, 0, N) vis[i][j] = -1;
  vis[pos.f][pos.s] = 0;
  pq.push({pos, 0});
  while(!pq.empty()){
    auto u = pq.top(); pq.pop();
    if(u.dis > vis[u.pos.f][u.pos.s]) continue;
    fore(i, 0, 4){
      ii npos = {u.pos.f + cx[i], u.pos.s + cy[i]};
      if(valid(u.pos, npos)){
        vis[npos.f][npos.s] = u.dis;
        pq.push({npos, u.dis});
      }
    }
    for(int i = -2; i <= 2; i ++){
      for(int j = -2; j <= 2; j++){
        ii npos = {u.pos.f + i, u.pos.s + j};
        if(valid(u.pos, npos)){
          vis[npos.f][npos.s] = u.dis + 1;
          pq.push({npos, u.dis + 1});
        }
      }
    }
  }
}
int main(){ _
  cin >> h >> w;
  ii ini; cin >> ini.f >> ini.s;
  ii fin; cin >> fin.f >> fin.s;
  ini.f--, ini.s--, fin.f--, fin.s--;
  fore(i, 0, h){
    fore(j, 0, w){
      cin >> mat[i][j];
    }
  }
  dijkstra(ini);
  cout << vis[fin.f][fin.s] << ENDL;
  return 0;
}
