/*
 © 2021-01-16 17:40:00 Franco1010 All Rights Reserved
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
  lli n; cin >> n;
  vi a(n), b(n);
  fore(i, 0, n) cin >> a[i];
  fore(i, 0, n) cin >> b[i];
  lli mx = -1e18;
  lli res = -1e18;
  fore(i, 0, n){
    mx = max(a[i], mx);
    res = max(res, b[i] * mx);
    cout << res << ENDL;
  }
  return 0;
}
