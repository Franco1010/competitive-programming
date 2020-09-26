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
struct segtree{
  #define mid (l + r) / 2
  #define left(u) (u + 1)
  #define right(u) (u + ((mid - l + 1) << 1))
  struct node{
    lli s;
    node(lli s = 0): s(s) {}
    node operator + (const node & n){
      return node(max(s, n.s));
    }
  };
  vector<node> st;
  segtree(int n): st(2 * n) {}
  void update(int u, int l, int r, int kth, lli val){
    if(l == r){
      st[u] = val;
      return;
    }
    if(kth <= mid) update(left(u), l, mid, kth, val);
    else update(right(u), mid + 1, r, kth, val);
    st[u] = st[left(u)] + st[right(u)];
  }
  lli query(int u, int l, int r, int ll, int rr){
    if(l > r or r < ll or l > rr) return 0;
    if(ll <= l and r <= rr) return st[u].s;
    return max(query(left(u), l, mid, ll, rr), query(right(u), mid + 1, r, ll, rr));
  }
};
const lli N = 3e5;
int main(){ _
  lli n, k; cin >> n >> k;
  vector<lli> v(n);
  segtree st(N + 1);
  lli res = 0;
  fore(i, 0, n){
    cin >> v[i];
    lli foo = st.query(0, 0, N, max(v[i] - k, 0ll), min(v[i] + k, lli(3e5))) + 1ll;
    res = max(res, foo);
    st.update(0, 0, N, v[i], foo);
  }
  cout << res << ENDL;
  return 0;
}
