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
  lli t; cin >> t;
  while(t--){
    lli n, x; cin >> n >> x;
    set<lli> st;
    lli zero = 0, sum = 0;
    fore(i, 0, n){
      lli y; cin >> y;
      if(x - y == 0) zero++;
      sum += x - y;
    }
    if(zero == n) cout << 0 << ENDL;
    else if(sum == 0 or zero) cout << 1 << ENDL;
    else cout << 2 << ENDL;
  }
  return 0;
}