/*
 © 2021-01-30 00:27:16 Franco1010 All Rights Reserved
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
  lli n, m; cin >> n >> m;
  priority_queue<lli> q;
  fore(i, 0, n){
    lli x; cin >> x;
    q.push(x);
  }
  fore(i, 0, m){
    lli x = q.top(); q.pop();
    x /= 2;
    q.push(x);
  }
  lli res = 0;
  while(!q.empty()){
    res += q.top();
    q.pop();
  }
  cout << res << ENDL;
  return 0;
}
