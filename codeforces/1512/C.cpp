/*
 © 2021-04-10 15:30:02 Franco1010 All Rights Reserved
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
  lli a, b; cin >> a >> b;
  string s; cin >> s;
  for(lli l = 0, r = sz(s) - 1; l <= r; l++, r--){
    if(l == r){
      if(s[l] == '0') a--;
      else if(s[r] == '1') b--;
    }else if(s[l] == '0'){
      a--;
      if(s[r] == '1'){
        cout << -1 << ENDL;
        return;
      }else s[r] = '0', a--;
    }else if(s[l] == '1'){
      b--;
      if(s[r] == '0'){
        cout << -1 << ENDL;
        return;
      }else s[r] = '1', b--;
    }else if(s[r] == '0'){
      a -= 2;
      s[l] = '0';
    }else if(s[r] == '1'){
      b -= 2;
      s[l] = '1';
    }
  }
  for(lli l = 0, r = sz(s) - 1; l <= r; l++, r--){
    if(s[l] == s[r] and s[l] == '?'){
      if(l == r){
        if(a){
          s[l] = '0';
          a--;
        }else if(b){
          s[l] = '1';
          b--;
        }
      }else{
        if(a >= 2){
          s[l] = s[r] = '0';
          a -= 2;
        }else if(b >= 2){
          s[l] = s[r] = '1';
          b -= 2;
        }
      }
    }
  }
  bool yes = true;
  for(auto i : s) if(i == '?') yes = false;
  if(yes and a == 0 and b == 0) cout << s << ENDL;
  else cout << -1 << ENDL;
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
