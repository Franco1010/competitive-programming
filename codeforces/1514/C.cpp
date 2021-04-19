/*
 © 2021-04-19 08:35:02 Franco1010 All Rights Reserved
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
lli n;
const lli N = 1e5 + 5;
bool mark[N];
int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  while(cin >> n){
    // deb(n);
    {
      lli x = n;
      for(lli i = 2; i * i <= x; i++){
        if(x%i == 0){
          while(x%i == 0) x/= i;
          for(lli j = i; j < N; j += i) mark[j] = true;
        }
      }
      if(x > 1){
        for(lli j = x; j < N; j += x) mark[j] = true;
      }
    }
    lli lim = 1;
    lli prod = 1;
    fore(i, 2, n){
      if(!mark[i]){
        prod = prod * lli(i) % n;
        if(prod == 1) lim = i;
      }
    }
    vi ans;
    fore(i, 1, lim + 1) if(!mark[i]) ans.pb(i);
    cout << sz(ans) << ENDL;
    for(auto i : ans) cout << i << ' '; cout << ENDL;
  }
  return 0;
}
