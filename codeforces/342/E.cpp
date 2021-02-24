/*
 © 2021-02-24 16:50:10 Franco1010 All Rights Reserved
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
const lli K = 18;
const lli MAXN = 1ll << K;
vector<int> g[MAXN];int n;
bool tk[MAXN];
int fat[MAXN];
int szt[MAXN];
int calcsz(int x, int f){
	szt[x]=1;
	for(auto y:g[x])if(y!=f&&!tk[y])szt[x]+=calcsz(y,x);
	return szt[x];
}
void cdfs(int x=0, int f=-1, int sz=-1){ // O(nlogn)
	if(sz<0)sz=calcsz(x,-1);
	for(auto y:g[x])if(!tk[y]&&szt[y]*2>=sz){
		szt[x]=0;cdfs(y,f,sz);return;
	}
	tk[x]=true;fat[x]=f;
	for(auto y:g[x])if(!tk[y])cdfs(y,x);
}
void centroid(){memset(tk,false,sizeof(tk));cdfs();}
int F[K][1<<K],D[1<<K];
void lca_dfs(int x){
	fore(i,0,g[x].size()){
		int y=g[x][i];if(y==F[0][x])continue;
		F[0][y]=x;D[y]=D[x]+1;lca_dfs(y);
	}
}
void lca_init(){
	D[0]=0;F[0][0]=-1;
	lca_dfs(0);
	fore(k,1,K)fore(x,0,n)
		if(F[k-1][x]<0)F[k][x]=-1;
		else F[k][x]=F[k-1][F[k-1][x]];
}
int lca(int x, int y){
	if(D[x]<D[y])swap(x,y);
	for(int k=K-1;k>=0;--k)if(D[x]-(1<<k)>=D[y])x=F[k][x];
	if(x==y)return x;
	for(int k=K-1;k>=0;--k)if(F[k][x]!=F[k][y])x=F[k][x],y=F[k][y];
	return F[0][x];
}
lli dis(int x, int y){return D[x] + D[y] - 2 * D[lca(x, y)];}
lli best[MAXN];
int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  lli m; cin >> n >> m;
  fore(i, 0, n - 1){
    lli u, v; cin >> u >> v;
    u--, v--;
    g[u].pb(v);
    g[v].pb(u);
  }
  centroid();
  lca_init();
  fore(i, 0, n) best[i] = dis(0, i);
  while(m--){
    lli t, v; cin >> t >> v;v--;
    if(t == 1){
      lli foo = v;
      while(foo != -1){
        best[foo] = min(best[foo], dis(foo, v));
        foo = fat[foo];
      }
    }else{
      lli mn = 1e18;
      lli foo = v;
      while(foo != -1){
        mn = min(mn, best[foo] + dis(v, foo));
        foo = fat[foo];
      }
      cout << mn << ENDL;
    }
  }
  return 0;
}
