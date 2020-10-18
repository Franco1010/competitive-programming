/*
 © 2020-10-17 21:42:39 Franco1010 All Rights Reserved
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
map<lli,set<lli>> mp;
vector<ii> ans;
vi res, v;
lli x;
bool solve(lli pos){
  // bool yes = false;
  // cout << pos << ": " << v[pos] << ENDL;
  ans.pb({x, pos});
  if(v[pos] == 1) {
    x++;
    mp[1].erase(pos);
    return true;
  }
  if(v[pos] == 2){
    auto foo = mp[1].upper_bound(pos);
    if(foo != end(mp[1])){
      bool yes = solve(*foo);
      if(yes){
        mp[2].erase(pos);
        return true;
      }
    }
  }
  if(v[pos] == 3){
    auto foo = mp[1].upper_bound(pos);
    auto bar = mp[2].upper_bound(pos);
    auto foobar = mp[3].upper_bound(pos);
    vector<ii> aux;
    aux.pb({1, foo != end(mp[1]) ? *foo : 1e18});
    aux.pb({2, bar != end(mp[2]) ? *bar : 1e18});
    aux.pb({3, foobar != end(mp[3]) ? *foobar : 1e18});
    sort(all(aux), [&](const ii &a, const ii &b){
      return a.s < b.s;
    });
    // for(auto i : aux) cout << "(" << i.f << ' ' << i.s << ") "; cout << ENDL;
    if(aux.front().s != lli(1e18)){
      ans.pb({x, aux.front().s});
      x++;
      bool yes = solve(aux.front().s);
      if(yes){
        mp[3].erase(pos);
        mp[aux.front().f].erase(aux.front().s);
        return true;
      }
    }
  }
  return false;
}
int main(){ _
  lli n; cin >> n;
  v.resize(n);
  // res.resize(n, 0);
  fore(i, 0, n){
    cin >> v[i];
    if(v[i] == 1) mp[1].insert(i);
    if(v[i] == 2) mp[2].insert(i);
    if(v[i] == 3) mp[3].insert(i);
  }
  x = 1;
  fore(i, 0, n){
    if(mp[1].count(i) or mp[2].count(i) or mp[3].count(i)) {
      if(!solve(i)){
        cout << -1 << ENDL;
        return 0;
      }
    }
  }
  if(mp[1].empty() and mp[2].empty() and mp[3].empty() and x <= n + 1){
    cout << sz(ans) << ENDL;
    for(auto i : ans) cout << i.f << ' ' << i.s + 1ll << ENDL;
  }else cout << -1 << ENDL;
  return 0;
}
