/*
 © 2021-09-21 23:47:41 Franco1010 All Rights Reserved
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

const lli N = 1e7 + 5;
const lli INF = 1e18;
lli v[N];
int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  lli n; cin >> n;
  lli ans = INF;
  ii res;
  fore(i, 0, n){
    lli x; cin >> x;
    if(v[x]){
      if(x < ans){
        ans = x;
        res.f = v[x];
        res.s = i + 1;
      }
    }
    v[x] = i + 1;
  }
  for(lli i = 1; i < N; i++){
    lli a(INF), b(INF);
    for(lli j = i; j < N; j += i){
      if(v[j]){
        if(a == INF) a = j;
        else{
          b = j;
          if(a / i * b < ans){
            ans = a / i * b;
            res = {v[a], v[b]};
            if(res.f > res.s) swap(res.f, res.s);
          }
        }
      }
    }
  }
  cout << res.f << ' ' << res.s << ENDL;
  return 0;
}
