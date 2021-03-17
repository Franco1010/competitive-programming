/*
 © 2021-03-17 08:35:01 Franco1010 All Rights Reserved
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
    if(n&1ll) cout << 1 << ' ' << (n - 1ll) / 2ll << ' ' << (n - 1ll) / 2ll << ENDL;
    else if(n%4ll == 0ll) cout << n / 2ll << ' ' << n / 4ll << ' ' << n / 4ll << ENDL;
    else cout << 2 << ' ' << (n - 2ll) / 2ll << ' ' << (n - 2ll) / 2ll << ENDL;
  }
  return 0;
}
