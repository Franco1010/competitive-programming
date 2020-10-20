/*
 © 2020-10-20 16:50:02 Franco1010 All Rights Reserved
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
    lli n; cin >> n;
    lli l = 0, r = n - 1;
    vi v(n);
    fore(i, 0, n) cin >> v[i];
    while(l < sz(v) and v[l] == 0) l++;
    while(r >= 0 and v[r] == 0) r--;
    lli res = 0;
    fore(i, l, r + 1) res += (v[i] == 0);
    cout << res << ENDL;
  }
  return 0;
}
