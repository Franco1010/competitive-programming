/*
 © 2020-12-11 08:35:08 Franco1010 All Rights Reserved
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
    lli s, mx, mn;
    Node(lli s = 0, lli mx = -INF, lli mn = INF): s(s), mx(mx), mn(mn) {}
    Node operator + (const Node &n){
      return Node(s + n.s, max(mx, n.mx), min(mn, n.mn));
    }
  };
  vector<Node> st;
  Segtree(int n): st(2 * n) {}
  void update(int u, int l, int r, int kth, lli val){ // O(logN)
    if(l == r){
      st[u].s = val;
      st[u].mx = val;
      st[u].mn = val;
      return;
    }
    if(kth <= mid) update(left(u), l, mid, kth, val);
    else update(right(u), mid + 1, r, kth, val);
    st[u] = st[left(u)] + st[right(u)];
  }
  Node query(int u, int l, int r, int ll, int rr){ // O(logN)
    if(l > r or r < ll or l > rr) return Node();
    if(ll <= l and r <= rr) return st[u];
    return query(left(u), l, mid, ll, rr) + query(right(u), mid + 1, r, ll, rr);
  }
  #undef mid
};
lli n;
lli find(lli l, lli r, lli x, vi &v){
  lli pos = l;
  for(lli p = r - l + 1; p > 0; p /= 2ll) while( pos + p <= r and v[pos + p] <= x) pos += p;
  return pos;
}
void pre(lli l, lli r, vi &v, Segtree &st, set<lli> &s){
  if(l > r) return;
  auto q = st.query(0, 0, n - 1, l, r);
  s.insert(q.s);
  lli m = (q.mx + q.mn)/2ll;
  lli mid = find(l, r, m, v);
  // cout << m << ' ' << mid << ENDL;
  if(ii{l, mid} != ii{l, r}) pre(l, mid, v, st, s);
  if(ii{mid + 1, r} != ii{l, r}) pre(mid + 1, r, v, st, s);
}
int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  lli t; cin >> t;
  while(t--){
    lli q; cin >> n >> q;
    vi v(n);
    fore(i, 0, n){
      cin >> v[i];
    }
    sort(all(v));
    Segtree st(n);
    set<lli> s;
    fore(i, 0, n) st.update(0, 0, n - 1, i, v[i]);
    pre(0, n - 1, v, st, s);
    while(q--){
      lli x; cin >> x;
      cout << (s.count(x) ? "Yes" : "No") << ENDL;
    }
  }
  return 0;
}
