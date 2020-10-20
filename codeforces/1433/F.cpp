/*
 © 2020-10-20 16:50:02 Franco1010 All Rights Reserved
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
const lli N = 5e3 + 5;
lli s[N];
int main(){ _
  lli n, m, o; cin >> n >> m >> o;
  vi st(o, 0);
  lli res = 0;
  fore(i, 0, n){
    fore(j, 1, N) s[j] = m;
    fore(j, 0, m){
      lli x; cin >> x;
      for(lli k = N - 1; k >= x; k--){
        s[k] = min(s[k], s[k - x] + 1);
      }
    }
    vi aux = st;
    fore(j, 0, o){
      fore(k, 0, N) if(s[k] <= m / 2ll){
        aux[(st[j] + k) % o] = max(aux[(st[j] + k) % o], st[j] + k);
      }
    }
    st = aux;
  }
  cout << st[0] << ENDL;
  return 0;
}
