/*
 © 2020-12-04 07:05:01 Franco1010 All Rights Reserved
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
    vi v(n);fore(i, 0, n){
      cin >> v[i];
    }
    lli res = 0;
    lli mn = 1e18;
    fore(i, 1, n) res += labs(v[i] - v[i - 1]);
    fore(i, 1, n - 1){
      if(i + 1 < n){
        mn = min(mn, res - labs(v[i] - v[i - 1]) - labs(v[i] - v[i + 1]) + labs(v[i - 1] - v[i + 1]));
      }
    }
    mn = min(mn, res - labs(v[0] - v[1]));
    mn = min(mn, res - labs(v[n - 1] - v[n - 2]));
    cout << mn << ENDL;
  }
  return 0;
}
