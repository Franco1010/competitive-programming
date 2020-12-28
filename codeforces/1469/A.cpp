/*
 © 2020-12-28 08:35:01 Franco1010 All Rights Reserved
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
    lli p1 = -1, p2 = -1;
    fore(i, 0, sz(s)){
      if(s[i] == '(') p1 = i;
      if(s[i] == ')') p2 = i;
    }
    if(sz(s) % 2 == 0){
      if(p1 < p2) cout << "YES" << ENDL;
      else if(p2 > 0 and p1 < (sz(s) - 1)) cout << "YES" << ENDL;
      else cout << "NO" << ENDL;
    }else cout << "NO" << ENDL;
  }
  return 0;
}
