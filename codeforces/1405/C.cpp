/*
 © 2020-09-07 15:00:02 Franco1010 All Rights Reserved
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
    lli n, k; cin >> n >> k;
    string s; cin >> s;
    vector<bool> zero(k), one(k);
    bool yes = true;
    fore(i, 0, n){
      if(s[i] == '0') zero[i%k] = true;
      else if(s[i] == '1') one[i%k] = true;
      if(zero[i%k] and one[i%k]) yes = false;
    }
    // for(auto i : zero) cout << i << ' '; cout << ENDL;
    // for(auto i : one) cout << i << ' '; cout << ENDL;
    // for(auto i : sign) cout << i << ' '; cout << ENDL;
    if(yes) {
      lli foo = 0, bar = 0;
      fore(i, 0, k){
        if(zero[i]) foo++;
        else if(one[i]) bar++;
      }
      if(foo > k/2 or bar > k/2) cout << "NO" << ENDL;
      else cout << "YES" << ENDL;
    }
    else cout << "NO" << ENDL;
  }
  return 0;
}
