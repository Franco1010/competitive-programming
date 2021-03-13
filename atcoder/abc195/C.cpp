/*
 © 2021-03-12 13:07:10 Franco1010 All Rights Reserved
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
const lli INF = 1e18;
int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  lli n; cin >> n;
  lli res = 0;
  res += max(0ll, n - (lli(1e3) - 1));
  res += max(0ll, n - (lli(1e6) - 1));
  res += max(0ll, n - (lli(1e9) - 1));
  res += max(0ll, n - (lli(1e12) - 1));
  res += max(0ll, n - (lli(1e15) - 1));
  cout << res << ENDL;
  return 0;
}
