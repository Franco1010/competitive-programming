/*
 © 2020-09-28 02:45:48 Franco1010 All Rights Reserved
*/

#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("avx,avx2,fma")
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
  lli t; cin >> t;
  while(t--){
    lli n; cin >> n;
    if((n / 2) % 2 == 0){
      cout << "YES" << ENDL;
      lli s = 0;
      fore(i, 0, n/2) {
        cout << lli(i + 1) * 2ll << ' ';
        s += lli(i + 1) * 2ll;
      }
      fore(i, 0, n/2 - 1){
        cout << lli(i + 1) * 2ll - 1ll << ' ';
        s -= lli(i + 1) * 2ll - 1ll;
      }
      cout << s << ENDL;
    }else cout << "NO" << ENDL;
  }
  return 0;
}
