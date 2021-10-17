/*
 © 2021-10-17 06:05:02 Franco1010 All Rights Reserved
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
bool isp(lli x){
  if(x == 0 or x == 1) return false;
  for(lli i = 2; i * i <= x; i ++){
    if(x % i == 0) return false;
  }
  return true;
}
int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  // fore(i, 0, 20) cout << isp(i) << ' '; cout << ENDL;
  lli t; cin >> t;
  while(t--){
    lli n; cin >> n;
    lli s = 0;
    lli isodd = -1;
    fore(i, 0, n){
      lli x; cin >> x;
      s += x;
      if(x & 1ll) isodd = i;
    }
    if(s % 2ll == 0ll or !isp(s)){
      cout << n << ENDL;
      fore(i, 0, n) cout << i + 1 << ' '; cout << ENDL;
    }else{
      cout << n - 1 << ENDL;
      fore(i, 0, n){
        if(isodd == i) continue;
        cout << i + 1 << ' ';
      }
      cout << ENDL;
    }
  }
  return 0;
}
