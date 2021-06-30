/*
 © 2021-06-30 00:32:17 Franco1010 All Rights Reserved
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
const lli N = 1e6 + 5;
const lli MOD = 1e9 + 7;
lli cnt[N];
lli op[N];
bool p[N];
lli pot[N];
lli f(lli x){
  return x * pot[x - 1] % MOD;
}
int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  pot[0] = op[0] = 1;
  fore(i, 1, N){
    pot[i] = (pot[i - 1] * 2ll) % MOD;
    op[i] = 1;
  }
  for(lli i = 2; i < N; i++){
    if(!p[i])
    for(lli j = i; j < N; j += i){
      p[j] = true;
      if((j / i) % i == 0) op[j] = 0;
      else op[j] *= -1;
    }
  }
  lli n; cin >> n;
  fore(i, 0, n){
    lli x; cin >> x;
    cnt[x]++;
  }
  for(lli i = 1; i < N; i++) for(lli j = i + i; j < N; j += i) cnt[i] += cnt[j];
  lli ans = 0;
  for(lli i = 2; i < N; i++){
    lli foo = 0;
    for(lli j = i; j < N; j += i){
      foo = (foo + f(cnt[j]) * op[j / i] % MOD) % MOD;
    }
    foo = foo * i % MOD;
    ans = (ans + foo) % MOD;
  }
  cout << ans << ENDL;
  return 0;
}
