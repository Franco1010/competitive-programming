/*
 © 2021-01-04 08:35:01 Franco1010 All Rights Reserved
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
const lli INF = 1e18;
struct Segtree{
  #define mid (l + r) / 2
  #define left(u) (u + 1)
  #define right(u) (u + ((mid - l + 1) << 1))
  struct Node{
    ii mn, mx;
    Node(ii mn = {INF, INF}, ii mx = {INF, INF}): mn(mn), mx(mx) {}
    Node operator + (const Node &n){
      ii foo = min(mx, n.mx, [&](const ii& a, const ii& b){
        return tuple{a.f, -a.s} < tuple{b.f, -b.s};
      });
      return Node(min(mn, n.mn), foo);
    }
  };
  vector<Node> st;
  Segtree(int n): st(2 * n) {}
  void update(int u, int l, int r, int kth, ii val){
    if(l == r){
      st[u].mn = min(st[u].mn, val);
      st[u].mx = min(st[u].mx, val, [&](const ii& a, const ii& b){
        return tuple{a.f, -a.s} < tuple{b.f, -b.s};
      });
      return;
    }
    if(kth <= mid) update(left(u), l, mid, kth, val);
    else update(right(u), mid + 1, r, kth, val);
    st[u] = st[left(u)] + st[right(u)];
  }
  Node query(int u, int l, int r, int ll, int rr){
    if(l > r or r < ll or l > rr) return Node();
    if(ll <= l and r <= rr) return st[u];
    return query(left(u), l, mid, ll, rr) + query(right(u), mid + 1, r, ll, rr);
  }
};
int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  lli t; cin >> t;
  while(t--){
    lli n; cin >> n;
    vector<ii> v;
    vi comp;
    fore(i, 0, n){
      lli h, w; cin >> h >> w;
      v.pb({h, w});
      comp.pb(h); comp.pb(w);
    }
    comp.pb(0);
    sort(all(comp));
    comp.erase(unique(all(comp)), end(comp));
    lli N = sz(comp);
    Segtree st(N + 1);
    lli ind = 1;
    for(auto &[h, w] : v){
      h = lower_bound(all(comp), h) - begin(comp);
      w = lower_bound(all(comp), w) - begin(comp);
      st.update(0, 0, N, h, {min(st.query(0, 0, N, h, h).mn.f, w), ind});
      st.update(0, 0, N, w, {min(st.query(0, 0, N, w, w).mn.f, h), ind});
      ind++;
    }
    ind = 0;
    for(auto [h, w] : v){
      ind++;
      auto foo = st.query(0, 0, N, 0, h - 1);
      if(foo.mn.f < w and foo.mn.s != ind){
        cout << foo.mn.s << ' ';
        continue;
      }
      if(foo.mx.f < w and foo.mx.s != ind){
        cout << foo.mx.s << ' ';
        continue;
      }
      foo = st.query(0, 0, N, 0, w - 1);
      if(foo.mn.f < h and foo.mn.s != ind){
        cout << foo.mn.s << ' ';
        continue;
      }
      if(foo.mx.f < h and foo.mx.s != ind){
        cout << foo.mx.s << ' ';
        continue;
      }
      cout << -1 << ' ';
    }
    cout << ENDL;
  }
  return 0;
}
