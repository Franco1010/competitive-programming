/*
 © 2020-09-19 19:46:47 Franco1010 All Rights Reserved
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
const lli INF = 1e18;
struct segtree{
  #define mid (l + r) / 2
  #define left(u) (u + 1)
  #define right(u) (u + ((mid - l + 1) << 1))
  struct node{
    lli s, z;
    node(lli s = 0, lli z = 0): s(s), z(z) {}
    node operator + (const node &n){
      return node(max(s, n.s));
    }
  };
  vector<node> st;
  segtree(int n): st(2 * n) {}
  void push(int u, int l, int r){
    if(st[u].z){
      st[u].s = max(st[u].s, st[u].z);
      if(l < r){
        st[left(u)].s = max(st[left(u)].s, st[u].z);
        st[left(u)].z = max(st[left(u)].z, st[u].z);
        st[right(u)].s = max(st[right(u)].s, st[u].z);
        st[right(u)].z = max(st[right(u)].z, st[u].z);
      }
      st[u].z = 0;
    }
  }
  void update(int u, int l, int r, int ll, int rr, lli val){
    push(u, l, r);
    if(l > r or r < ll or l > rr) return;
    if(ll <= l and r <= rr){
      st[u].s = max(val, st[u].s);
      st[u].z = max(val, st[u].z);
      push(u, l, r);
      return;
    }
    push(u, l, r);
    update(left(u), l, mid, ll, rr, val);
    update(right(u), mid + 1, r, ll, rr, val);
    st[u] = st[left(u)] + st[right(u)];
  }
  lli query(int u, int l, int r, int ll, int rr){
    push(u, l, r);
    if(l > r or r < ll or l > rr) return 0;
    if(ll <= l and r <= rr) return st[u].s;
    push(u, l, r);
    return max(query(left(u), l, mid, ll, rr), query(right(u), mid + 1, r, ll, rr));
  }
};
int main(){ _
  lli n, k; cin >> n >> k;
  segtree sv(n), sh(n);
  sv.update(0, 0, n - 1, 0, n - 1, 1);
  sv.update(0, 0, n - 1, n - 1, n - 1, n);
  sh.update(0, 0, n - 1, 0, n - 1, 1);
  sh.update(0, 0, n - 1, 0, 0, n);
  lli res = (n - 2ll) * (n - 2ll);
  while(k--){
    lli q, x; cin >> q >> x;
    if(q == 1){
      lli foo = sv.query(0, 0, n - 1, x - 1, x - 1);
      res -= max(0ll, n - foo - 1);
      sv.update(0, 0, n - 1, x - 1, x - 1, n);
      sh.update(0, 0, n - 1, foo, n - 1, n - x + 1);
    }else{
      lli foo = sh.query(0, 0, n - 1, n - x, n - x);
      res -= max(0ll, n - foo - 1);
      sh.update(0, 0, n - 1, n - x, n - x, n);
      sv.update(0, 0, n - 1, 0, n - foo - 1, n - x + 1);
    }
  }
  cout << res << ENDL;
  return 0;
}
