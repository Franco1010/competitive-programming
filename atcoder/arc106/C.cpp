/*
 © 2020-10-24 07:00:00 Franco1010 All Rights Reserved
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
  lli n, m; cin >> n >> m;
  if(m == 0){
    fore(i, 0, n) cout << lli(i) * 2ll + 1 << ' ' << lli(i) * 2ll + 2ll << ENDL;
  }else if(m > 0 and n >= m + 2){
    fore(i, 0, m + 1) cout << lli(i) * 2ll + 2 << ' ' << lli(i) * 2ll + 3 << ENDL;
    cout << 1 << ' ' << lli(m) * 2ll + 4 << ENDL;
    lli cur = lli(m) * 2ll + 5;
    n -= m + 2;
    while(n--){
      cout << cur << ' ' << cur + 1 << ENDL;
      cur += 2;
    }
  }else cout << -1 << ENDL;
  return 0;
}
