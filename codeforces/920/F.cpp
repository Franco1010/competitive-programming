/*
 © 2021-01-17 01:18:50 Franco1010 All Rights Reserved
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
const lli INF = 1E18;
const lli N = 1e6 + 5;
lli f[N];
struct Segtree{
  #define mid (l + r) / 2
  #define left(u) (u + 1)
  #define right(u) (u + ((mid - l + 1) << 1))
  struct Node{
    lli s;
    ii mx;
    Node(lli s = 0, ii mx = {-INF, -INF}): s(s), mx(mx) {}
    Node operator + (const Node &n){
      return Node(s + n.s, max(mx, n.mx));
    }
  };
  vector<Node> st;
  Segtree(int n): st(2 * n) {}
  void update(int u, int l, int r, int ll, int rr, lli val = -1){
    if(l > r or r < ll or l > rr or (val == -1 and st[u].mx.f < 3)) return;
    if(l == r){
      if(val == -1) st[u] = Node(f[st[u].s], {f[st[u].s], l});
      else st[u] = Node(val, {val, l});
      return;
    }
    update(left(u), l, mid, ll, rr, val);
    update(right(u), mid + 1, r, ll, rr, val);
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
  fore(i, 1, N) for(lli j = i; j < N; j += i) f[j]++;
  lli n, m; cin >> n >> m;
  Segtree st(n);
  fore(i, 0, n){
    lli x; cin >> x;
    st.update(0, 0, n - 1, i, i, x);
  }
  fore(i, 0, m){
    lli q; cin >> q;
    if(q == 1){
      lli l, r; cin >> l >> r; l--, r--;
      st.update(0, 0, n - 1, l, r);
    }else{
      lli l, r; cin >> l >> r; l--, r--;
      cout << st.query(0, 0, n - 1, l, r).s << ENDL;
    }
  }
  return 0;
}
