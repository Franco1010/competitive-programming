/*
 © 2021-02-07 08:35:01 Franco1010 All Rights Reserved
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
// #define ENDL '\n'
using namespace std;
typedef long double ld;
typedef long long lli;
typedef pair<lli,lli> ii;
typedef vector<lli> vi;
#define deb(x) cout << #x": " << (x) << endl;
const lli N = 1e5 + 5;
const lli INF = 1e18;
lli v[N];
lli n;
lli q(lli x){
  if(x < 1 or x > n) return INF;
  if(v[x] != -1) return v[x];
  cout << "? " << x << endl;
  lli foo; cin >> foo;
  return v[x] = foo;
}
void res(lli x){
  cout << "! " << x << endl;
  exit(0);
}
int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  fore(i, 0, N) v[i] = -1;
  cin >> n;
  lli l = 1, r = n;
  while(r - l > 1){
    lli mid = (l + r) / 2;
    if(q(mid) < q(mid - 1) and q(mid) < q(mid + 1)) res(mid);
    else if(q(mid) > q(mid - 1)) r = mid;
    else l = mid;
  }
  if(q(l) < q(l - 1) and q(l) < q(l + 1)) res(l);
  else res(r);
  return 0;
}
