/*
 © 2021-03-12 13:07:10 Franco1010 All Rights Reserved
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
const lli INF = 1e18;
int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  lli n, m, q; cin >> n >> m >> q;
  vector<ii> v(n); for(auto&[a, b] : v) cin >> a >> b;
  vector<ii> box(m); fore(i, 0, m){
    cin >> box[i].f;
    box[i].s = i;
  }
  sort(all(box));
  while(q--){
    lli l, r; cin >> l >> r; l--, r--;
    vector<bool> used(n, false);
    lli ans = 0;
    fore(i, 0, m){
      if(!(l <= box[i].s and box[i].s <= r)){
        lli best = -1;
        fore(j, 0, n){
          if(v[j].f <= box[i].f and !used[j] and (best == -1 or v[best].s < v[j].s)){
            best = j;
          }
        }
        if(best != -1){
          used[best] = true;
          ans += v[best].s;
        }
      }
    }
    cout << ans << ENDL;
  }
  return 0;
}
