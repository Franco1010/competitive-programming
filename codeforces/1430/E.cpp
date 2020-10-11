/*
 © 2020-10-11 04:05:01 Franco1010 All Rights Reserved
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
  struct node{
    lli s, z;
    node(lli s = 0, lli z = 0): s(s), z(z) {}
    node operator + (const node & n){
      return node(s + n.s);
    }
  };
  vector<node> st;
  // void build(int u, int l, int r){
  //   if( l == r ){
  //     st[u].s = l;
  //     return;
  //   }
  //   build(left(u), l, mid);
  //   build(right(u), mid + 1, r);
  //   st[u] = st[left(u)] + st[right(u)];
  // }

  segtree(int n){
    st.resize(2 * n);
  }
  void push(lli u, lli l, lli r){
    if(st[u].z){
      st[left(u)].z += st[u].z;
      st[left(u)].s += st[u].z;
      st[right(u)].z += st[u].z;
      st[right(u)].s += st[u].z;
      st[u].z = 0;
    }
  }
  void update(int u, int l, int r, int ll, int rr, int val){
    if(l > r or r < ll or l > rr) return;
    if(ll <= l and r <= rr){
      st[u].z += val;
      st[u].s += val;
      return;
    }
    push(u, l, r);
    update(left(u), l, mid, ll, rr, val);
    update(right(u), mid + 1, r, ll, rr, val);
    st[u] = st[left(u)] + st[right(u)];
  }

  lli query(int u, int l, int r, int ll, int rr){
    if(l > r or r < ll or l > rr) return 0;
    if( ll <= l && r <= rr ){
      return st[u].s;
    }
    push(u, l, r);
    return query(left(u), l, mid, ll, rr) +
           query(right(u), mid + 1, r, ll, rr);
  }
};

int main(){ _
  lli n; cin >> n;
  string s; cin >> s;
  string r = s;
  reverse(all(r));
  map<char,vector<lli>> mp;
  fore(i, 0, n){
    mp[s[i]].pb(i);
  }
  lli res = 0;
  for(auto &i : mp){
    reverse(all(i.s));
  }
  lli x = 0;
  segtree st(n);
  fore(i, 0, n){
    if(mp[r[i]].back() + st.query(0, 0, n - 1, mp[r[i]].back(), mp[r[i]].back()) != i){
      res += mp[r[i]].back() + st.query(0, 0, n - 1, mp[r[i]].back(), mp[r[i]].back()) - i;
      st.update(0, 0, n - 1, 0, mp[r[i]].back(), +1);
    }
    mp[r[i]].pop_back();
  }
  cout << res << ENDL;
  return 0;
}
