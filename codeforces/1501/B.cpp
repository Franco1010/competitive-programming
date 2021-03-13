/*
 © 2021-03-13 03:05:01 Franco1010 All Rights Reserved
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
    Node(lli s = 0, lli lazy = -1): s(s), lazy(lazy) {}
  };
  vector<Node> st;
  Segtree(int n): st(2 * n) {}
  void push(int u, int l, int r){
    if(st[u].lazy != -1){
      if(l < r){
        st[left(u)].lazy = st[u].lazy;
        st[right(u)].lazy = st[u].lazy;
      }
      st[u].s = st[u].lazy;
      st[u].lazy = -1;
    }
  }
  void update(int u, int l, int r, int ll, int rr, lli val){ // O(logN)
    push(u, l, r);
    if(l > r or r < ll or l > rr) return;
    if(ll <= l and r <= rr){
      st[u].lazy = val;
      push(u, l, r);
      return;
    }
    update(left(u), l, mid, ll, rr, val);
    update(right(u), mid + 1, r, ll, rr, val);
  }
  void print(int u, int l, int r, int ll, int rr){
    push(u, l, r);
    if(l > r or r < ll or l > rr) return;
    if(l == r){
      cout << st[u].s << ' ';
      return;
    }
    print(left(u), l, mid, ll, rr);
    print(right(u), mid + 1, r, ll, rr);
  }
};
const lli N = 2e5 + 5;
int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  Segtree st(N);
  lli t; cin >> t;
  while(t--){
    lli n; cin >> n;
    st.update(0, 0, N - 1, 0, n - 1, 0);
    fore(i, 0, n){
      lli x; cin >> x;
      if(x) st.update(0, 0, N - 1, max(0ll, i - x + 1), i, 1);
    }
    st.print(0, 0, N - 1, 0, n - 1); cout << ENDL;
  }
  return 0;
}
