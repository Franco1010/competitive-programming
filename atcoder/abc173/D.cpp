/*
 © 2020-07-05 06:57:04 Franco1010 All Rights Reserved
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
struct Node{
  lli x, y;
  lli val(){ return min(x, y);; }
  bool operator < (const Node & n) const {
    return min(x, y) < min(n.x, n.y);
  }
};
int main(){ _
  lli n; cin >> n;
  vector<lli> v(n);
  fore(i, 0, n) cin >> v[i];
  sort(rbegin(v), rend(v));
  priority_queue<Node> pq;
  lli ans = 0;
  for(auto i : v){
    if(pq.empty()) pq.push({i, i});
    else{
      auto x = pq.top(); pq.pop();
      ans += x.val();
      pq.push({x.x, i}); pq.push({x.y, i});
    }
  }
  cout << ans << ENDL;
  return 0;
}
