/*
 © 2021-06-04 09:35:01 Franco1010 All Rights Reserved
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
struct Segtree{ // TODO: poder Monoid y F = function<Monoid(Monoid, Monoid)>;
  #define mid (l + r) / 2
  #define left(u) (u + 1)
  #define right(u) (u + ((mid - l + 1) << 1))
  struct Node{
    char ch;
    lli s;
    Node(lli ch = '?', lli s = 0): ch(ch), s(s) {}
  };
  vector<Node> st;
  Segtree(int n): st(2 * n) {}
  void update(int u, int l, int r, int ll, int rr, char val){ // O(logN)
    if(l > r or r < ll or l > rr) return;
    if(l == ll and r == rr){
      // cout << "llego " << ll << ' ' << rr << ENDL;
      if(l == r){
        st[u].ch = val;
        if(val == '?') st[u].s = 2;
        else st[u].s = 1;
      }else{
        st[u].ch = val;
        if(val == '0') st[u].s = st[left(u)].s;
        else if(val == '1') st[u].s = st[right(u)].s;
        else st[u].s = st[left(u)].s + st[right(u)].s;
      }
      return;
    }
    update(left(u), l, mid, ll, rr, val);
    update(right(u), mid + 1, r, ll, rr, val);
    if(st[u].ch == '0') st[u].s = st[left(u)].s;
    else if(st[u].ch == '1') st[u].s = st[right(u)].s;
    else st[u].s = st[left(u)].s + st[right(u)].s;
  }
};
int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  lli k; cin >> k;
  vi v = {0};
  lli cur = 1;
  fore(i, 0, k){
    v.pb(cur);
    cur *= 2ll;
  }
  reverse(all(v));
  string s; cin >> s;
  vector<ii> pre(sz(s) + 1);
  cur = 1;
  fore(i, 0, k){
    lli foo = 0;
    fore(j, 0, v[i]){
      pre[j + cur] = {foo, foo + (1ll << lli(i)) - 1ll};
      foo = pre[j + cur].s + 1ll;
    }
    cur += v[i];
  }
  lli N = 1ll << (k - 1ll);
  Segtree st(N);
  fore(i, 0, sz(s)){
    st.update(0, 0, N - 1, pre[i + 1].f, pre[i + 1].s, s[i]);
  }
  lli q; cin >> q;
  while(q--){
    lli pos; char x; cin >> pos >> x;
    st.update(0, 0, N - 1, pre[pos].f, pre[pos].s, x);
    cout << st.st[0].s << ENDL;
  }
  // for(auto i : pre) cout << i << ' '; cout << ENDL;
  // for(auto i : pre) cout << "(" << i.f << ' ' << i.s << ") "; cout << ENDL;
  return 0;
}
