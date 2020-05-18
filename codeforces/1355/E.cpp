/*
 © 2020-05-16 22:45:14 Franco1010 All Rights Reserved
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
lli n, a, r, m;
lli f(vector<lli> &v, lli x){
  lli cost = 0;
  lli add = 0, sub = 0;
  for(auto i : v){
    if(i < x) add += x - i;
    if(i > x) sub += i - x;
  }
  if(a + r > m){
    lli foo = min(add, sub);
    add -= foo;
    sub -= foo;
    cost += m * foo;
  }
  cost += a * add;
  cost += r * sub;
  return cost;
}
int main(){ _
  cin >> n >> a >> r >> m;
  vector<lli> v(n);
  fore(i, 0, n) cin >> v[i];
  lli l = 0, r = 1e9;
  while(r - l > 2){
    lli m1 = l + (r - l) / 3;
    lli m2 = r - (r - l) / 3;
    lli f1 = f(v, m1);
    lli f2 = f(v, m2);
    if(f1 <= f2) r = m2;
    else l = m1;;
  }
  lli res = 1e18;
  fore(i, l, r + 1) res = min(res, f(v, i));
  cout << res << ENDL;
  return 0;
}
