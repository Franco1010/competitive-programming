/*
 © 2021-03-10 06:05:02 Franco1010 All Rights Reserved
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
    lli acu = 0;
    for(lli l = 0, r = n - 1; l < r; l++, r--){
      if(s[l] == s[r]) acu++;
      else break;
    }
    if(acu >= k and 2 * k < n) cout << "YES" << ENDL;
    else cout << "NO" << ENDL;
  }
  return 0;
}
