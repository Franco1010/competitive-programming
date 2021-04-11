/*
 © 2021-04-11 09:35:01 Franco1010 All Rights Reserved
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
    lli n, k; cin >> n >> k;
    if(k > (n - 1ll) / 2ll) cout << -1 << ENDL;
    else{
      vi v(n, -1);
      lli cur = n;
      for(lli i = 1; i < n and k > 0; i += 2) v[i] = cur--, k--;
      for(lli i = n - 1; i >= 0; i--) if(v[i] == -1) v[i] = cur--;
      for(auto i : v) cout << i << ' '; cout << ENDL;
    }
  }
  return 0;
}
// 1 5 2 4 3
// 1 6 2 5 3 4
