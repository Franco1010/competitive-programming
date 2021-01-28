/*
 © 2021-01-28 08:35:01 Franco1010 All Rights Reserved
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
bool lucky(lli x, lli d){
  while(x){
    if(x % 10ll == d) return true;
    x /= 10ll;
  }
  return false;
}
const lli N = 105;
bool isl[N];
int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  // deb(check(51, 7));
  lli t; cin >> t;
  while(t--){
    lli q, d; cin >> q >> d;
    fore(i, 1, N) isl[i] = lucky(i, d);
    fore(i, 0, N) fore(j, 0, N) if(isl[i] and isl[j] and i + j < N) isl[i + j] = true;
    fore(i, 0, q){
      lli x; cin >> x;
      if(x >= d * 10) cout << "YES" << ENDL;
      else if(isl[x]) cout << "YES" << ENDL;
      else cout << "NO" << ENDL;
    }
  }
  return 0;
}
