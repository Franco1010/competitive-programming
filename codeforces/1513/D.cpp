/*
 © 2021-04-11 09:35:01 Franco1010 All Rights Reserved
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
lli gcd(lli a, lli b){
  return b ? gcd(b, a % b) : a;
}
struct Segtree{
  #define mid (l + r) / 2
  #define left(u) (u + 1)
  #define right(u) (u + ((mid - l + 1) << 1))
  struct Node{
    lli s;
    Node(lli s = 0): s(s) {}
    Node operator + (const Node& n){
      return gcd(s, n.s);
    }
  };
  vector<Node> st;
  Segtree(int n): st(2 * n) {}
  void update(int u, int l, int r, int kth, lli val){ // O(logN)
    if(l == r){
      st[u].s = val;
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
};
struct SegtreeMark{
  #define mid (l + r) / 2
  #define left(u) (u + 1)
  #define right(u) (u + ((mid - l + 1) << 1))
  struct Node{
    lli s, lazy;
    Node(lli s = 0, lli lazy = 0): s(s), lazy(lazy) {}
    Node operator + (const Node& n){
      return s + n.s;
    }
  };
  vector<Node> st;
  SegtreeMark(int n): st(2 * n) {}
  void push(int u, int l, int r){
    if(st[u].lazy){
      if(l < r){
        st[left(u)].lazy = st[u].lazy;
        st[right(u)].lazy = st[u].lazy;
      }
      st[u].s = 1;
      st[u].lazy = 0;
    }
  }
  void update(int u, int l, int r, int ll, int rr){ // O(logN)
    push(u, l, r);
    if(l > r or r < ll or l > rr) return;
    if(ll <= l and r <= rr){
      st[u].lazy = 1;
      push(u, l, r);
      return;
    }
    update(left(u), l, mid, ll, rr);
    update(right(u), mid + 1, r, ll, rr);
    st[u] = st[left(u)] + st[right(u)];
  }
  lli query(int u, int l, int r, int kth){
    push(u, l, r);
    if(l == r) return st[u].s;
    if(kth <= mid) return query(left(u), l, mid, kth);
    else return query(right(u), mid + 1, r, kth);
  }
  lli first(int u, int l, int r, int ll, int rr){
    push(u, l, r);
    if(st[u].s == 0) return -1;
    if(l > r or r < ll or l > rr) return -1;
    if(l == r) return l;
    lli foo = first(left(u), l, mid, ll, rr);
    if(foo != -1) return foo;
    return first(right(u), mid + 1, r, ll, rr);
  }
  lli last(int u, int l, int r, int ll, int rr){
    push(u, l, r);
    if(st[u].s == 0) return -1;
    if(l > r or r < ll or l > rr) return -1;
    if(l == r) return l;
    lli foo = last(right(u), mid + 1, r, ll, rr);
    if(foo != -1) return foo;
    return last(left(u), l, mid, ll, rr);
  }
  void print(int u, int l, int r){
    push(u, l, r);
    if(l == r){
      cout << st[u].s << ' ';
      return;
    }
    print(left(u), l, mid);
    print(right(u), mid + 1, r);
  }
};
lli n;
lli lookdonel(SegtreeMark& st, lli x){
  lli foo = st.last(0, 0, n - 1, 0, x);
  if(foo == -1) return 0;
  else return foo;
}
lli lookdoner(SegtreeMark& st, lli x){
  lli foo = st.first(0, 0, n - 1, x, n - 1);
  if(foo == -1) return n - 1;
  else return foo;
}
lli expl(Segtree& st, lli x, lli lim, lli gg){
  lli pos = x;
  for(lli p = n; p; p /= 2ll) while(pos - p >= lim and st.query(0, 0, n - 1, pos - p, x).s == gg) pos -= p;
  return pos;
}
lli expr(Segtree& st, lli x, lli lim, lli gg){
  lli pos = x;
  for(lli p = n; p; p /= 2ll) while(pos + p <= lim and st.query(0, 0, n - 1, x, pos + p).s == gg) pos += p;
  return pos;
}
struct DSU{
  vi pr, rank;
  lli comp;
  DSU(int n): pr(n), rank(n, 1){ // O(N)
    iota(all(pr), 0);
    comp = n;
  }
  int find(int u){ // O(1)
    return pr[u] == u ? u: pr[u] = find(pr[u]);
  }
  void unite(int u, int v){ // O(1)
    u = find(u), v = find(v);
    if(u != v){
      if(rank[u] < rank[v]) swap(u, v);
      rank[u] += rank[v];
      pr[v] = u;
      comp--;
    }
  }
};
int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  lli t; cin >> t;
  while(t--){
    lli p; cin >> n >> p;
    vector<ii> ord;
    Segtree st(n);
    fore(i, 0, n){
      lli x; cin >> x;
      ord.pb({x, i});
      st.update(0, 0, n - 1, i, x);
    }
    sort(all(ord));
    SegtreeMark stm(n);
    DSU dsu(n);
    lli ans = 0;
    for(auto i : ord){
      if(i.f >= p) break;
      if(stm.query(0, 0, n - 1, i.s)) continue;
      lli l = lookdonel(stm, i.s);
      lli r = lookdoner(stm, i.s);
      lli ll = expl(st, i.s, l, i.f);
      lli rr = expr(st, i.s, r, i.f);
      // cout << ll << ' ' << i.s << ' ' << rr << ENDL;
      if(ll == rr) continue;
      fore(i, ll, rr) dsu.unite(i, i + 1);
      stm.update(0, 0, n - 1, ll, rr);
      // done.pb(i.s);
      ans += (rr - ll) * i.f;
    }
    // cout << ans << ENDL;
    ans += (dsu.comp - 1ll) * p;
    cout << ans << ENDL;
    // stm.print(0, 0, n - 1); cout << ENDL;
  }
  return 0;
}
