/*
 © 2021-02-23 19:45:02 Franco1010 All Rights Reserved
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
    lli last = n;
    vi v(n);
    vi pos(n + 1);
    fore(i, 0, n){
      lli x; cin >> x;
      v[i] = x;
      pos[x] = i;
    }
    for(lli i = n; i >= 1; i--){
      if(pos[i] < last){
        fore(j, pos[i], last) cout << v[j] << ' ';
        last = pos[i];
      }
    }
    cout << ENDL;
  }
  return 0;
}
