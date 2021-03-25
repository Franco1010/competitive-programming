/*
 © 2021-03-25 08:35:02 Franco1010 All Rights Reserved
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

int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  lli t; cin >> t;
  while(t--){
    lli n; cin >> n;
    vector<ii> v; fore(i, 0, n){
      lli x; cin >> x;
      if(v.empty() or x != v.back().f) v.pb({x, i});
    }
    v.pb({0, n});
    {// min
      vi ans(n, 0);
      lli last = 0;
      priority_queue<lli> pq;
      fore(i, 0, sz(v) - 1){
        ans[v[i].s] = v[i].f;
        fore(j, last + 1, v[i].f) pq.push(-j);
        fore(j, v[i].s + 1, v[i + 1].s) ans[j] = -pq.top(), pq.pop();
        last = v[i].f;
      }
      for(auto i : ans) cout << i << ' '; cout << ENDL;
    }
    {// max
      vi ans(n, 0);
      lli last = 0;
      priority_queue<lli> pq;
      fore(i, 0, sz(v) - 1){
        ans[v[i].s] = v[i].f;
        fore(j, last + 1, v[i].f) pq.push(j);
        fore(j, v[i].s + 1, v[i + 1].s) ans[j] = pq.top(), pq.pop();
        last = v[i].f;
      }
      for(auto i : ans) cout << i << ' '; cout << ENDL;
    }
  }
  return 0;
}
