/*
 © 2021-06-10 09:35:02 Franco1010 All Rights Reserved
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
const lli N = 1e7;
bool p[N];
vi primes;
lli fac(lli a){
  lli foo = 0;
  for(auto i : primes){
    if(i * i > a) break;
    while(a % i == 0){
      a /= i;
      foo++;
    }
  }
  if(a > 1) foo++;
  return foo;
}
int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  for(lli i = 2; i * i <= N; i++) if(!p[i]) for(lli j = i * i; j < N; j += i) p[j] = true;
  fore(i, 2, N) if(!p[i]) primes.pb(i);
  lli t; cin >> t;
  while(t--){
    lli a, b, k; cin >> a >> b >> k;
    lli foo = fac(a) + fac(b);
    // auto aa = fac(a);
    // auto bb = fac(b);
    // cout << a << ": "; for(auto i : aa) cout << "(" << i.f << ' ' << i.s << ") "; cout << ENDL;
    // cout << b << ": "; for(auto i : bb) cout << "(" << i.f << ' ' << i.s << ") "; cout << ENDL;
    if(k == 1){
      if(a != b and (a % b == 0  or b % a == 0))cout << "YES" << ENDL;
      else cout << "NO" << ENDL;
    }
    else if(foo >= k) cout << "YES" << ENDL;
    else cout << "NO" << ENDL;
  }
  return 0;
}
