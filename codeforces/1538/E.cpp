/*
 © 2021-06-10 09:35:02 Franco1010 All Rights Reserved
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
lli eval(string foo){
  string base = "haha";
  lli ans = 0;
  fore(i, 0, sz(foo)){
    bool yes = true;
    fore(j, 0, sz(base)){
      if(i + j >= sz(foo)){
        yes = false;
        break;
      }
      if(foo[i + j] != base[j]){
        yes = false;
        break;
      }
    }
    if(yes) ans++;
  }
  return ans;
}
struct Node{
  string pre, suf;
  lli tot;
  string full;
  Node(string pre = "", string suf = "", lli tot = 0, string full = "-1"): pre(pre), suf(suf), tot(tot), full(full) {}
  Node operator + (const Node& n) {
    Node res = Node(pre, n.suf, tot + n.tot);
    if(full != "-1" and n.full != "-1" and sz(full) + sz(n.full) < 50){
      string foo = full + n.full;
      res.pre = res.suf = foo;
      res.full = foo;
      // res.pre = "";
      // res.suf = "";
      // fore(i, 0, min(sz(foo), 5)) res.pre += foo[i];
      // lli cnt = 0;
      // for(lli i = sz(foo) - 1; i >= 0; i--){
      //   res.suf += foo[i];
      //   cnt++;
      //   if(cnt == 5) break;
      // }
      // res.full = foo;
    }else{
      res.full = "-1";
    }
    string foo = "";
    lli cnt = 0;
    for(lli i = sz(suf) - 1; i >= 0; i--){
      foo = suf[i] + foo;
      cnt++;
      if(cnt == 3) break;
    }
    cnt = 0;
    fore(i, 0, sz(n.pre)){
      foo += n.pre[i];
      cnt++;
      if(cnt == 3) break;
    }
    // deb(foo);
    // deb(eval(foo));
    res.tot += eval(foo);
    return res;
  }
  friend ostream& operator << (ostream& os, const Node& n) {
    return os << "(" << n.pre << ' ' << n.tot << ' ' << n.suf << "): " << n.full;
  }
};
int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  lli t; cin >> t;
  while(t--){
    // deb(eval("haha"));
    map<string, Node> mp;
    lli n; cin >> n;
    string var;
    cin.get();
    while(n--){
      string s; getline(cin, s);
      // deb(s);
      stringstream ss(s);
      ss >> var;
      string op; ss >> op;
      if(op == ":="){
        ss >> s;
        mp[var] = Node(s, s, eval(s), s);
        // deb(mp[var]);
      }else{
        string l, r;
        ss >> l >> s >> r;
        mp[var] = mp[l] + mp[r];
        // deb(mp[var]);
        // exit(0);
      }
    }
    auto foo = mp[var];
    cout << foo.tot << ENDL;
    // string foo = mp[var];
    // cout << ans << ENDL;
    // break;
  }
  return 0;
}
