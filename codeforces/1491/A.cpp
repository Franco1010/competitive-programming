/*
 © 2021-02-28 07:35:23 Franco1010 All Rights Reserved
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
  lli n, q; cin >> n >> q;
  vi v(n);
  lli zero = 0, one = 0;
  fore(i, 0, n){
    cin >> v[i];
    if(v[i]) one++;
    else zero++;
  }
  while(q--){
    lli t, x; cin >> t >> x; x--;
    if(t == 1){
      if(v[x]) zero++, one--, v[x] = 0;
      else zero--, one++, v[x] = 1;
    }else{
      x++;
      if(one >= x) cout << 1 << ENDL;
      else cout << 0 << ENDL;
    }
  }
  return 0;
}
