/*
 © 2020-09-04 09:35:02 Franco1010 All Rights Reserved
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
struct segtree{
  #define mid (l + r) / 2
  #define left(u) (u + 1)
  #define right(u) (u + ((mid - l + 1) << 1))
  struct Node{
    lli s;
    Node(lli s = 0): s(s) {}
    Node operator + (const Node & n){
      return Node(max(s, n.s));
    }
  };
  vector<Node> st;
  segtree(int n){
    st.resize(2 * n);
  }
  void update(int u, int l, int r, int kth, lli val){
    if(l == r){
      st[u].s = val;
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
int main(){ _
  lli t; cin >> t;
  while(t--){
    lli n, k; cin >> n >> k;
    map<lli,lli> mp;
    fore(i, 0, n){
      lli x; cin >> x;
      mp[x]++;
    }
    vector<ii> v;
    lli cur = 0;
    deque<ii> q;
    for(auto i : mp){
      q.pb(i);
      cur += i.s;
      while(q.front().f < i.f - k) {
        cur -= q.front().s;
        q.pop_front();
      }
      v.pb({i.f, cur});
    }
    // v.pb({i, cur});
    // for(auto i : v) cout << i.s << ' '; cout << ENDL;
    segtree st(sz(v));
    fore(i, 0, sz(v)){
      st.update(0, 0, sz(v) - 1, i, v[i].s);
    }
    fore(i, 0, n) {
      lli x; cin >> x;
    }
    lli res = 0;
    lli l = -1, r = 0;
    fore(i, 0, sz(v)){
      while(r + 1 < sz(v) and v[r].f - k <= v[i].f) r++;
      while(l + 1 < sz(v) and v[l + 1].f < v[i].f - k) l++;
      lli foo = 0;
      if( v[r].f - k > v[i].f ) foo = max(foo, st.query(0, 0, sz(v) - 1, r, sz(v) - 1));
      if( l >= 0 and v[i].f - k > v[l].f ) foo = max(foo, st.query(0, 0, sz(v) - 1, 0, l));
      res = max(res, v[i].s + foo);
    }
    cout << res << ENDL;
  }
  return 0;
}
