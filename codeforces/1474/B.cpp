/*
 © 2021-01-19 08:35:02 Franco1010 All Rights Reserved
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
const lli N = 1e6 + 5;
bool p[N];
vi primes;
int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  p[0] = p[1] = true;
  for(lli i = 2; i * i <= N; i++) if(!p[i]) for(lli j = i * i; j < N; j += i) p[j] = true;
  fore(i, 0, N) if(!p[i]) primes.pb(i);
  lli t; cin >> t;
  while(t--){
    lli d; cin >> d;
    lli foo = lower_bound(all(primes), d + 1) - begin(primes);;
    lli bar = foo;
    while(primes[bar] - d < primes[foo] or primes[foo] * primes[bar] - d < primes[bar]) bar++;
    cout << primes[foo] * primes[bar] << ENDL;
  }
  return 0;
}
