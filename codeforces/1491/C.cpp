/*
 © 2021-02-28 07:35:23 Franco1010 All Rights Reserved
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
struct Segtree{
  #define mid (l + r) / 2
  #define left(u) (u + 1)
  #define right(u) (u + ((mid - l + 1) << 1))
  struct Node{
    lli s, lazy;
    Node(lli s = 0, lli lazy = 0): s(s), lazy(lazy) {}
    Node operator + (const Node &n){
      return Node(s + n.s);
    }
  };
  vector<Node> st;
  Segtree(int n): st(2 * n) {}
  void push(int u, int l, int r){
    if(st[u].lazy){
      if(l < r){
        st[left(u)].lazy += st[u].lazy;
        st[right(u)].lazy += st[u].lazy;
      }
      st[u].s += st[u].lazy * (r - l + 1);
      st[u].lazy = 0;
    }
  }
  void update(int u, int l, int r, int ll, int rr, lli val){ // O(logN)
    push(u, l, r);
    if(l > r or r < ll or l > rr or ll > rr) return;
    if(ll <= l and r <= rr){
      st[u].lazy += val;
      push(u, l, r);
      return;
    }
    update(left(u), l, mid, ll, rr, val);
    update(right(u), mid + 1, r, ll, rr, val);
    st[u] = st[left(u)] + st[right(u)];
  }
  Node query(int u, int l, int r, int ll, int rr){ // O(logN)
    push(u, l, r);
    if(l > r or r < ll or l > rr) return Node();
    if(ll <= l and r <= rr) return st[u];
    return query(left(u), l, mid, ll, rr) + query(right(u), mid + 1, r, ll, rr);
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
int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  lli t; cin >> t;
  while(t--){
    lli n; cin >> n;
    vi v(n); for(auto& i : v) cin >> i;
    // vi acu(n, 0);
    Segtree acu(n);
    lli res = 0;
    for(lli i = 0; i < n; i++){
      lli temp = acu.query(0, 0, n - 1ll, i, i).s;
      if(v[i] > 1 and temp){
        lli mn = min(temp, v[i] - 1ll);
        acu.update(0, 0, n - 1ll, i + v[i] - mn + 1, min(n - 1ll, i + v[i]), 1ll);
        temp -= mn;
        v[i] -= mn;
      }
      if(v[i] == 1 and i + 1 < n){
        acu.update(0, 0, n - 1ll, i + 1ll, i + 1ll, temp);
      }
      // acu.update(0, 0, n - 1ll, i, i, -acu.query(0, 0, n - 1ll, i, i).s);
      lli foo = 0;
      if(v[i] > 1){
        foo += v[i] - 1ll;
        acu.update(0, 0, n - 1ll, i + 2ll, min(n - 1ll, i + v[i]), 1ll);
      }
      res += foo;
    }
    cout << res << ENDL;
  }
  return 0;
}
