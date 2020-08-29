/*
 © 2020-08-29 06:57:42 Franco1010 All Rights Reserved
*/

#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("avx,avx2,fma")
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
const int N = 1e6 + 5;
lli gcd(lli a, lli b){
  return b ? gcd(b, a % b) : a;
}
lli p[N];
lli mp[N];
bool pairw = true;
void fac(lli x){
  set<lli> foo;
  while(x > 1){
    if(!foo.count(p[x])){
      mp[p[x]]++;
      if(mp[p[x]] > 1) pairw = false;
      foo.insert(p[x]);
    }
    x /= p[x];
  }
}
int main(){ _
  iota(all(p), 0);
  for(lli i = 2; i * i <= N; i++) if(p[i] == i) for(lli j = i * i; j < N; j += i) if(p[j] == j) p[j] = i;
  // fore(i, 0, N) if(!p[i]) primes.pb(i);
  // fore(i, 0, 20) cout << primes[i] << ' '; cout << ENDL;
  lli n; cin >> n;
  vector<lli> v(n);
  set<lli> st;
  lli x = 0;
  fore(i, 0, n){
    cin >> v[i];
    if(x) x = gcd(x, v[i]);
    else x = v[i];
    fac(v[i]);
  }
  if(pairw) cout << "pairwise coprime" << ENDL;
  else if(x == 1) cout << "setwise coprime" << ENDL;
  else cout << "not coprime" << ENDL;
  return 0;
}
