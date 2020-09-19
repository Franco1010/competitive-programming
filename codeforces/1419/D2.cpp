/*
 © 2020-09-19 09:35:01 Franco1010 All Rights Reserved
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
  fore(i, 0, n) cin >> v[i];
  sort(all(v));
  vector<lli> res(n);
  fore(i, 0, n / 2) res[i * 2 + 1] = v[i];
  fore(i, n/2, n) res[(i - n/2) * 2] = v[i];
  lli ans = 0;
  fore(i, 1, n - 1){
    if(res[i] < res[i - 1] and res[i] < res[i + 1]) ans++;
  }
  cout << ans << ENDL;
  for(auto i : res) cout << i << ' '; cout << ENDL;
  return 0;
}
