/*
 © 2020-06-28 09:35:02 Franco1010 All Rights Reserved
*/

#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("avx,avx2,fma")
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
// lli bs(lli x,
int main(){ _
  lli t; cin >> t;
  while(t--){
    lli n, k; cin >> n >>k;
    vector<lli> v;
    map<lli,lli> mp;
    fore(i, 0, n){
      lli x; cin >> x;
      lli foo = (k - (x % k) + k) % k;;
      if(foo) mp[foo]++;
    }
    lli cur = 0;
    lli res = 0;
    while(not mp.empty()){
      vector<lli> aux;
      for(auto &i : mp){
        lli foo = (k + (i.f - cur)) % k;
        res += foo + 1;
        cur = (cur + foo + 1) % k;
        i.s--;
        if(not i.s) aux.pb(i.f);
      }
      for(auto i : aux) mp.erase(i);
    }
    cout << res << ENDL;
  }
  return 0;
}
