/*
 © 2020-11-15 08:35:02 Franco1010 All Rights Reserved
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
const lli N = 10 + 5;
lli mat[N][N];
int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  lli t; cin >> t;
  while(t--){
    lli n, m; cin >>n >> m;
    // vi v(n * m);
    lli mn = 1e18;
    bool sgn = false;
    lli sum = 0;
    fore(i, 0, n){
      fore(j, 0, m){
        lli x; cin >> x;
        sum += llabs(x);
        mn = min(mn, llabs(x));
        if(x < 0) sgn = !sgn;
      }
    }
    cout << sum - 2ll * mn * lli(sgn) << ENDL;
  }
  return 0;
}
