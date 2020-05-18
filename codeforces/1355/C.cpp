/*
 © 2020-05-16 22:45:14 Franco1010 All Rights Reserved
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
const int N = 2 * 5e5 + 5;
lli acu[N];
int main(){ _
  lli a, b, c, d; cin >> a >> b >> c >> d;
  fore(i, a, b + 1){
    acu[i + b]++;
    acu[i + c + 1]--;
  }
  fore(i, 1, N) acu[i] += acu[i - 1];
  for(int i = N - 2; i >= 0; i--) acu[i] += acu[i + 1];
  lli res = 0;
  fore(i, c, d + 1){
    res += acu[i + 1];
  }
  cout << res << ENDL;
  return 0;
}
// 1 2 3 4 5 6 7
// 0 0 1 2 1 0 0
