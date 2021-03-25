/*
 © 2021-03-25 08:35:02 Franco1010 All Rights Reserved
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

int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  lli t; cin >> t;
  while(t--){
    lli n, k; cin >> n >> k;
    string s; cin >> s;
    lli l = 0, r = n - 1;
    while(l + 1 < n and s[l] != '*') l++;
    while(r - 1 >= 0 and s[r] != '*') r--;
    lli ans = l == r ? 1 : 2;
    while(l < r){
      l = min(l + k, n - 1);
      if(l >= r) break;
      while(s[l] == '.') l--;
      ans++;
    }
    cout << ans << ENDL;
  }
  return 0;
}
