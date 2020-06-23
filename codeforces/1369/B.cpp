/*
 © 2020-06-23 09:05:02 Franco1010 All Rights Reserved
*/

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
typedef pair<int,int> ii;
#define deb(x) cout << #x": " << (x) << endl;

int main(){ _
  lli t; cin >> t;
  while(t--){
    lli n; cin >> n;
    lli x = -1, y = -1;
    string s;cin >> s;
    fore(i, 0, n){
      if(x == -1 and s[i] == '1') x = i;
      if(s[i] == '0') y = i;
    }
    string res = "";
    if(x != -1 and y != -1 and x < y){
      fore(i, 0, x) res.pb(s[i]);
      res.pb('0');
      fore(i, y + 1, n) res.pb(s[i]);
    }else res = s;
    cout << res << ENDL;
  }
  return 0;
}
// 1 0 1 0 1
