/*
 © 2020-10-03 06:54:37 Franco1010 All Rights Reserved
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
const int N = 5e3 + 5;
lli acu[4][N];
int main(){ _
  lli n; string s; cin >> n >> s;
  fore(i, 0, n){
    fore(j, 0, 4) acu[j][i + 1] = acu[j][i];
    if(s[i] == 'A') acu[0][i + 1]++;
    if(s[i] == 'T') acu[1][i + 1]++;
    if(s[i] == 'C') acu[2][i + 1]++;
    if(s[i] == 'G') acu[3][i + 1]++;
  }
  lli res = 0;
  fore(i, 0, n){
    fore(j, i + 1, n){
      lli at = (acu[0][j + 1] - acu[0][i]) - (acu[1][j + 1] - acu[1][i]);
      lli cg = (acu[2][j + 1] - acu[2][i]) - (acu[3][j + 1] - acu[3][i]);
      if(!at and !cg) res++;
    }
  }
  cout << res << ENDL;
  return 0;
}
