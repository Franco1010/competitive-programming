/*
 © 2020-09-27 20:15:02 Franco1010 All Rights Reserved
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
    map<lli,lli> a, b; // 0, 1
    vector<lli> res(n);
    fore(i, 0, n){
      lli x; cin >> x;
      if(a[k - x] > b[k - x]) res[i] = 1, b[x]++;
      else res[i] = 0, a[x]++;
    }
    for(auto i : res) cout << i << ' '; cout << ENDL;
  }
  return 0;
}
