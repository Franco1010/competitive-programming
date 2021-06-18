/*
 © 2021-06-18 09:35:01 Franco1010 All Rights Reserved
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
    lli n; cin >> n;
    vi v(n); for(auto& i : v) cin >> i;
    sort(all(v));
    lli pos = -1;
    lli diff = v.back() - v.front();
    fore(i, 1, n){
      if(v[i] - v[i - 1] < diff){
        diff = v[i] - v[i - 1];
        pos = i - 1;
      }
    }
    fore(i, pos + 1, n) cout << v[i] << ' ';
    fore(i, 0, pos + 1) cout << v[i] << ' '; cout << ENDL;
  }
  return 0;
}
