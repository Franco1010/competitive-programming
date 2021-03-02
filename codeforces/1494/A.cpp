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
bool val(string& s){
  stack<char> st;
  for(auto i : s){
    if(i == ')'){
      if(!st.empty() and st.top() == '(') st.pop();
      else st.push(i);
    }else st.push(i);
  }
  return sz(st) == 0;
}
void solve(){
  string s; cin >> s;
  fore(i, 0, 2){
    fore(j, 0, 2){
      fore(k, 0, 2){
        string foo = s;
        for(auto& c : foo){
          if(c == 'A') c = i == 0 ? '(' : ')';
          if(c == 'B') c = j == 0 ? '(' : ')';
          if(c == 'C') c = k == 0 ? '(' : ')';
        }
        if(val(foo)){
          cout << "YES" << ENDL;
          return;
        }
      }
    }
  }
  cout << "NO" << ENDL;
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
