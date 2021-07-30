/*
 © 2021-07-30 09:35:01 Franco1010 All Rights Reserved
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
void rec(string& s, lli left){
  fore(i, 0, sz(s)){
    fore(j, i + 1, sz(s)){
      bool yes = true;
      for(lli l = i, r = j; l < r; l++, r--){
        if(s[l] != s[r]){
          yes = false;
          break;
        }
      }
      if(yes) return;
    }
  }
  if(left == 0){
    cout << s << ENDL;
    return;
  }
  for(char x = 'a'; x <= 'c'; x++){
    s.pb(x);
    rec(s, left - 1);
    s.pop_back();
  }
}
const vector<string> bases = {"abc", "acb", "bac", "bca", "cab", "cba"};
int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  lli n, m; cin >> n >> m;
  string s; cin >> s;
  vector<vi> pre;
  for(auto base : bases){
    string foo = base;
    while(sz(foo) < n) foo += base;
    vi bar(n + 1, 0);
    fore(i, 0, n){
      bar[i + 1] = bar[i];
      if(s[i] != foo[i]) bar[i + 1]++;
    }
    pre.pb(bar);
  }
  while(m--){
    lli l, r; cin >> l >> r; l--;
    lli ans = 1e18;
    fore(i, 0, sz(pre)){
      ans = min(ans, pre[i][r] - pre[i][l]);
    }
    cout << ans << ENDL;
  }
  // fore(i, 2, 20){
  //   string s = "";
  //   rec(s, i);
  //   cout << ENDL;
  // }
  return 0;
}
