/*
 © 2020-08-15 21:07:12 Franco1010 All Rights Reserved
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
  sort(all(v));
  // for(auto i : v) cout << i << ' '; cout << ENDL;
  lli res = 0;
  fore(i, 0, n){
    fore(j, i + 1, n){
      if(v[j] != v[i])
      fore(k, j + 1, n){
        if(v[i] != v[k] and v[j] != v[k])
        if(v[i] + v[j] > v[k]){
          // cout << v[i] << ' ' << v[j] << ' ' << v[k] << ENDL;
          res ++;
        }
      }
    }
  }
  cout << res << ENDL;
  return 0;
}
