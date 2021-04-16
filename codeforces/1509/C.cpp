/*
 © 2021-04-16 09:35:01 Franco1010 All Rights Reserved
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
const lli N = 2e3 + 5;
const lli K = 11;
const lli INF = 1e18;
lli dp[N][N];
bool vis[N][N];
lli st[2][K][1<<K];lli n;
void st_init(vi& a){
	fore(i,0,n)st[0][0][i]=a[i];
  fore(i,0,n)st[1][0][i]=a[i];
	fore(k,1,K)fore(i,0,n-(1<<k)+1){
		st[0][k][i]=min(st[0][k-1][i],st[0][k-1][i+(1<<(k-1))]);
    st[1][k][i]=max(st[1][k-1][i],st[1][k-1][i+(1<<(k-1))]);
  }
}
lli stmin(int s, int e){
	int k=31-__builtin_clz(e-s);
	return min(st[0][k][s],st[0][k][e-(1<<k)]);
}
lli stmax(int s, int e){
  int k=31-__builtin_clz(e-s);
	return max(st[1][k][s],st[1][k][e-(1<<k)]);
}
vi v;
lli solve(lli l, lli r){
  auto& ans = dp[l][r];
  auto& mem = vis[l][r];
  lli foo = stmax(l, r + 1) - stmin(l, r + 1);
  if(l == 0 and r == n - 1) return foo;
  if(!mem){
    mem = true;
    ans = INF;
    if(l > 0) ans = min(ans, solve(l - 1, r) + foo);
    if(r + 1 < n) ans = min(ans, solve(l, r + 1) + foo);
  }
  return ans;
}
int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  cin >> n;
  v.resize(n); for(auto& i : v) cin >> i;
  sort(all(v));
  st_init(v);
  lli ans = INF;
  fore(i, 0, n) ans = min(ans, solve(i, i));
  cout << ans << ENDL;
  return 0;
}
