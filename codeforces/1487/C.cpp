/*
 © 2021-02-15 08:35:01 Franco1010 All Rights Reserved
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
  lli n; cin >> n;
  vi cnt(n, 0);
  vector<vi> res(n, vi(n, 0));
  lli foo = (n * (n - 1ll)) / 2ll;
  lli bar = foo / n;
  // deb(bar);
  fore(i, 0, n - 1){
    lli pos = i + 1;
    while(pos < n and cnt[i] < bar){
      res[i][pos++] = 1;
      cnt[i]++;
    }
  }
  fore(i, 0, n - 1){
    lli pos = i + 1;
    while(pos < n and res[i][pos] == 1) pos++;
    fore(j, pos, n){
      if(cnt[j] < bar){
        res[i][j] = -1;
        cnt[j]++;
      }
    }
  }
  fore(i, 0, n){
    fore(j, i + 1, n) {
      cout << res[i][j] << ' ';
    }
  }
  cout << ENDL;
}
int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  lli t; cin >> t;
  while(t--)
  solve();
  return 0;
}
