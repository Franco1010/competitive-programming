/*
 © 2021-03-02 08:45:02 Franco1010 All Rights Reserved
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
bool solve(vi& v, vi& ext, lli pos = 0, vi acu = vi(4, 0)){
  if(pos >= 4){
    fore(i, 0, 4) if(acu[i] > v[i]) return false;
    return true;
  }
  if(ext[pos] == 2){
    acu[(pos - 1 + 4)%4]++;
    acu[(pos + 1 + 4)%4]++;
    return solve(v, ext, pos + 1, acu);
  }
  if(ext[pos] == 1){
    bool yes = false;
    acu[(pos - 1 + 4)%4]++;
    yes |= solve(v, ext, pos + 1, acu);
    acu[(pos - 1 + 4)%4]--;
    acu[(pos + 1 + 4)%4]++;
    yes |= solve(v, ext, pos + 1, acu);
    acu[(pos + 1 + 4)%4]--;
    return yes;
  }
  return solve(v, ext, pos + 1, acu);
}
int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  lli t; cin >> t;
  while(t--){
    lli n; cin >> n;
    vi v(4); fore(i, 0, 4) cin >> v[i];
    vi ext(4, 0); fore(i, 0, 4){
      ext[i] = max(0ll, v[i] - (n - 2));
    }
    cout << (solve(v, ext) ? "YES" : "NO") << ENDL;
  }
  return 0;
}
