/*
 © 2021-02-12 08:50:01 Franco1010 All Rights Reserved
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
struct node{
  lli x, y, z;
};
lli f(lli a, lli b, lli lim){
  queue<node> q;
  q.push({a, max(2ll, b), b == 1ll ? 1 : 0});
  while(!q.empty()){
    auto u = q.front(); q.pop();
    if(u.x == 0) return u.z;
    if(u.z + 1 <= lim) q.push({u.x/u.y, u.y, u.z + 1});
    if(u.z + 1 <= lim) q.push({u.x, u.y + 1, u.z + 1});
  }
  return 0;
}
int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  lli t; cin >> t;
  while(t--){
    lli a, b; cin >> a >> b;
    lli foo = 0, bar = a;
    while(bar) bar /= max(b, 2ll), foo++;
    cout << f(a, b, foo + 1) << ENDL;
  }
  return 0;
}
