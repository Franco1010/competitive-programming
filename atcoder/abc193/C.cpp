/*
 © 2021-02-27 05:57:52 Franco1010 All Rights Reserved
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
int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  set<lli> st;
  lli n; cin >> n;
  lli foo = n;
  fore(i, 2, 1e5 + 1){
    lli cur = lli(i) * lli(i);
    while(cur <= n){
      st.insert(cur);
      cur *= i;
    }
  }
  cout << n - sz(st) << ENDL;
  return 0;
}
