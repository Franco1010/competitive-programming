/*
 © 2021-08-15 09:35:02 Franco1010 All Rights Reserved
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
pair<lli,string> solve(string s){
  lli ans = 0;
  fore(i, 1, sz(s)){
    if(s[i] == '?'){
      if(s[i - 1] == 'R') s[i] = 'B';
      else s[i] = 'R';
    }else{
      ans += s[i] == s[i - 1];
    }
  }
  return {ans, s};
}
int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  lli t; cin >> t;
  while(t--){
    lli n; cin >> n;
    string s; cin >> s;
    pair<lli,string> ans = {1e18, ""};
    if(s[0] == '?'){
      s[0] = 'R';
      ans = min(ans, solve(s));
      s[0] = 'B';
      ans = min(ans, solve(s));
    }else ans = solve(s);
    cout << ans.s << ENDL;
  }
  return 0;
}
