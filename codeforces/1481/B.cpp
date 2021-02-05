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
  lli n, k; cin >> n >> k;
  vi v(n); for(auto& i : v) cin >> i;
  lli last = -1;
  fore(i, 0, k){
    lli pos = -1;
    fore(i, 0, n - 1){
      if(v[i] < v[i + 1]){
        pos = i;
        break;
      }
    }
    if(pos == -1){
      cout << -1 << ENDL;
      return;
    }
    v[pos]++;
    last = pos;
  }
  cout << last + 1 << ENDL;
}
int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  lli t; cin >> t;
  while(t--){
    solve();
  }
  return 0;
}
