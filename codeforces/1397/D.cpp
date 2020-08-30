/*
 © 2020-08-30 15:55:01 Franco1010 All Rights Reserved
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
    lli n; cin >> n;
    priority_queue<lli> pq;
    fore(i, 0, n){
      lli x; cin >> x;
      pq.push(x);
    }
    while(sz(pq) >= 2){
      lli foo = pq.top(); pq.pop();
      lli bar = pq.top(); pq.pop();
      foo--;
      bar--;
      if(foo) pq.push(foo);
      if(bar) pq.push(bar);
    }
    if(pq.empty()) cout << "HL" << ENDL;
    else cout << "T" << ENDL;
  }
  return 0;
}
