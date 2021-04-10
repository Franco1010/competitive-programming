/*
 © 2021-04-10 15:30:02 Franco1010 All Rights Reserved
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
  lli sum = 0;
  vi v(n + 2); for(auto& i : v) cin >> i, sum += i;
  sort(all(v));
  // for(auto i : v) cout << i << ' '; cout << ENDL;
  if(sum - v[n] - v[n + 1] == v[n]){
    fore(i, 0, n) cout << v[i] << ' '; cout << ENDL;
    return;
  }
  sum -= v[n + 1];
  fore(i, 0, n + 1) if(sum - v[i] == v[n + 1]){
    fore(j, 0, n + 1) if(j != i) cout << v[j] << ' '; cout << ENDL;
    return;
  }
  cout << -1 << ENDL;
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
