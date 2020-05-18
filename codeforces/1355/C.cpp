/*
 © 2020-05-16 22:45:14 Franco1010 All Rights Reserved
*/

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
typedef pair<int,int> ii;
#define deb(x) cout << #x": " << (x) << endl;
const int N = 5e5 + 5;
struct SegTree{
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
  SegTree(int n){
    st.resize(2 * n);
  }
  void push(int u, int l, int r){
    if(st[u].lazy){
      st[left(u)].s += st[u].lazy;
      st[right(u)].s += st[u].lazy;
      st[left(u)].lazy += st[u].lazy;
      st[right(u)].lazy += st[u].lazy;
      st[u].lazy = 0;
    }
  }
  void update(int u, int l, int r, int ll, int rr){
    if(l > r or r < ll or l > rr) return;
    if(ll <= l and r <= rr){
      st[u].s += 1;
      st[u].lazy += 1;
      return;
    }
    push(u, l, r);
    update(left(u), l, mid, ll, rr);
    update(right(u), mid + 1, r, ll, rr);
    st[u] = st[left(u)] + st[right(u)];
  }
  lli query(int u, int l, int r, int ll, int rr){
    if(l > r or r < ll or l > rr) return 0;
    if(ll <= l and r <= rr) return st[u].s;
    return query(left(u), l, mid, ll, rr) + query(right(u), mid + 1, r, ll, rr);
  }
  void floor(int u, int l, int r){
    if(l == r) return;
    push(u, l, r);
    floor(left(u), l, mid);
    floor(right(u), mid + 1, r);
    st[u] = st[left(u)] + st[right(u)];
  }
};
int main(){ _
  lli a, b, c, d; cin >> a >> b >> c >> d;
  lli n = 2 * N + 5;
  SegTree st(n);
  fore(i, a, b + 1){
    st.update(0, 0, n - 1, i + b, i + c);
  }
  st.floor(0, 0, n - 1);
  lli res = 0;
  fore(i, c, d + 1){
    res += st.query(0, 0, n - 1, i + 1, n - 1);
  }
  cout << res << ENDL;
  return 0;
}
// 1 2 3 4 5 6 7
// 0 0 1 2 1 0 0
