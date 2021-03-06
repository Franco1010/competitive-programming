/*
 © 2021-03-06 05:55:36 Franco1010 All Rights Reserved
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
lli n;
ld solve(lli u){
  if(u == n) return 0;
  ld p = ld(1) / ld(n);
  ld parteabajo = 1;
  ld e = 1;
  e += ld(p * solve(u + 1)) * ld(n - u);
  parteabajo -= p * ld(u);
  e /= parteabajo;
  return e;
}
int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  cout << fixed << setprecision(7);
  while(cin >> n){
    cout << solve(1) << ENDL;;
  }
  return 0;
}
