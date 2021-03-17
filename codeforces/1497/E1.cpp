/*
 © 2021-03-17 08:35:01 Franco1010 All Rights Reserved
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
const lli MAXN = 1e7 + 5;
lli p[MAXN];
lli vis[MAXN];
lli curvis;
lli f(lli n){
  lli ans = 1;
  while(n > 1){
    lli foo = p[n], cnt = 0;
    while(foo == p[n]) n /= p[n], cnt++;
    if(cnt&1ll) ans *= foo;
  }
  return ans;
}
int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  for(lli i = 2; i < MAXN; i++) if(!p[i]) for(lli j = i; j < MAXN; j += i) p[j] = i;
  lli t; cin >> t;
  while(t--){
    lli n, k; cin >> n >> k;
    vi v(n);
    fore(i, 0, n){
      lli x; cin >> x; v[i] = f(x);
    }
    lli ans = 0, cur = 0;
    curvis++;
    fore(i, 0, n){
      if(vis[v[i]] == curvis){
        curvis++;
        ans++;
        vis[v[i]] = curvis, cur = 1;
      }else vis[v[i]] = curvis, cur++;
    }
    if(cur) ans++;
    cout << ans << ENDL;
  }
  return 0;
}
