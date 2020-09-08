/*
 © 2020-09-08 09:35:38 Franco1010 All Rights Reserved
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
vector<lli> v;
lli n;
void solve(){
  ii cur = {0, 0};
  fore(i, 0, n){
    if(v[i]) cur.s++;
    else cur.f++;
    ii aux = {0, 0};
    fore(j, i + 1, n){
      if(v[j]) aux.s++;
      else aux.f++;
    }
    if(cur.s%2 == 0 and cur.s <= n/2 and cur.s + aux.f >= n/2){
      fore(j, 0, cur.s) cout << 1 << ' ';
      fore(j, 0, n/2 - cur.s) cout << 0 << ' ';
      cout << ENDL;
      return;
    }
    if(aux.s%2 == 0 and aux.s <= n/2 and cur.f + aux.s >= n/2){
      fore(j, 0, n/2 - aux.s) cout << 0 << ' ';
      fore(j, 0, aux.s) cout << 1 << ' ';
      cout << ENDL;
      return;
    }
  }
}
int main(){ _
  lli t; cin >> t;
  while(t--){
    cin >> n;
    v.clear();
    lli zero = 0, one = 0;
    fore(i, 0, n){
      lli x; cin >> x;
      v.pb(x);
      if(x) one++;
      else {
        zero++;
      }
    }
    if(one == n){
      cout << n << ENDL;
      fore(i, 0, n) cout << 1 << ' '; cout << ENDL;
      continue;
    }
    cout << n / 2 << ENDL;
    if(zero >= one){
      fore(i, 0, n/2) cout << 0 << ' '; cout << ENDL;
    }else{
      if((n/2)&1){
        solve();
      }else{
        fore(i, 0, n/2) cout << 1 << ' '; cout << ENDL;
      }
    }
  }
  return 0;
}
