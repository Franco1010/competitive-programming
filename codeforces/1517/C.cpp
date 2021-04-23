/*
 © 2021-04-23 09:35:01 Franco1010 All Rights Reserved
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
const lli N = 5e2 + 5;
lli m[N][N];
int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  lli n; cin >> n;
  vi v(n); for(auto& i : v) cin >> i;
  vector<bool> done(n, false);
  fore(i, 0, n){
    ii pos = {i, 0};
    lli it = 0;
    while(pos.f < n and pos.s < n){
      while(done[it]) it++;
      m[pos.f][pos.s] = v[it];
      if(v[it] == i + 1) done[it] = true;
      it++;
      pos.f++, pos.s++;
    }
  }
  fore(i, 0, n){
    fore(j, 0, i + 1) cout << m[i][j] << ' '; cout << ENDL;
  }
  return 0;
}
