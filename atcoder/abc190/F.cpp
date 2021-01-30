/*
 © 2021-01-30 05:58:27 Franco1010 All Rights Reserved
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
struct Segtree{
  #define mid (l + r) / 2
  #define left(u) (u + 1)
  #define right(u) (u + ((mid - l + 1) << 1))
  struct Node{
    lli s, mx;
    Node(lli s = 0, lli mx = -1): s(s), mx(mx) {}
    Node operator + (const Node &n){
      return Node(s + n.s, max(mx, n.mx));
    }
  };
  vector<Node> st;
  Segtree(int n): st(2 * n) {}
  void update(int u, int l, int r, int kth, lli val){ // O(logN)
    if(l == r){
      st[u].s = val;
      st[u].mx = val;
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
  lli n; cin >> n;
  Segtree st(n);
  vector<ii> ord;
  vi v(n); fore(i, 0, n) cin >> v[i], ord.pb({v[i], i});
  sort(all(ord), [&](const ii& a, const ii& b){
    return a.f > b.f;
  });
  lli ini = 0;
  for(auto i : ord){
    auto foo = st.query(0, 0, n - 1, 0, i.s);
    ini += foo.s;
    st.update(0, 0, n - 1, i.s, 1);
  }
  cout << ini << ENDL;
  fore(i, 0, n - 1){
    ini -= v[i];
    ini += n - v[i] - 1;
    cout << ini << ENDL;
  }
  return 0;
}
