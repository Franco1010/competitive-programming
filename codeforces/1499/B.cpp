/*
 © 2021-03-18 08:50:01 Franco1010 All Rights Reserved
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
    string s; cin >> s;
    lli n = sz(s);
    vector<bool> dp(n, false);
    dp[0] = true;
    dp[1] = true;
    fore(i, 2, n){
      if(s[i] >= s[i - 1] and dp[i - 1]) dp[i] = true;
      if(s[i] >= s[i - 2] and dp[i - 2]) dp[i] = true;
    }
    cout << (dp[n - 1] or dp[n - 2] ? "YES" : "NO") << ENDL;
  }
  return 0;
}
