/*
 © 2021-01-14 08:35:01 Franco1010 All Rights Reserved
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
    lli s, mn, mx;
    Node(lli s = 0, lli mn = 0, lli mx = 0): s(s), mn(mn), mx(mx) {}
    Node operator + (const Node& n){
      return Node(s + n.s, min(mn, s + n.mn), max(mx, s + n.mx));
    }
  };
  vector<Node> st;
  Segtree(int n): st(2 * n) {}
  void update(int u, int l, int r, int kth, lli val){ // O(logN)
    if(l == r){
      st[u] = Node(val, min(val, 0ll), max(val, 0ll));
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

int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  lli t; cin >> t;
  while(t--){
    lli n, m; cin >> n >> m;
    string s; cin >> s;
    Segtree st(n + 2);
    fore(i, 1, n + 1) st.update(0, 0, n + 1, i, s[i - 1] == '+' ? +1 : -1);
    while(m--){
      lli l, r; cin >> l >> r;
      auto foo = st.query(0, 0, n + 1, 0, l - 1);
      auto bar = st.query(0, 0, n + 1, r + 1, n + 1);
      auto far = (foo + bar);
      cout << far.mx - far.mn + 1ll << ENDL;
    }
  }
  return 0;
}
