/*
 © 2020-07-11 06:54:04 Franco1010 All Rights Reserved
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
const int N = 1e4 + 5;
lli res[N];
int main(){ _
  lli n; cin >> n;
  for(lli i = 1; i < N; i++){
    for(lli j = 1; j < N; j++){
      for(lli k = 1; k < N; k++){
        if(i * i + j * j + k * k + i * j + j * k + k * i < N){
          res[i * i + j * j + k * k + i * j + j * k + k * i]++;
        }else break;
      }
    }
  }
  fore(i, 1, n + 1) {
    cout << res[i] << ENDL;
  }
  return 0;
}
