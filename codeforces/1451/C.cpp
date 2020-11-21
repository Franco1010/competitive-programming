/*
 © 2020-11-21 08:35:01 Franco1010 All Rights Reserved
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
    map<char, lli> a, b;
    string s;
    cin >> s; for(auto i : s) a[i]++;
    cin >> s; for(auto i : s) b[i]++;
    bool yes = true;
    for(char i = 'a'; i <= 'z'; i++){
      if(a[i]%k != b[i]%k) yes = false;
      a[i] -= a[i]%k;
      b[i] -= b[i]%k;
    }
    // for(char i = 'a'; i <= 'z'; i++) cout << a[i] << ' '; cout << ENDL;
    // for(char i = 'a'; i <= 'z'; i++) cout << b[i] << ' '; cout << ENDL;
    lli cur = 0;
    for(char i = 'a'; i <= 'z'; i++){
      cur += a[i] / k;
      cur -= b[i] / k;
      if(cur < 0) yes = false;
    }
    if(cur == 0 and yes) cout << "Yes" << ENDL;
    else cout << "No" << ENDL;
  }
  return 0;
}
