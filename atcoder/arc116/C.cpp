/*
 © 2021-03-28 06:53:10 Franco1010 All Rights Reserved
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
using uint=unsigned;
using ull=unsigned long long;
struct modinfo{uint mod,root;};
template<modinfo const&ref>
struct modular{
	static constexpr uint const &mod=ref.mod;
	static modular root(){return modular(ref.root);}
	uint v;
	//modular(initializer_list<uint>ls):v(*ls.bg){}
	modular(lli vv=0){s(vv%mod+mod);}
	modular& s(uint vv){
		v=vv<mod?vv:vv-mod;
		return *this;
	}
	modular operator-()const{return modular()-*this;}
	modular& operator+=(const modular&rhs){return s(v+rhs.v);}
	modular&operator-=(const modular&rhs){return s(v+mod-rhs.v);}
	modular&operator*=(const modular&rhs){
		v=ull(v)*rhs.v%mod;
		return *this;
	}
	modular&operator/=(const modular&rhs){return *this*=rhs.inv();}
	modular operator+(const modular&rhs)const{return modular(*this)+=rhs;}
	modular operator-(const modular&rhs)const{return modular(*this)-=rhs;}
	modular operator*(const modular&rhs)const{return modular(*this)*=rhs;}
	modular operator/(const modular&rhs)const{return modular(*this)/=rhs;}
	modular pow(int n)const{
		modular res(1),x(*this);
		while(n){
			if(n&1)res*=x;
			x*=x;
			n>>=1;
		}
		return res;
	}
	modular inv()const{return pow(mod-2);}

	friend modular operator+(int x,const modular&y){
		return modular(x)+y;
	}
	friend modular operator-(int x,const modular&y){
		return modular(x)-y;
	}
	friend modular operator*(int x,const modular&y){
		return modular(x)*y;
	}
	friend modular operator/(int x,const modular&y){
		return modular(x)/y;
	}
	friend ostream& operator<<(ostream&os,const modular&m){
		return os<<m.v;
	}
	friend istream& operator>>(istream&is,modular&m){
		lli x;is>>x;
		m=modular(x);
		return is;
	}
	bool operator<(const modular&r)const{return v<r.v;}
	bool operator==(const modular&r)const{return v==r.v;}
	bool operator!=(const modular&r)const{return v!=r.v;}
	explicit operator bool()const{
		return v;
	}
};

extern constexpr modinfo base{998244353,3};
// extern constexpr modinfo base{1000000007,0};
//modinfo base{1,0};
using mint=modular<base>;

//COMBI

const int vmax=(1<<21)+10;
mint fact[vmax],finv[vmax],invs[vmax];
void initfact(){
	fact[0]=1;
	fore(i,1,vmax)fact[i]=fact[i-1]*i;
	finv[vmax-1]=fact[vmax-1].inv();
	for(int i=vmax-2;i>=0;i--)finv[i]=finv[i+1]*(i+1);
	for(int i=vmax-1;i>=1;i--)invs[i]=finv[i]*fact[i-1];
}
mint choose(int n,int k){
	return fact[n]*finv[n-k]*finv[k];
}
mint binom(int a,int b){
	return fact[a+b]*finv[a]*finv[b];
}
mint catalan(int n){
	return binom(n,n)-(n-1>=0?binom(n-1,n+1):0);
}
const lli N = 2e5 + 5;
lli p[N];
vi primes;
lli n, m;
set<vi> st;
void dfs(vi& v, lli cur){
  if(sz(v) == n){
    st.insert(v);
    return;
  }
  lli foo = cur;
  while(foo <= m){
    v.pb(foo);
    dfs(v, foo);
    v.pop_back();
    foo += cur;
  }
}
mint f(lli x){
  mint res = 1;
  while(x > 1){
    lli foo = p[x];
    lli cnt = 0;
    while(p[x] == foo){
      x /= p[x];
      cnt++;
    }
    res *= choose(n - 1 + cnt, cnt);
  }
  return res;
}
int main(){ _
  p[0] = p[1] = 1;
  for(lli i = 2; i < N; i++) if(!p[i]) for(lli j = i; j < N; j += i) p[j] = i;
  // fore(i, 0, N) if(!p[i]) primes.pb(i);
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  initfact();
  cin >> n >> m;
  mint ans = 0;
  fore(i, 2, m + 1){
    ans += f(i);
  }
  cout << ans + mint(1) << ENDL;
  return 0;
}

