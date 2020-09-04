/*
 © 2020-09-04 09:35:02 Franco1010 All Rights Reserved
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
const int N = 19;
const int M = 162 + 5;
lli dp[N][M][2];
lli vis[N][M][2];
lli pot[N];
lli curvis;
lli solve(string &s, int res, int pos = 0, bool gre = false){
  if(pos >= N) return 0;
  lli &ans = dp[pos][res][gre];
  if(vis[pos][res][gre] != curvis){
    ans = 1e18;
    vis[pos][res][gre] = curvis;
    if(gre){
      fore(i, 0, min(10, res + 1)){
        ans = min(ans, pot[N - pos - 1] * lli(i - (s[pos] - '0')) + solve(s, res - i, pos + 1, gre));
      }
    }
    else{
      fore(i, s[pos] - '0', min(10, res + 1)){
        ans = min(ans, pot[N - pos - 1] * lli(i - (s[pos] - '0')) + solve(s, res - i, pos + 1, gre or i > (s[pos] - '0')));
      }
    }
  }
  return ans;
}
int main(){ _
  pot[0] = 1;
  fore(i, 1, N) pot[i] = pot[i - 1] * 10ll;
  lli t; cin >> t;
  while(t--){
    string n; lli s; cin >> n >> s;
    reverse(all(n));
    while(sz(n) < N) n.pb('0');
    reverse(all(n));
    curvis++;
    cout << solve(n, s) << ENDL;
  }
  return 0;
}
