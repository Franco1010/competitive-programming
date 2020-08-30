/*
 © 2020-08-30 15:55:01 Franco1010 All Rights Reserved
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

int main(){ _
  lli n; cin >> n;
  vector<lli> v(n);
  fore(i, 0, n){
    cin >> v[i];
  }
  if(n == 1){
    cout << 1 << ' ' << 1 << ENDL << -v[0] << ENDL;
    cout << 1 << ' ' << 1 << ENDL << -v[0] << ENDL;
    cout << 1 << ' ' << 1 << ENDL << v[0] << ENDL;
  }
  else{
    cout << 1 << ' ' << n - 1 << ENDL;
    fore(i, 0, n - 1) cout << (n - 1ll) * v[i] << ' '; cout << ENDL;
    cout << 2 << ' ' << n << ENDL;
    fore(i, 1, n - 1) cout << 0 << ' '; cout << (n - 1ll) * v[n - 1] << ENDL;
    cout << 1 << ' ' << n << ENDL;
    fore(i, 0, n) cout << -n * v[i] << ' ' ; cout << ENDL;
  }
  return 0;
}
