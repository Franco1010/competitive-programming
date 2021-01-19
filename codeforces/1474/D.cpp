/*
 © 2021-01-19 12:38:28 Franco1010 All Rights Reserved
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
bool can(lli a, lli b, lli c, lli d){
  if(a == b and b == c and c == d and d == 0) return true;
  bool yes = false;
  if(min(a, b)) yes |= can(a - min(a, b), b - min(a, b), c, d);
  if(min(b, c)) yes |= can(a, b - min(b, c), c - min(b, c), d);
  if(min(c, d)) yes |= can(a, b, c - min(c, d), d - min(c, d));
  return yes;
}
void solve(){
  lli n; cin >> n;
  vi v(n), vl(n), vr(n);
  vector<bool> okl(n, true), okr(n, true);
  fore(i, 0, n){
    lli x; cin >> x;
    v[i] = vl[i] = vr[i] = x;
  }
  lli last = v[0];
  fore(i, 1, n){
    okl[i] = okl[i - 1];
    if(vl[i] < last) okl[i] = false;
    else{
      vl[i] -= last;
      last = vl[i];
    }
  }
  last = v[n - 1];
  for(lli i = n - 2; i >= 0; i--){
    okr[i] = okr[i + 1];
    if(vr[i] < last) okr[i] = false;
    else{
      vr[i] -= last;
      last = vr[i];
    }
  }
  fore(i, 1, n){
    if(okl[i - 1] and okr[i] and vl[i - 1] == vr[i]){
      cout << "YES" << ENDL;
      return;
    }
    if(i == 1 or okl[i - 2]){
      if(i == n - 1 or okr[i + 1]){
        if(can(i == 1 ? 0 : vl[i - 2], v[i], v[i - 1], i == n - 1 ? 0 : vr[i + 1])){
          cout << "YES" << ENDL;
          return;
        }
      }
    }
  }
  cout << "NO" << ENDL;
}
int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  lli t; cin >> t;
  while(t--){
    solve();
  }
  return 0;
}
