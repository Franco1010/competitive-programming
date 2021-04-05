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
// #define ENDL '\n'
using namespace std;
typedef long double ld;
typedef long long lli;
typedef pair<lli,lli> ii;
typedef vector<lli> vi;
#define deb(x) cout << #x": " << (x) << endl;

int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  lli n; cin >> n;
  vector<ii> even, odd;
  fore(i, 1, n + 1){
    fore(j, 1, n + 1){
      if((i + j)&1) odd.pb({i, j});
      else even.pb({i, j});
    }
  }
  while(!odd.empty() or !even.empty()){
    lli x; cin >> x;
    if(x == 1){
      if(!odd.empty()){
        cout << 2 << ' ' << odd.back().f << ' ' << odd.back().s << endl;
        odd.pop_back();
      }else{
        cout << 3 << ' ' << even.back().f << ' ' << even.back().s << endl;
        even.pop_back();
      }
    }
    if(x == 2){
      if(!even.empty()){
        cout << 1 << ' ' << even.back().f << ' ' << even.back().s << endl;
        even.pop_back();
      }else{
        cout << 3 << ' ' << odd.back().f << ' ' << odd.back().s << endl;
        odd.pop_back();
      }
    }
    if(x == 3){
      if(!even.empty()){
        cout << 1 << ' ' << even.back().f << ' ' << even.back().s << endl;
        even.pop_back();
      }else{
        cout << 2 << ' ' << odd.back().f << ' ' << odd.back().s << endl;
        odd.pop_back();
      }
    }
  }
  return 0;
}
