/*
 © 2021-01-23 05:54:10 Franco1010 All Rights Reserved
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
struct Dato{
  ii xy, signo, add;
};
const lli N = 2e5 + 5;
lli v[2][N];
Dato vm[N];
int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  lli n; cin >> n;
  fore(i, 1, n + 1){
    cin >> v[0][i] >> v[1][i];
  }
  lli m; cin >> m;
  vm[0].xy = {0, 1};
  vm[0].signo = {1, 1};
  vm[0].add = {0, 0};
  fore(i, 1, m + 1){
    vm[i] = vm[i - 1];
    lli x; cin >> x;
    if(x == 1){
      swap(vm[i].xy.f, vm[i].xy.s);
      swap(vm[i].add.f, vm[i].add.s);
      swap(vm[i].signo.f, vm[i].signo.s);
      vm[i].signo.s *= -1ll;
      vm[i].add.s *= -1ll;
    }
    if(x == 2){
      swap(vm[i].xy.f, vm[i].xy.s);
      swap(vm[i].add.f, vm[i].add.s);
      swap(vm[i].signo.f, vm[i].signo.s);
      vm[i].signo.f *= -1ll;
      vm[i].add.f *= -1ll;
    }
    if(x == 3){
      lli y; cin >> y;
      vm[i].signo.f *= -1;
      vm[i].add.f = 2ll * y - vm[i].add.f;
    }
    if(x == 4){
      lli y; cin >> y;
      vm[i].signo.s *= -1;
      vm[i].add.s = 2ll * y - vm[i].add.s;
    }
  }
  lli q; cin >> q;
  while(q--){
    lli a, b; cin >> a >> b;
    cout << v[vm[a].xy.f][b] * vm[a].signo.f + vm[a].add.f << ' ';
    cout << v[vm[a].xy.s][b] * vm[a].signo.s + vm[a].add.s << ENDL;
  }
  return 0;
}
