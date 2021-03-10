/*
 © 2021-03-10 06:05:02 Franco1010 All Rights Reserved
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
struct Segtree{
  #define mid (l + r) / 2
  #define left(u) (u + 1)
  #define right(u) (u + ((mid - l + 1) << 1))
  struct Node{
    lli mx;
    Node(lli mx = 0): mx(mx) {}
    Node operator + (const Node &n){
      return Node(max(mx, n.mx));
    }
  };
  vector<Node> st;
  Segtree(int n): st(2 * n) {}
  void update(int u, int l, int r, int kth, lli val){ // O(logN)
    if(l == r){
      st[u].mx = val;
      return;
    }
    if(kth <= mid) update(left(u), l, mid, kth, val);
    else update(right(u), mid + 1, r, kth, val);
    st[u] = st[left(u)] + st[right(u)];
  }
  Node query(int u, int l, int r, int ll, int rr){ // O(logN)
    if(l > r or r < ll or l > rr or ll > rr) return Node();
    if(ll <= l and r <= rr) return st[u];
    return query(left(u), l, mid, ll, rr) + query(right(u), mid + 1, r, ll, rr);
  }
};
int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  lli n; cin >> n;
  vector<ii> a(n, {0, 0}), b(n, {0, 0});// l, r
  vi v(n);fore(i, 0, n) cin >> v[i];
  Segtree stl(n), str(n);
  fore(i, 1, n){
    if(v[i] > v[i - 1]) a[i].f = a[i - 1].f + 1;
    else b[i].f = b[i - 1].f + 1;
    stl.update(0, 0, n - 1, i, b[i].f);
  }
  for(lli i = n - 2; i >= 0; i--){
    if(v[i] > v[i + 1]) a[i].s = a[i + 1].s + 1;
    else b[i].s = b[i + 1].s + 1;
    str.update(0, 0, n - 1, i, b[i].s);
  }
  lli ans = 0;
  fore(i, 1, n - 1){
    if(!a[i].f or !a[i].s) continue;
    auto foo = stl.query(0, 0, n - 1, 0, i - a[i].f).mx;
    if(foo >= a[i].f and foo >= a[i].s) continue;
    foo = str.query(0, 0, n - 1, 0, i - a[i].f - 1).mx;
    if(foo >= a[i].f and foo >= a[i].s) continue;
    foo = str.query(0, 0, n - 1, i + a[i].s, n - 1).mx;
    if(foo >= a[i].f and foo >= a[i].s) continue;
    foo = stl.query(0, 0, n - 1, i + a[i].s + 1, n - 1).mx;
    if(foo >= a[i].f and foo >= a[i].s) continue;
    foo = min(a[i].f, a[i].s);
    if(foo & 1ll) continue;
    if(foo + 1 <= max(a[i].f, a[i].s)) continue;
    // deb(i);
    ans++;
    // foo = max(a[i].f, a[i].s);
    // if(foo % 2ll == 0) {
    //   ans++;
    //   continue;
    // }
  }
  cout << ans << ENDL;
  return 0;
}
