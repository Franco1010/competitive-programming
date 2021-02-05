/*
 © 2021-02-05 08:35:01 Franco1010 All Rights Reserved
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
    lli n, m; cin >> n >> m;
    vi v(n); for(auto& i : v) cin >> i;
    vector<vi> req(n + 1);
    map<lli,lli> done;
    lli need = 0;
    fore(i, 0, n){
      lli x; cin >> x;
      if(v[i] != x){
        req[x].pb(i);
        need++;
      }else done[x] = i;
    }
    vi uss;
    vi res;
    fore(i, 0, m){
      lli x; cin >> x;
      if(!req[x].empty()){
        while(!uss.empty()){
          res[uss.back()] = req[x].back();
          uss.pop_back();
        }
        done[x] = req[x].back();
        res.pb(req[x].back());
        req[x].pop_back();
        need--;
      }else if(done.count(x)){
        while(!uss.empty()){
          res[uss.back()] = done[x];
          uss.pop_back();
        }
        res.pb(done[x]);
      }else{
        uss.pb(sz(res));
        res.pb(-1);
      }
    }
    if(!uss.empty() or need) cout << "NO" << ENDL;
    else{
      cout << "YES" << ENDL;
      for(auto i : res) cout << i + 1 << ' '; cout << ENDL;
    }
  }
  return 0;
}
