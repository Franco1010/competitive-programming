/*
 © 2020-09-19 09:35:01 Franco1010 All Rights Reserved
*/

#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("avx,avx2,fma")
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
  lli t; cin >> t;
  while(t--){
    lli n; cin >> n;
    string s; cin >> s;
    if(n % 2){
      bool ii = false;
      fore(i, 0, sz(s)){
        if(i%2 == 0 and s[i]%2) ii = true;
      }
      if(ii) cout << 1 << ENDL;
      else cout << 2 << ENDL;
    }else{
      bool pp = false;
      fore(i, 0, sz(s)){
        if(i%2 and s[i]%2==0) pp = true;
      }
      if(pp) cout << 2 << ENDL;
      else cout << 1 << ENDL;
    }
  }
  return 0;
}
