/*
 © 2021-04-17 02:06:01 Franco1010 All Rights Reserved
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
  lli a, b; cin >> a >> b;
  lli ans = 1;
  fore(i, 2, 2e5 + 1){
    lli foo = b / lli(i);
    lli bar = lli(i) * (foo - 1);
    foo = lli(i) * foo;
    if(a <= bar and foo <= b) ans = i;
  }
  cout << ans << ENDL;
  return 0;
}
