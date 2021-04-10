/*
 © 2021-04-10 15:30:02 Franco1010 All Rights Reserved
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
const lli N = 405;
string mat[N];
int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  lli t; cin >> t;
  while(t--){
    lli n; cin >> n;
    vector<ii> v;
    fore(i, 0, n){
      cin >> mat[i];
      fore(j, 0, n) if(mat[i][j] == '*') v.pb({i, j});
    }
    if(v[0].f == v[1].f){
      fore(i, 0, n) if(i != v[0].f){
        mat[i][v[0].s] = mat[i][v[1].s] = '*';
        break;
      }
    }else if(v[0].s == v[1].s){
      fore(i, 0, n) if(i != v[0].s){
        mat[v[0].f][i] = mat[v[1].f][i] = '*';
        break;
      }
    }else{
      mat[v[0].f][v[1].s] = mat[v[1].f][v[0].s] = '*';
    }
    fore(i, 0, n) cout << mat[i] << ENDL;
  }
  return 0;
}
