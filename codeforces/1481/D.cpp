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
void solve(){
  lli n, m; cin >> n >> m;
  vector<string> g(n);
  fore(i, 0, n) cin >> g[i];
  vector<array<lli,2>> who(n, {-1, -1});
  fore(i, 0, n){
    fore(j, 0, n){
      if(i == j) continue;
      who[i][g[i][j] - 'a'] = j;
      if(g[i][j] == g[j][i]){
        cout << "YES" << ENDL;
        fore(k, 0, m + 1) cout << (k & 1ll ? i + 1 : j + 1) << ' '; cout << ENDL;
        return;
      }
    }
  }
  if(m & 1ll){
    cout << "YES" << ENDL;
    fore(i, 0, m + 1) cout << (i & 1ll ? 1 : 2) << ' '; cout << ENDL;
    return;
  }else if(n > 2){
    fore(i, 0, n){
      fore(j, 0, n){
        if(i == j) continue;
        lli k = who[j][g[i][j] - 'a'];
        if(k == -1) continue;
        cout << "YES" << ENDL;
        if((m / 2ll) & 1ll){
          vi foo = {i, j, k, j};
          fore(i, 0, m + 1) cout << foo[i%sz(foo)] + 1<< ' '; cout << ENDL;
          return;
        }else{
          vi foo = {j, k, j, i};
          fore(i, 0, m + 1) cout << foo[i%sz(foo)] + 1<< ' '; cout << ENDL;
          return;
        }
      }
    }
  }else cout << "NO" << ENDL;
}
int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  // solve();
  lli t; cin >> t;
  while(t--){
    solve();
  }
  return 0;
}
