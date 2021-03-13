/*
 © 2021-03-13 03:05:01 Franco1010 All Rights Reserved
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
const lli MX = 2.5e6 + 5;
int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  lli n; cin >> n;
  vector<ii> ans;
  map<lli,vi> mp;
  set<lli> st;
  vector<ii> v; fore(i, 0, n){
    lli x; cin >> x;
    if(!st.count(x)) v.pb({x, i + 1});
    st.insert(x);
    mp[x].pb(i + 1);
    if(sz(mp[x]) >= 2){
      ans.pb({x, mp[x][0]});
      ans.pb({x, mp[x][1]});
      mp[x].clear();
    }
  }
  if(sz(ans) >= 4){
    cout << "YES" << ENDL;
    cout << ans[0].s << ' ' << ans[2].s << ' ' << ans[1].s << ' ' << ans[3].s << ENDL;
    return 0;
  }
  sort(all(v));
  if(sz(ans) >= 2){
    lli x = ans[0].f;
    for(auto i : v){
      if(i.f >= x) break;
      lli foo = x - i.f;
      auto bar = lower_bound(all(v), ii{x + foo, -1});
      if(bar != end(v) and (*bar).f == x + foo){
        cout << "YES" << ENDL;
        cout << i.s << ' ' << (*bar).s << ' ' << ans[0].s << ' ' << ans[1].s << ENDL;
        return 0;
      }
    }
  }
  // for(auto i : v) cout << "(" << i.f << ' ' << i.s << ") "; cout << ENDL;
  lli lim = MX / n + 5ll;
  fore(dis, 1, lim + 1){
    ii foo = {-1,-1};
    fore(i, 0, n){
      if(v[i].f > dis){
        auto l = lower_bound(all(v), ii{v[i].f - dis, -1});
        if(l != end(v) and (*l).f == v[i].f - dis){
          ii bar = {(*l).s, v[i].s};
          if(foo == ii{-1, -1}) foo = bar;
          else if(bar.f > foo.s){
            cout << "YES" << ENDL;
            cout << foo.f << ' ' << bar.s << ' ' << foo.s << ' ' << bar.f << ENDL;
            exit(0);
          }
        }
      }
    }
  }
  cout << "NO" << ENDL;
  return 0;
}
