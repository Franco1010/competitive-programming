/*
 © 2020-06-27 07:00:49 Franco1010 All Rights Reserved
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
const int N = 1e7 + 5;
lli d[N];
int main(){ _
  fore(i, 0, N){
    fore(j, 0, N){
      if(i * j >= N) break;
      d[i * j]++;
    }
  }
  lli res = 0;
  lli n; cin >> n;
  fore(i, 1, n + 1) res += lli(i) * d[i];
  cout << res << ENDL;
  return 0;
}
