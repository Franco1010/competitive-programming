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
map<lli, lli> mp;
void gen(lli p = 1, lli n = 0, lli s = 0){
  if(p == 10){
    if(!mp.count(s)) mp[s] = n;
    else mp[s] = min(mp[s], n);
    return;
  }
  gen(p + 1, n * 10ll + p, s + p);
  gen(p + 1, n, s);
}
int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  gen();
  lli t; cin >> t;
  while(t--){
    lli x; cin >> x;
    if(mp.count(x)) cout << mp[x] << ENDL;
    else cout << -1 << ENDL;
  }
  return 0;
}
