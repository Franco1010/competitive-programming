/*
 © 2021-02-24 13:22:40 Franco1010 All Rights Reserved
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
const lli N = 2e5 + 5;
lli v[N];
bool f(lli n, lli k, lli x){
  vi pre(n, 0);
  fore(i, 0, n) pre[i] = (v[i] >= x ? +1 : -1);
  fore(i, 1, n) pre[i] += pre[i - 1];
  lli mn = 0;
  fore(i, k - 1, n){
    if(pre[i] - mn > 0) return true;
    mn = min(mn, pre[i - k + 1]);
  }
  return false;
}
lli bs(lli n, lli k){
  lli lim = 1;
  while(f(n, k, lim)) lim *= 2;
  lli pos = 1;
  for(lli p = lim; p ; p /= 2) while(pos + p <= lim and f(n, k, pos + p)) pos += p;
  return pos;
}
int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  lli n, k; cin >> n >> k;
  fore(i, 0, n) cin >> v[i];
  cout << bs(n, k) << ENDL;
  return 0;
}
