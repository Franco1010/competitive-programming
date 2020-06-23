/*
 © 2020-06-23 09:05:02 Franco1010 All Rights Reserved
*/

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
typedef pair<int,int> ii;
#define deb(x) cout << #x": " << (x) << endl;

int main(){ _
  lli t; cin >> t;
  while(t--){
    lli n, k; cin >> n >> k;
    vector<lli> v(n), f;
    lli ans = 0;
    lli l = 0, r = n - 1;
    fore(i, 0, n) cin >> v[i];
    sort(all(v));
    fore(i, 0, k){
      lli x; cin >> x;
      if(x == 1){
        ans += 2ll * v[r--];
      }
      else f.pb(x);
    }
    sort(rbegin(f), rend(f));
    for(auto i : f){
      ans += v[r--];
      ans += v[l];
      l += i - 1;
    }
    cout << ans << ENDL;
  }
  return 0;
}
