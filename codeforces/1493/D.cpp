/*
 © 2021-03-06 08:05:01 Franco1010 All Rights Reserved
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
const lli N = 2e5 + 5;
const lli MOD = 1e9 + 7 ;
vector<lli> primes;
vector<multiset<lli>> mem;

lli gcd(lli a, lli b){return a?gcd(b%a,a):b;}
lli mulmod(lli a, lli b, lli m) {
	lli r=a*b-(lli)((long double)a*b/m+.5)*m;
	return r<0?r+m:r;
}
lli expmod(lli b, lli e, lli m){
	if(!e)return 1;
	lli q=expmod(b,e/2,m);q=mulmod(q,q,m);
	return e&1?mulmod(b,q,m):q;
}
bool is_prime_prob(lli n, int a){
	if(n==a)return true;
	lli s=0,d=n-1;
	while(d%2==0)s++,d/=2;
	lli x=expmod(a,d,n);
	if((x==1)||(x+1==n))return true;
	fore(rep,0,s-1){
		x=mulmod(x,x,n);
		if(x==1)return false;
		if(x+1==n)return true;
	}
	return false;
}
bool rabin(lli n){ // true iff n is prime
	if(n==1)return false;
	int ar[]={2,3,5,7,11,13,17,19,23};
	fore(i,0,9)if(!is_prime_prob(n,ar[i]))return false;
	return true;
}
const int MAXP=2e5+1; // sieve size
int sv[MAXP]; // sieve
int posInPrimes[MAXP];
lli add(lli a, lli b, lli m){return (a+=b)<m?a:a-m;}
lli rho(lli n){
	static lli s[MAXP];
	while(1){
		lli x=rand()%n,y=x,c=rand()%n;
		lli *px=s,*py=s,v=0,p=1;
		while(1){
			*py++=y=add(mulmod(y,y,n),c,n);
			*py++=y=add(mulmod(y,y,n),c,n);
			if((x=*px++)==y)break;
			lli t=p;
			p=mulmod(p,abs(y-x),n);
			if(!p)return gcd(t,n);
			if(++v==26){
				if((p=gcd(p,n))>1&&p<n)return p;
				v=0;
			}
		}
		if(v&&(p=gcd(p,n))>1&&p<n)return p;
	}
}
void init_sv(){
	fore(i,2,MAXP)if(!sv[i])for(lli j=i;j<MAXP;j+=i)sv[j]=i;
  int auxcnt = 0;
  fore(i, 0, MAXP) if(sv[i] == i){
    primes.pb(i);
    posInPrimes[i] = auxcnt++;
  }
}
void fact(lli n, map<lli,lli>& f){
	for(auto&& p:f){
		while(n%p.f==0){
			p.s++;
			n/=p.f;
		}
	}
	if(n<MAXP)while(n>1)f[sv[n]]++,n/=sv[n];
	else if(rabin(n))f[n]++;
	else {lli q=rho(n);fact(q,f);fact(n/q,f);}
}
struct Segtree{
  #define mid (l + r) / 2
  #define left(u) (u + 1)
  #define right(u) (u + ((mid - l + 1) << 1))
  struct Node{
    lli s;
    Node(lli s = 1): s(s) {}
    Node operator + (const Node &n){
      return Node(s * n.s % MOD);
    }
  };
  vector<Node> st;
  Segtree(int n): st(2 * n) {}
  void update(int u, int l, int r, int kth, lli val){ // O(logN)
    if(l == r){
      st[u].s = (val + MOD) % MOD;
      return;
    }
    if(kth <= mid) update(left(u), l, mid, kth, val);
    else update(right(u), mid + 1, r, kth, val);
    st[u] = st[left(u)] + st[right(u)];
  }
};
int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  init_sv();
  lli TAM = sz(primes) + 5;
  mem.resize(TAM);
  lli n, q; cin >> n >> q;
  vector<map<lli,lli>> v(n);
  fore(i, 0, n){
    lli x; cin >> x;
    fact(x, v[i]);
    for(auto j : v[i]) mem[posInPrimes[j.f]].insert(j.s);
  }
  Segtree st(TAM);
  for(auto i : primes){
    if(sz(mem[posInPrimes[i]]) == n)
    st.update(0, 0, TAM - 1, posInPrimes[i], expmod(i, *mem[posInPrimes[i]].begin(), MOD));
  }
  fore(qq, 0, q){
    lli pos, x; cin >> pos >> x; pos--;
    map<lli,lli> f;
    fact(x, f);
    for(auto i : f){
      if(v[pos].count(i.f)){
        auto foo = mem[posInPrimes[i.f]].find(v[pos][i.f]);
        mem[posInPrimes[i.f]].erase(foo);
        v[pos][i.f] += i.s;
        mem[posInPrimes[i.f]].insert(v[pos][i.f]);
      }else{
        v[pos][i.f] = i.s;
        mem[posInPrimes[i.f]].insert(v[pos][i.f]);
      }
      if(sz(mem[posInPrimes[i.f]]) == n)
      st.update(0, 0, TAM - 1, posInPrimes[i.f], expmod(i.f, *mem[posInPrimes[i.f]].begin(), MOD));
    }
    cout << st.st[0].s << ENDL;
  }
  return 0;
}
