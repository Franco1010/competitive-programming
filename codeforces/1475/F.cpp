/*
 © 2021-01-25 09:00:01 Franco1010 All Rights Reserved
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
typedef vector<bool> Row;
typedef vector<Row> Matrix;
lli n;
void editC(Matrix& m, lli j){
  fore(i, 0, n) m[i][j] = !m[i][j];
}
void editR(Matrix& m, lli i){
  fore(j, 0, n) m[i][j] = !m[i][j];
}
int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  lli t; cin >> t;
  while(t--){
    cin >> n;
    Matrix a(n, Row(n)), b(n, Row(n));
    fore(i, 0, n){
      string s; cin >> s;
      fore(j, 0, n) a[i][j] = s[j] == '1';
    }
    fore(i, 0, n){
      string s; cin >> s;
      fore(j, 0, n) b[i][j] = s[j] == '1';
    }
    fore(j, 0, n) if(a[0][j] != b[0][j]) editC(a, j);
    fore(i, 1, n) if(a[i][0] != b[i][0]) editR(a, i);
    if(a == b) cout << "YES" << ENDL;
    else cout << "NO" << ENDL;
  }
  return 0;
}
