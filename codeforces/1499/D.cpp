/*
© 2021-03-18 08:50:01 Franco1010 Alli Rights Reserved
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
const lli N = 2e7 + 5;
lli p[N];
lli countPairs(lli G, lli L)
{
  if (L % G != 0)
  return 0;
  lli div = L/G;
  return 1ll << p[div];
}
int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  for(lli i = 2; i < N; ++i) if(!p[i]) for(lli j = i; j < N; j += i) p[j]++;
  // fore(i, 0, 30) cout << p[i] << ' '; cout << ENDL;
  lli t; cin >> t;
  while(t--){
    lli c, d, x; cin >> c >> d >> x;
    lli ans = 0;
    for(lli i = 1; i * i <= x; i++){
      if(x % i == 0){
        if(x % (x / i) == 0 and i != (x / i)){
          lli g = (x / i);
          if((x + d * g) % c == 0){
            lli l = (x + d * g) / c;
            ans += countPairs(g, l);
          }
        }
        lli g = i;
        if((x + d * g) % c == 0){
          lli l = (x + d * g) / c;
          ans += countPairs(g, l);
        }
      }
    }
    cout << ans << ENDL;
  }
  return 0;
}
