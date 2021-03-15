/*
 © 2021-03-14 18:32:32 Franco1010 All Rights Reserved
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
#define mod(a,m) (((a)%m+m)%m)
pair<lli,lli> extendedEuclid (lli a, lli b){
	lli x,y;
	if (b==0) return {1,0};
	auto p=extendedEuclid(b,a%b);
	x=p.s;
	y=p.f-(a/b)*x;
	if(a*x+b*y==-gcd(a,b)) x=-x, y=-y;
	return {x,y};
}
pair<pair<lli,lli>,pair<lli,lli> > diophantine(lli a,lli b, lli r) {
	lli d=gcd(a,b);
	a/=d; b/=d; r/=d;
	auto p = extendedEuclid(a,b);
	p.f*=r; p.s*=r;
	assert(a*p.f+b*p.s==r);
	return {p,{-b,a}};
}
lli inv(lli a, lli m) {
	assert(gcd(a,m)==1);
	lli x = diophantine(a,m,1).f.f;
	return mod(x, m);
}
pair<lli,lli> sol(tuple<lli,lli,lli> c){
    lli a=get<0>(c), x1=get<1>(c), m=get<2>(c), d=gcd(a,m);
    if(d==1) return {mod(x1*inv(a,m),m), m};
    else return x1%d ? ii({-1LL,-1LL}) : sol(make_tuple(a/d,x1/d,m/d));
}
pair<lli,lli> crt(vector< tuple<lli,lli,lli> > cond) {
	lli x1=0,m1=1,x2,m2;
	for(auto t:cond){
		tie(x2,m2)=sol(t);
		if((x1-x2)%gcd(m1,m2))return {-1,-1};
		if(m1==m2)continue;
		lli k=diophantine(m2,-m1,x1-x2).f.s,l=m1*(m2/gcd(m1,m2));
		x1=mod((__int128)m1*k+x1,l);m1=l;
	}
	return sol(make_tuple(1,x1,m1));
}
lli f(vector<ii>& foo, lli k, lli x){
  lli res = 0;
  for(auto i : foo){
    res += (x / i.s) + (x % i.s >= i.f);
  }
  return x + 1 - res >= k;
}
lli bs(vector<ii>& foo, lli k){
  lli pos = 1;
  while(!f(foo, k, pos)) pos *= 2ll;
  for(lli p = pos; p; p /= 2ll) while(pos - p >= 0 and f(foo, k, pos - p)) pos -= p;
  return pos;
}
const lli N = 1e6 + 5;
int ex[N];
int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  fore(i, 0, N) ex[i] = -1;
  lli n, m, k; cin >> n >> m >> k;
  fore(i, 0, n){ lli x; cin >> x; ex[x] = i; }
  vector<ii> foo;
  fore(i, 0, m){
    lli x; cin >> x;
    if(ex[x] != -1){
      auto bar = crt({{1, ex[x], n}, {1, i, m}});
      if(bar != ii(-1, -1)) foo.pb(bar);
    }
  }
  cout << bs(foo, k) + 1 << ENDL;
  return 0;
}
