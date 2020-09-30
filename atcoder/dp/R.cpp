/*
 © 2020-09-29 17:19:25 Franco1010 All Rights Reserved
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
const lli N = 5e1 + 5;
const lli MOD = 1e9 + 7;
typedef vector<vector<lli> > Matrix;
Matrix ones(int n) {
	Matrix r(n,vector<lli>(n));
	fore(i,0,n)r[i][i]=1;
	return r;
}
Matrix operator*(Matrix &a, Matrix &b) {
	int n=sz(a),m=sz(b[0]),z=sz(a[0]);
	Matrix r(n,vector<lli>(m));
	fore(i,0,n)fore(j,0,m)fore(k,0,z)
		r[i][j]+=a[i][k]*b[k][j],r[i][j]%=MOD;
	return r;
}
Matrix be(Matrix b, lli e) {
	Matrix r=ones(sz(b));
	while(e){if(e&1LL)r=r*b;b=b*b;e/=2;}
	return r;
}
int main(){ _
  lli n, k; cin >> n >> k;
  Matrix g(n, vi(n));
  fore(i, 0, n){
    fore(j, 0, n){
      cin >> g[i][j];
    }
  }
  g = be(g, k);
  lli res = 0;
  fore(i, 0, n){
    fore(j, 0, n) res = (res + g[i][j] + MOD) % MOD;
  }
  cout << res << ENDL;
  return 0;
}
