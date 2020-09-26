/*
 © 2020-09-26 07:00:12 Franco1010 All Rights Reserved
*/

#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
// #include <atcoder/all>
#define f first
#define s second
#define fore(i,a,b) for(int i = (a), ThxMK = (b); i < ThxMK; ++i)
#define pb push_back
#define all(s) begin(s), end(s)
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define sz(s) int(s.size())
#define ENDL '\n'
using namespace std;
// using namespace atcoder;
typedef long double ld;
typedef long long lli;
typedef pair<lli,lli> ii;
typedef vector<lli> vi;
#define deb(x) cout << #x": " << (x) << endl;
const lli N = 2e5 + 5;
const lli MOD = 998244353;
lli pot[N];
struct segtree{
  #define mid (l + r) / 2
  #define left(u) (u + 1)
  #define right(u) (u + ((mid - l + 1) << 1))
  struct node{
    lli s, z;
    node(lli s = 0, lli z = 0): s(s), z(z) {}
    node operator + (const node & n){
      return node((s + n.s + MOD) % MOD);
    }
  };
  vector<node> st;
  segtree(int n): st(2 * n) {}
  void push(int u, int l, int r){
    if(st[u].z){
      lli foo = (pot[l] - pot[r + 1] + MOD) % MOD;
      st[u].s = st[u].z * foo % MOD;
      if(l < r){
        st[left(u)].z = st[u].z;
        st[right(u)].z = st[u].z;
      }
      st[u].z = 0;
    }
  }
  void update(int u, int l, int r, int ll, int rr, lli dd){
    push(u, l, r);
    if(l > r or r < ll or l > rr) return;
    if(ll <= l and r <= rr){
      st[u].z += dd;
      push(u, l, r);
      return;
    }
    push(u, l, r);
    update(left(u), l, mid, ll, rr, dd);
    update(right(u), mid + 1, r, ll, rr, dd);
    st[u] = st[left(u)] + st[right(u)];
  }
};
int main(){ _
  lli n, q; cin >> n >> q;
  pot[n + 1] = 0;
  pot[n] = 1;
  for(lli i = n - 1; i >= 0; i--){
    pot[i] = pot[i + 1] * 10ll % MOD;
  }
  for(lli i = n - 1; i >= 0; i--){
    pot[i] = (pot[i] + pot[i + 1] + MOD) % MOD;
  }
  // fore(i, 0, n + 1) cout << pot[i] << ' '; cout << ENDL;
  segtree st(n);
  st.update(0, 1, n, 1, n, 1);
  while(q--){
    lli l, r, d; cin >> l >> r >> d;
    st.update(0, 1, n, l, r, d);
    cout << st.st[0].s << ENDL;
  }
  return 0;
}
