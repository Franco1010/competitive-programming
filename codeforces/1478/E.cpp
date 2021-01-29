/*
 © 2021-01-28 08:35:01 Franco1010 All Rights Reserved
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
    lli zero, one, z;
    bool pro;
    Node(lli zero = 0, lli one = 0, lli z = 0, bool pro = 0): zero(zero), one(one), z(z), pro(pro) {}
    Node operator + (const Node& n){
      return Node(zero + n.zero, one + n.one);
    }
  };
  vector<Node> st;
  Segtree(int n): st(2 * n) {}
  void push(int u, int l, int r){
    if(st[u].pro){
      if(l < r){
        st[left(u)].z = st[right(u)].z = st[u].z;
        st[left(u)].pro = st[right(u)].pro = true;
      }
      lli foo = (r - l + 1ll);
      st[u] = Node(foo * (st[u].z == 0), foo * (st[u].z == 1));
    }
  }
  void update(int u, int l, int r, int ll, int rr, lli val){
    push(u, l, r);
    if(l > r or r < ll or l > rr) return;
    if(ll <= l and r <= rr){
      st[u].z = val;
      st[u].pro = true;
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
      cout << (st[u].zero ? 0 : 1) << ' ';
      return;
    }
    print(left(u), l, mid);
    print(right(u), mid + 1, r);
  }
};
void solve(){
  lli n, q; cin >> n >> q;
  string s, f; cin >> s >> f;
  Segtree st(n);
  fore(i, 0, n) st.update(0, 0, n - 1, i, i, f[i] == '1');
  vector<ii> v(q); for(auto &i : v) cin >> i.f >> i.s;
  reverse(all(v));
  for(auto [l, r] : v){
    lli tam = r - l + 1ll;
    auto foo = st.query(0, 0, n - 1, l - 1, r - 1);
    if(foo.zero > foo.one) st.update(0, 0, n - 1, l - 1, r - 1, 0);
    else if(foo.one > foo.zero) st.update(0, 0, n - 1, l - 1, r - 1, 1);
    else{
      cout << "NO" << ENDL;
      return;
    }
  }
  fore(i, 0, n){
    auto foo = st.query(0, 0, n - 1, i, i);
    if((foo.zero and s[i] == '1') or (foo.one and s[i] == '0')){
      cout << "NO" << ENDL;
      return;
    }
  }
  cout << "YES" << ENDL;
}
int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  lli t; cin >> t;
  while(t--){
    solve();
  }
  return 0;
}
