/*
 © 2021-04-17 02:06:01 Franco1010 All Rights Reserved
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
#define mid l + (r - l) / 2
typedef struct ST *PST;
struct Node{
  lli s, t1, t2, acu1, acu2;
  Node(lli s = 0, lli t1 = 0, lli t2 = 0, lli acu1 = 0, lli acu2 = 0):
        s(s), t1(t1), t2(t2), acu1(acu1), acu2(acu2) {}
  Node operator + (const Node& n){
    Node foo;
    foo.s = s + n.s;
    foo.s += n.acu1 * t2;
    foo.s += n.acu2 * t1;
    foo.t1 = t1 + n.t1;
    foo.t2 = t2 + n.t2;
    foo.acu1 = acu1 + n.acu1;
    foo.acu2 = acu2 + n.acu2;
    return foo;
  }
};
struct ST {
	Node data;
	PST l, r;
  ST(Node data = Node()): data(data), l(0), r(0) {}
};
Node data(PST& u){return u ? u->data : Node();}
void pull(PST& u){u->data = data(u->l) + data(u->r);}
void update(PST& u, lli l, lli r, lli kth, lli val, lli t){
  if(l == r){
    if(t == 1){
      u->data.t1 += val;
      // u->data.t1 = max(0ll, u->data.t1);
      u->data.acu1 = (u->data.t1 * l);
    }else{
      u->data.t2 += val;
      // u->data.t2 = max(0ll, u->data.t2);
      u->data.acu2 = (u->data.t2 * l);
    }
    u->data.s = (u->data.t1 * u->data.t2 * l);
    return;
  }
  if(kth <= mid){
    if(!u->l) u->l = new ST();
    update(u->l, l, mid, kth, val, t);
  }
  else {
    if(!u->r) u->r = new ST();
    update(u->r, mid + 1, r, kth, val, t);
  }
  pull(u);
}
// Node query(PST& u, lli l, lli r, lli ll, lli rr){
//   if(!u or l > r or r < ll or l > rr) return Node();
//   if(ll <= l and r <= rr) return u->data;
//   return query(u->l, l, mid, ll, rr) + query(u->r, mid + 1, r, ll, rr);
// }
const lli N = 1e8 + 5;
int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  lli n, m, q; cin >> n >> m >> q;
  vi a(n, 0), b(m, 0);
  PST st = new ST();
  fore(i, 0, n) update(st, 0, N, a[i], +1, 1);
  fore(i, 0, m) update(st, 0, N, b[i], +1, 2);
  fore(i, 0, q){
    lli t, x, y; cin >> t >> x >> y; x--;
    if(t == 1){
      update(st, 0, N, a[x], -1, t);
      a[x] = y;
      update(st, 0, N, a[x], +1, t);
    }else{
      update(st, 0, N, b[x], -1, t);
      b[x] = y;
      update(st, 0, N, b[x], +1, t);
    }
    cout << st->data.s << ENDL;
  }
  return 0;
}
