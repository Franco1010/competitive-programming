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
bool isp(string& s){
  for(lli l = 0, r = sz(s) - 1; l < r; l++, r--){
    if(s[l] != s[r]) return false;
  }
  return true;
}
int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  lli t; cin >> t;
  while(t--){
    string s; cin >> s;
    string foo = 'a' + s;
    string bar = s + 'a';
    if(!isp(foo)){
      cout << "YES" << ENDL;
      cout << foo << ENDL;
    }else if(!isp(bar)){
      cout << "YES" << ENDL;
      cout << bar << ENDL;
    }else cout << "NO" << ENDL;
  }
  return 0;
}
// aaababaaa
