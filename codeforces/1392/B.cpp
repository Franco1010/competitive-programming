/*
 © 2020-08-16 09:35:02 Franco1010 All Rights Reserved
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
  lli t; cin >> t;
  while(t--){
    lli n, k; cin >> n >> k;
    vector<lli> v(n);
    fore(i, 0, n) {
      cin >> v[i];
    }
    lli foo = *max_element(all(v));
    for(auto &i : v) i = foo - i;
    auto v2 = v;
    foo = *max_element(all(v2));
    for(auto &i : v2) i = foo - i;
    k--;
    if(k % 2 == 0) {for(auto i : v) cout << i << ' '; cout << ENDL;}
    else {for(auto i : v2) cout << i << ' '; cout << ENDL;}
  }
  return 0;
}
