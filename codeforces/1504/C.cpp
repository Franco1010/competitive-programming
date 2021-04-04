/*
 © 2021-04-03 16:45:01 Franco1010 All Rights Reserved
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
    lli n; string s; cin >> n >> s;
    lli cnt = 0;
    for(auto i : s) if(i == '0') cnt++;
    if(cnt%2 == 0 and s.front() == '1' and s.back() == '1'){
      cout << "YES" << ENDL;
      string bar; lli foo = (n - cnt) / 2;
      fore(i, 0, n){
        if(s[i] == '1') foo > 0 ? bar.pb('(') : bar.pb(')'), foo--;
        else cnt%2 ? bar.pb(')') : bar.pb('('), cnt--;
      }
      cout << bar << ENDL;
      fore(i, 0, n) if(s[i] == '0') bar[i] = bar[i] == ')' ? '(' : ')';
      cout << bar << ENDL;
    }else cout << "NO" << ENDL;
  }
  return 0;
}
