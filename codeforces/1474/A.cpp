/*
 © 2021-01-19 08:35:02 Franco1010 All Rights Reserved
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
  lli t; cin >> t;
  while(t--){
    lli n ;cin >> n;
    string s; cin >> s;
    string res = "";
    lli last = -1;
    fore(i, 0, n){
      if(last == -1){
        res.pb('1');
        last = s[i] - '0' + 1;
      }else if(last == 0){
        if(s[i] == '0'){
          res.pb('1');
          last = 1;
        }else{
          res.pb('1');
          last = 2;
        }
      }else if(last == 1){
        if(s[i] == '0'){
          res.pb('0');
          last = 0;
        }else{
          res.pb('1');
          last = 2;
        }
      }else{
        if(s[i] == '0'){
          res.pb('1');
          last = 1;
        }else{
          res.pb('0');
          last = 1;
        }
      }
    }
    cout << res << ENDL;
  }
  return 0;
}
