/*
 © 2020-12-16 02:25:26 Franco1010 All Rights Reserved
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
    lli n; cin >> n;
    string s; cin >> s;
    bool yes = false;
    fore(i, 0, 5){
      auto foo = s.substr(0, i);
      auto bar = s.substr(sz(s) - (4 - i), (4 - i));
      foo += bar;
      if(foo == "2020"){
        yes = true;
        break;
      }
    }
    if(yes) cout << "YES" << ENDL;
    else cout << "NO" << ENDL;
  }
  return 0;
}
