/*
 © 2021-03-18 08:50:01 Franco1010 All Rights Reserved
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
const lli N = 1e5 + 5;
lli c[N];
int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  lli t; cin >> t;
  while(t--){
    lli n; cin >> n;
    lli mni = 1e18, mnp = 1e18;
    lli acui = 0, acup = 0;
    lli cnti = 0, cntp = 0;
    lli ans = 1e18;
    fore(i, 0, n){
      cin >> c[i];
      if(i&1ll) mni = min(mni, c[i]), acui += c[i], cnti++;
      else mnp = min(mnp, c[i]), acup += c[i], cntp++;
      if(i){
        lli foo = acui + (n - cnti) * mni;
        lli bar = acup + (n - cntp) * mnp;
        ans = min(ans, foo + bar);
      }
    }
    cout << ans << ENDL;
  }
  return 0;
}
