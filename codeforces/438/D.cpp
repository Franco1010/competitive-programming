/*
 © 2021-03-23 02:23:59 Franco1010 All Rights Reserved
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
    lli s, lazy, mx, mn;
    bool flag;
    Node(lli s = 0, lli mx = -INF, lli mn = INF, lli lazy = 0, bool flag = 0):
            s(s), mx(mx), mn(mn), lazy(lazy), flag(flag) {}
    Node operator + (const Node &n){
      auto foo = Node(s + n.s, max(mx, n.mx), min(mn, n.mn));
      return foo;
    }
  };
  vector<Node> st;
  Segtree(int n): st(2 * n) {}
  void push(lli u, lli l, lli r){
    if(st[u].flag){
      if(l < r){
        st[left(u)].lazy = st[right(u)].lazy = st[u].lazy;
        st[left(u)].flag = st[right(u)].flag = 1;
      }
      st[u] = Node(st[u].lazy * lli(r - l + 1ll), st[u].lazy, st[u].lazy);
    }
  }
  void update(int u, int l, int r, int ll, int rr, lli val){ // O(logN)
    push(u, l, r);
    if(l > r or r < ll or l > rr or val > st[u].mx) return;
    if(ll <= l and r <= rr and st[u].mx == st[u].mn){
      st[u].lazy = st[u].mx % val;
      st[u].flag = 1;
      push(u, l, r);
      return;
    }
    update(left(u), l, mid, ll, rr, val);
    update(right(u), mid + 1, r, ll, rr, val);
    st[u] = st[left(u)] + st[right(u)];
  }
  void update(int u, int l, int r, int kth, lli val){
    push(u, l, r);
    if(r < kth or l > kth) return;
    if(l == r){
      st[u].lazy = val;
      st[u].flag = 1;
      push(u, l, r);
      return;
    }
    update(left(u), l, mid, kth, val);
    update(right(u), mid + 1, r, kth, val);
    st[u] = st[left(u)] + st[right(u)];
  }
  Node query(int u, int l, int r, int ll, int rr){ // O(logN)
    push(u, l, r);
    if(l > r or r < ll or l > rr) return Node();
    if(ll <= l and r <= rr) return st[u];
    return query(left(u), l, mid, ll, rr) + query(right(u), mid + 1, r, ll, rr);
  }
};
int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  lli n, m; cin >> n >> m;
  Segtree st(n);
  fore(i, 0, n){
    lli x; cin >> x; st.update(0, 0, n - 1, i, x);
  }
  while(m--){
    lli t; cin >> t;
    if(t == 1){
      lli l, r; cin >> l >> r; l--, r--;
      cout << st.query(0, 0, n - 1, l, r).s << ENDL;
    }else if(t == 2){
      lli l, r, x; cin >> l >> r >> x; l--, r--;
      st.update(0, 0, n - 1, l, r, x);
    }else if(t == 3){
      lli k, x; cin >> k >> x; k--;
      st.update(0, 0, n - 1, k, x);
    }
  }
  return 0;
}
