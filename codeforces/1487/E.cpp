/*
 © 2021-02-15 08:35:01 Franco1010 All Rights Reserved
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
const lli INF = 1e15;
struct Segtree{
  #define mid (l + r) / 2
  #define left(u) (u + 1)
  #define right(u) (u + ((mid - l + 1) << 1))
  struct Node{
    lli s, lazy;
    Node(lli s = INF, lli lazy = INF): s(s), lazy(lazy) {}
  };
  vector<Node> st;
  Segtree(int n): st(2 * n) {}
  void push(int u, int l, int r){
    if(st[u].lazy < INF){
      if(l < r){
        st[left(u)].lazy = min(st[left(u)].lazy, st[u].lazy);
        st[right(u)].lazy = min(st[right(u)].lazy, st[u].lazy);
      }
      st[u].s = min(st[u].s, st[u].lazy);
      st[u].lazy = INF;
    }
  }
  void update(int u, int l, int r, int ll, int rr, lli val){ // O(logN)
    push(u, l, r);
    if(l > r or r < ll or l > rr) return;
    if(ll <= l and r <= rr){
      st[u].lazy = min(st[u].lazy, val);
      push(u, l, r);
      return;
    }
    update(left(u), l, mid, ll, rr, val);
    update(right(u), mid + 1, r, ll, rr, val);
  }
  void copy(int u, int l, int r, vi& v){
    push(u, l, r);
    if(l == r) {
      v[l] += st[u].s;
      return;
    }
    copy(left(u), l, mid, v);
    copy(right(u), mid + 1, r, v);
  }
};
int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  vi n(4); fore(i, 0, 4) cin >> n[i];
  vector<Segtree> st;
  vector<vi> v(4); fore(i, 0, 4) fore(j, 0, n[i]){
    lli x; cin >> x;
    v[i].pb(x);
  }
  st.pb(Segtree(n[0]));
  fore(i, 0, 3){
    lli m; cin >> m;
    map<lli, vi> mp;
    while(m--){
      lli u, v; cin >> u >> v; u--, v--;
      mp[u].pb(v);
    }
    if(i) st[i].copy(0, 0, n[i] - 1, v[i]);
    // for(auto ii : v[i]) cout << ii << ' '; cout << ENDL;
    st.pb(Segtree(n[i + 1]));
    fore(j, 0, n[i]){
      mp[j].pb(n[i + 1]);
      sort(all(mp[j]));
      // cout << "list: "; for(auto ii : mp[j]) cout << ii << ' '; cout << ENDL;
      lli last = -1;
      for(auto k : mp[j]){
        if(last + 1 <= k - 1){
          st[i + 1].update(0, 0, n[i + 1] - 1, last + 1, k - 1, v[i][j]);
        }
        last = k;
      }
    }
  }
  st[3].copy(0, 0, n[3] - 1, v[3]);
  // for(auto i : v[3]) cout << i << ' '; cout << ENDL;
  lli res = INF;
  for(auto i : v[3]) res = min(res, i);
  if(res < INF) cout << res << ENDL;
  else cout << -1 << ENDL;
  return 0;
}
