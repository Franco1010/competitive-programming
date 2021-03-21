/*
 © 2021-03-21 07:20:01 Franco1010 All Rights Reserved
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
const lli N = 1e5 + 5;
vi g[N];
lli vis[N];
lli curvis;
lli cur;
int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  lli t; cin >> t;
  while(t--){
    lli n, m; cin >> n >> m;
    fore(i, 0, n) g[i].clear();
    cur = 0;
    curvis++;
    vector<ii> ady(n, {0, 0});
    fore(i, 0, n) ady[i].s = i;
    vi fd(m, 0);
    fore(i, 0, m){
      lli k; cin >> k;
      fd[i] = k;
      while(k--){
        lli x; cin >> x; x--;
        g[x].pb(i);
        ady[x].f++;
      }
    }
    sort(all(ady));
    vi ans(m, -1);
    // for(auto i : ady) cout << "(" << i.f << ' ' << i.s << ") "; cout << ENDL;
    // fore(i,0, n){
    //   cout << i  << ": "; for(auto j : g[i]) cout << j << ' '; cout << ENDL;
    // }
    for(auto i : ady){
      sort(all(g[i.s]), [&](const lli&x, const lli& y){
        return fd[x] < fd[y];
      });
      lli now = (m + 1ll) / 2ll;
      for(auto j : g[i.s]){
        if(vis[j] != curvis and now > 0){
          now--;
          vis[j] = curvis;
          ans[j] = i.s + 1;
          cur++;
        }
      }
    }
    if(cur == m){
      cout << "YES" << ENDL;
      for(auto i : ans) cout << i << ' '; cout << ENDL;
    }else cout << "NO" << ENDL;
  }
  return 0;
}
