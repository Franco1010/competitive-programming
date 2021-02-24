/*
 © 2021-02-23 19:45:02 Franco1010 All Rights Reserved
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
  lli a, b, k; cin >> a >> b >> k;
  vi x(a + b, 0), y(a + b, 0);
  if(a == 0){
    if(k == 0){
      x.assign(a + b, 1);
      y.assign(a + b, 1);
      cout << "Yes" << ENDL;
      for(auto i : x) cout << i; cout << ENDL;
      for(auto i : y) cout << i; cout << ENDL;
    }else cout << "No" << ENDL;
  }
  else if(b == 1){
    if(k == 0){
      x[0] = y[0] = 1;
      cout << "Yes" << ENDL;
      for(auto i : x) cout << i; cout << ENDL;
      for(auto i : y) cout << i; cout << ENDL;
    }else cout << "No" << ENDL;
  }
  else if(k >= a + b - 1) cout << "No" << ENDL;
  else{
    x[0] = y[0] = 1;
    x[1] = 1; y[1 + k] = 1;
    b -= 2;
    for(lli i = 2; b and i < sz(x); i++){
      if(i == 1 + k) continue;
      x[i] = y[i] = 1;
      b--;
    }
    cout << "Yes" << ENDL;
    for(auto i : x) cout << i; cout << ENDL;
    for(auto i : y) cout << i; cout << ENDL;
  }
  return 0;
}
