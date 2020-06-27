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
lli bs(vector<lli> &v, lli k){
  lli pos = 0;
  for(lli p = sz(v); p > 0; p /= 2) while(pos + p < sz(v) and v[pos + p] <= k) pos += p;
  return pos;
}
int main(){ _
  lli n, m, k; cin >> n >> m >> k;
  vector<lli> a(n + 1, 0), b(m + 1, 0);
  fore(i, 0, n){
    cin >> a[i + 1];
    a[i + 1] += a[i];
  }
  fore(i, 0, m){
    cin >> b[i + 1];
    b[i + 1] += b[i];
  }
  lli res = 0;
  fore(i, 0, n + 1){
    if(a[i] <= k){
      res = max(res, i + bs(b, k - a[i]));
    }
  }
  cout << res << ENDL;
  return 0;
}
