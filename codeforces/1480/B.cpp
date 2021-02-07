/*
 © 2021-02-07 08:35:01 Franco1010 All Rights Reserved
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
struct st{
  lli a, b, foo, tot;
};
void solve(){
  lli A, B, n; cin >> A >> B >> n;
  vector<st> v(n);
  fore(i, 0, n) cin >> v[i].a;
  fore(i, 0, n) cin >> v[i].b;
  fore(i, 0, n){
    v[i].foo = v[i].b / A + lli(v[i].b % A != 0);
    v[i].tot = (v[i].foo - 1) * v[i].a;
    B -= v[i].tot;
  }
  if(B <= 0){
    cout << "NO" << ENDL;
    return;
  }
  sort(all(v), [&](const st& a, const st& b){
    return a.a < b.a;
  });
  fore(i, 0, n){
    if(B <= 0){
      cout << "NO" << ENDL;
      return;
    }
    B -= v[i].a;
  }
  cout << "YES" << ENDL;
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
