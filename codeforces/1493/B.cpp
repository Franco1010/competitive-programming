/*
 © 2021-03-06 08:05:01 Franco1010 All Rights Reserved
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
map<lli,lli> conv = {{0, 0}, {1, 1}, {2, 5}, {3, -1}, {4, -1}, {5, 2}, {6, -1}, {7, -1}, {8, 8}, {9, -1}};
bool check(lli h, lli m, lli hh, lli mm){
  if(conv[mm/10] == -1) return false;
  if(conv[mm%10] == -1) return false;
  lli hhh = conv[mm%10] * 10;
  hhh += conv[mm/10];
  if(conv[hh/10] == -1) return false;
  if(conv[hh%10] == -1) return false;
  lli mmm = conv[hh%10] * 10;
  mmm += conv[hh/10];
  return 0 <= hhh and hhh < h and 0 <= mmm and mmm < m;
}
void solve(lli h, lli m, lli hh, lli mm){
  while(true){
    if(check(h, m, hh, mm)) {
      string hhh = to_string(hh);
      string mmm = to_string(mm);
      if(sz(hhh) < 2) hhh = "0" + hhh;
      if(sz(mmm) < 2) mmm = "0" + mmm;
      cout << hhh << ":" << mmm << ENDL;
      return;
    }
    mm++;
    if(mm >= m) mm = 0, hh++;
    if(hh >= h) hh = 0;
  }
}
int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  lli t; cin >> t;
  while(t--){
    lli h, m; cin >> h >> m;
    string s; cin >> s;
    lli hh = (s[0] - '0') * 10 + (s[1] - '0');
    lli mm = (s[3] - '0') * 10 + (s[4] - '0');
    solve(h, m, hh, mm);
  }
  return 0;
}
