/*
 © 2020-11-24 08:35:01 Franco1010 All Rights Reserved
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
const lli N = 1e6;
bool p[N];
vi primes;
map<lli,lli> fact(lli x){
  map<lli,lli> mp;
  for(lli i = 0; i < sz(primes) and primes[i] * primes[i] <= x; i++){
    while(x % primes[i] == 0){
      x /= primes[i];
      mp[primes[i]]++;
    }
  }
  if(x > 1) mp[x]++;
  return mp;
}
int main(){ _
  p[0] = p[1] = true;
  for(lli i = 2; i * i <= N; i++) if(p[i] == false) for(lli j = i * i; j < N; j += i) p[j] = true;
  fore(i, 0, N) if(p[i] == false) primes.pb(i);
  // fore(i, 0, 20) cout << primes[i] << ' '; cout << ENDL;
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  lli t; cin >> t;
  while(t--){
    lli n; cin >> n;
    auto f = fact(n);
    // for(auto i : f) cout << "(" << i.f << ' ' << i.s << ") "; cout << ENDL;
    vector<ii> v;
    for(auto i : f) v.pb(i);
    sort(all(v), [&](const ii &a, const ii &b){
      return tuple{-a.s, a.f} < tuple{-b.s, b.f};
    });
    // for(auto i : v) cout << "(" << i.f << ' ' << i.s << ") "; cout << ENDL;
    vi res(v[0].s, 1);
    for(auto i : v){
      fore(j, 0, i.s){
        res[j] *= i.f;
      }
    }
    cout << sz(res) << ENDL;
    for(lli i = sz(res) - 1; i >= 0; i--) cout << res[i] << ' '; cout << ENDL;
  }
  return 0;
}
