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

int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  lli t; cin >> t;
  while(t--){
    lli n; cin >> n;
    bool allzero = true;
    bool allone = true;
    vi v(n);
    fore(i, 0, n){
      lli x; cin >> x;
      v[i] = x;
      if(x == 0) allone = false;
      else allzero = false;
    }
    if(n == 1){
      if(v[0] == 0) cout << "1 2" << ENDL;
      else cout << "2 1" << ENDL;
    }
    else if(v.back() == 0) {fore(i, 0, n + 1) cout << i + 1 << ' '; cout << ENDL;}
    else if(v.front() == 1) {cout << n + 1 << ' '; fore(i, 0, n) cout << i + 1 << ' '; cout << ENDL;}
    else{
      bool yes = false;
      fore(i, 0, n - 1){
        if(v[i] == 0 and v[i + 1] == 1){
          yes = true;
          fore(j, 0, i + 1) cout << j + 1 << ' ';
          cout << n + 1 << ' ';
          fore(j, i + 1, n) cout << j + 1 << ' '; cout << ENDL;
          break;
        }
      }
      if(yes == false) cout << -1 << ENDL;
    }
  }
  return 0;
}
