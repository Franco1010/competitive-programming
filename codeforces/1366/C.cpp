/*
 © 2020-06-11 09:35:02 Franco1010 All Rights Reserved
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
    lli n, m; cin >> n >> m;
    vector<ii> cnt(n + m, {0, 0});
    fore(i, 0, n){
      fore(j, 0, m){
        lli x; cin >> x;
        if(x) cnt[i + j].s++;
        else cnt[i + j].f++;
      }
    }
    // int m = -1;
    // if((n + m - 1) % 2) m = (n + m - 1) / 2;
    lli res = 0;
    for(lli l = 0, r = n + m - 2; l < r; l++, r--){
      res += min(cnt[l].f + cnt[r].f, cnt[l].s + cnt[r].s);
    }
    // fore(i, 0, (n + m) / 2){
    //
    //   res += abs(cnt[i].f - cnt[i].s);
    // }
    cout << res << ENDL;
  }
  return 0;
}
