/*
 © 2021-04-21 23:01:37 Franco1010 All Rights Reserved
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
const lli N = 2e5 + 5;
bool k[N];
int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  lli n; cin >> n;
  lli x = 64;
  lli sum = 0;
  vi v(n); for(auto& i : v) cin >> i, x = min(x, lli(__builtin_ctzll(i)));
  for(auto& i : v) i >>= x, sum += i;
  if(sum&1ll){
    cout << 0 << ENDL;
    return 0;
  }
  k[0] = true;
  for(auto& i : v) for(lli j = N - 1; j >= i; j--) if(k[j - i]) k[j] = true;
  if(!k[sum / 2ll]){
    cout << 0 << ENDL;
    return 0;
  }
  fore(i, 0, n){
    if(v[i]&1ll){
      cout << 1 << ENDL;
      cout << i + 1 << ENDL;
      return 0;
    }
  }
  return 0;
}
