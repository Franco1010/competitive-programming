/*
 © 2020-05-14 09:35:01 Franco1010 All Rights Reserved
*/

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
typedef pair<int,int> ii;
#define deb(x) cout << #x": " << (x) << endl;
lli cur = 1;
void recur(lli l, lli r, vector<lli> &v){
  // cout << l << ' ' << r << ENDL;
  if(l == r) {
    v[l] = cur++;
    return;
  }
  lli mid = (l + r) / 2;
  v[mid] = cur++;
  recur(l, mid - 1, v);
  recur(mid + 1, r, v);
}
struct Node{
  lli l, r;
  bool operator < (const Node & n)const{
    if(r - l + 1 == n.r - n.l + 1) return l > n.l;
    return r - l + 1 < n.r - n.l + 1;
  }
};
int main(){ _
  lli t; cin >> t;
  while(t--){
    lli n; cin >> n;
    cur = 1;
    vector<lli> v(n);
    priority_queue<Node> pq;
    pq.push({0, n - 1});
    while(!pq.empty()){
      auto u = pq.top(); pq.pop();
      lli mid = (u.l + u.r) / 2;
      v[mid] = cur++;
      if(mid > u.l) pq.push({u.l, mid - 1});
      if(mid < u.r) pq.push({mid + 1, u.r});
    }
    for(auto i : v) cout << i << ' ' ; cout << ENDL;
  }
  return 0;
}
