/*
 © $%Y%$-$%M%$-$%D%$ $%h%$:$%m%$:$%s%$ $%U%$ All Rights Reserved
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

int main(){ _
  lli t; cin >> t;
  while(t--){
    lli a, b; cin >> a >> b;
    if(b < a) swap(a, b);
    lli res = 0;
    for(lli p = 8; p > 1; p /= 2) while(b % p == 0 and b / p >= a) b/=p, res++;
    if(b == a) cout << res << ENDL;
    else cout << -1 << ENDL;
  }
  return 0;
}
