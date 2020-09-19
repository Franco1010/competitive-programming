/*
 © 2020-09-19 07:38:49 Franco1010 All Rights Reserved
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
const lli MOD = 998244353;
struct segtree{
  #define mid (l + r)/2
  #define left(u) (u + 1)
  #define right(u) (u + ((mid - l + 1) << 1))
  struct node{
    lli s;
    node(lli s = 0): s(s) {}
    node operator + (const node & n){
      return node((s + n.s) % MOD);
    }
  };
  vector<node> st;
  int n;
  segtree(int n): n(n), st(2 * n) {}
  void update(int u, int l, int r, int kth, int val){
    if(l == r){
      st[u].s = (st[u].s + val) % MOD;
      return;
    }
    if(kth <= mid) update(left(u), l, mid, kth, val);
    else update(right(u), mid + 1, r, kth, val);
    st[u] = st[left(u)] + st[right(u)];
  }
  lli query(int u, int l, int r, int ll, int rr){
    if(l > r or r < ll or l > rr) return 0;
    if(ll <= l and r <= rr) return st[u].s % MOD;
    return (query(left(u), l, mid, ll, rr) + query(right(u), mid + 1, r, ll, rr)) % MOD;
  }
  lli qq(int l, int r){
    return query(0, 1, n, max(l, 1), min(r, n));
  }
};
int main(){ _
  lli n, k; cin >> n >> k;
  vector<ii> v;
  fore(i, 0, k){
    lli l, r ;cin >> l >> r;
    v.pb({l, r});
  }
  segtree st(n);
  st.update(0, 1, n, 1, 1);
  fore(i, 1, n + 1){
    for(auto j : v){
      st.update(0, 1, n, i, st.qq(i - j.s, i - j.f));
    }
  }
  cout << st.qq(n, n) << ENDL;
  return 0;
}
