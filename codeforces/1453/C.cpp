/*
 © 2020-12-04 07:05:01 Franco1010 All ris Reserved
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
const lli N = 2e3 + 5;
const lli INF = 1e18;
string mat[N];
lli le[N][10];
lli ri[N][10];
lli up[N][10];
lli dn[N][10];
int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  lli t; cin >> t;
  while(t--){
    lli n; cin >> n;
    vi gle(10, INF), gri(10, -INF), gup(10, INF), gdn(10, -INF);
    fore(i, 0, N) fore(j, 0, 10) le[i][j] = up[i][j] = INF;
    fore(i, 0, N) fore(j, 0, 10) ri[i][j] = dn[i][j] = -INF;
    fore(i, 0, n){
      cin >> mat[i];
      fore(j, 0, n){
        lli foo = mat[i][j] - '0';
        le[i][foo] = min(le[i][foo], lli(j));
        up[j][foo] = min(up[j][foo], lli(i));
        ri[i][foo] = max(ri[i][foo], lli(j));
        dn[j][foo] = max(dn[j][foo], lli(i));
        gle[foo] = min(gle[foo], lli(j));
        gup[foo] = min(gup[foo], lli(i));
        gri[foo] = max(gri[foo], lli(j));
        gdn[foo] = max(gdn[foo], lli(i));
      }
    }
    vi res(10, 0);
    fore(dig, 0, 10){
      fore(i, 0, n){
        fore(j, 0, n){
          if((j - le[i][dig] >= 0) and (i - gup[dig] >= 0))
            res[dig] = max(res[dig], (j - le[i][dig]) * (i - gup[dig]));
          if((j - le[i][dig] >= 0) and (gdn[dig] - i >= 0))
            res[dig] = max(res[dig], (j - le[i][dig]) * (gdn[dig] - i));

          if((ri[i][dig] - j >= 0) and (i - gup[dig] >= 0))
            res[dig] = max(res[dig], (ri[i][dig] - j) * (i - gup[dig]));
          if((ri[i][dig] - j >= 0) and (gdn[dig] - i >= 0))
            res[dig] = max(res[dig], (ri[i][dig] - j) * (gdn[dig] - i));

          if(i - up[j][dig] >= 0 and j - gle[dig] >= 0)
            res[dig] = max(res[dig], (i - up[j][dig]) * (j - gle[dig]));
          if(i - up[j][dig] >= 0 and gri[dig] - j >= 0)
            res[dig] = max(res[dig], (i - up[j][dig]) * (gri[dig] - j));

          if(dn[j][dig] - i >= 0 and j - gle[dig] >= 0)
            res[dig] = max(res[dig], (dn[j][dig] - i) * (j - gle[dig]));
          if(dn[j][dig] - i >= 0 and gri[dig] - j >= 0)
            res[dig] = max(res[dig], (dn[j][dig] - i) * (gri[dig] - j));
        }
      }
    }
    for(auto i : res) cout << i << ' '; cout << ENDL;
  }
  return 0;
}
