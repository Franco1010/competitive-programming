/*
 © 2020-09-19 07:00:13 Franco1010 All Rights Reserved
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
lli p[N];
lli fac(lli x){
  map<lli,lli> mp;
  lli res = 1;
  while(x > 1 and p[x] > 1){
    mp[p[x]]++;
    x /= p[x];
  }
  // cout << ": "; for(auto i : mp) cout << "(" << i.f << ',' << i.s << ") ";
  for(auto i : mp) res *= i.s + 1;
  return res;
}
lli div(lli x){
  lli res = 0;
  for(lli i = 1; i * i <= x; i++){
    if(x % i == 0){
      if(x/i == i) res++;
      else res += 2;
    }
  }
  return res;
}
int main(){ _
  iota(all(p), 0);
  p[0]= 1;
  for(lli i = 2; i * i <= N; i++) if(p[i] == i) for(lli j = i * i; j < N; j += i) p[j] = i;
  // fore(i, 0, 20) cout << p[i] << ' '; cout << ENDL;
  lli n; cin >> n;
  lli res = 0;
  fore(i, 1, n){
    // cout << n - i << ' ' << fac(n - i) << ENDL;
    res += fac(n - i);
  }
  cout << res << ENDL;
  return 0;
}
