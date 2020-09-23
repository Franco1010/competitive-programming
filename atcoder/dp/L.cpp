/*
 © 2020-09-23 17:36:54 Franco1010 All Rights Reserved
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
const int N = 3e3 + 5;
const lli INF = 1e18;
lli v[N];
ii dp[N][N][2];
bool vis[N][N][2];
lli n;
lli diff(ii x){
  return x.f - x.s;
}
ii solve(lli l, lli r, bool turn){
  if(l == r){
    if(turn) return {0, v[l]};
    else return {v[l], 0};
  }
  ii &ans = dp[l][r][turn];
  if(!vis[l][r][turn]){
    vis[l][r][turn] = true;
    if(turn){
      ans = {solve(l + 1, r, !turn).f, solve(l + 1, r, !turn).s + v[l]};
      ii foo = {solve(l, r - 1, !turn).f, solve(l, r - 1, !turn).s + v[r]};
      if(diff(foo) < diff(ans)) ans = foo;
    }else{
      ans = {solve(l + 1, r, !turn).f + v[l], solve(l + 1, r, !turn).s};
      ii foo = {solve(l, r - 1, !turn).f + v[r], solve(l, r - 1, !turn).s};
      if(diff(foo) > diff(ans)) ans = foo;
    }
  }
  return ans;
}
int main(){ _
  cin >> n;
  fore(i, 0, n){
    cin >> v[i];
  }
  cout << diff(solve(0, n - 1, 0)) << ENDL;
  return 0;
}
