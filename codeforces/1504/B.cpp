/*
 © 2021-04-03 16:45:01 Franco1010 All Rights Reserved
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
void solve(){
  lli n; cin >> n;
  string a, b; cin >> a >> b;
  lli cnt0 = 0, cnt1 = 0;
  for(auto i : b) if(i == '0') cnt0++; else cnt1++;
  bool inv = false;
  for(lli i = n - 1; i >= 0; i--){
    char foo;
    if(inv) foo = b[i] == '0' ? '1' : '0';
    else foo = b[i];
    if(foo != a[i]){
      if(cnt0 != cnt1){
        cout << "NO" << ENDL;
        return;
      }
      inv = !inv;
      swap(cnt0, cnt1);
    }
    if(inv) b[i] == '0' ? cnt1-- : cnt0--;
    else b[i] == '0' ? cnt0-- : cnt1--;
  }
  cout << "YES" << ENDL;
}
int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  lli t; cin >> t;
  while(t--){
    solve();
  }
  return 0;
}
