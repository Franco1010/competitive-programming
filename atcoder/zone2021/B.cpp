/*
 © 2021-05-01 07:01:01 Franco1010 All Rights Reserved
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
const ld EPS = 1e-9;
bool ge(ld a, ld b){return a-b > EPS;}
lli n, d, h; 
bool f(vector<pair<ld,ld>>& v, ld x){
  // y = mx + b
  ld m = (ld(h) - x) / ld(d);
  ld b = h;
  // deb(x);
  // deb(m);
  // deb(m * ld(-d) + b);
  // ld b = min(x, ld(h));
  for(auto& i : v){
    ld y = (ld(-d) + i.f) * m + b;
    // deb(y);
    if(ge(i.s, y)) return false;
  }
  return true;
}
int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  cin >> n >> d >> h;
  ld ans = 1e18;
  vector<pair<ld,ld>> v(n); for(auto& i : v) cin >> i.f >> i.s;
  ld l = 0, r = 1000;
  fore(rep, 0, 500){
    ld m = (l + r) / 2;
    if(f(v, m)) r = m;
    else l = m;
  }
  cout << fixed << setprecision(9);
  cout << l << ENDL;
  return 0;
}
