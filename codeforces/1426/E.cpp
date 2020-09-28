/*
 © 2020-09-28 16:00:39 Franco1010 all Rights Reserved
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
const lli INF = 1E18;
struct Dinic{
	int nodes,src,dst;
	vector<int> dist,q,work;
	struct edge {int to,rev;lli f,cap;};
	vector<vector<edge>> g;
	Dinic(int x):nodes(x),g(x),dist(x),q(x),work(x){}
	void add_edge(int s, int t, lli cap){
		g[s].pb((edge){t,sz(g[t]),0,cap});
		g[t].pb((edge){s,sz(g[s])-1,0,0});
	}
	bool dinic_bfs(){
		fill(all(dist),-1);dist[src]=0;
		int qt=0;q[qt++]=src;
		for(int qh=0;qh<qt;qh++){
			int u=q[qh];
			fore(i,0,sz(g[u])){
				edge &e=g[u][i];int v=g[u][i].to;
				if(dist[v]<0&&e.f<e.cap)dist[v]=dist[u]+1,q[qt++]=v;
			}
		}
		return dist[dst]>=0;
	}
	lli dinic_dfs(int u, lli f){
		if(u==dst)return f;
		for(int &i=work[u];i<sz(g[u]);i++){
			edge &e=g[u][i];
			if(e.cap<=e.f)continue;
			int v=e.to;
			if(dist[v]==dist[u]+1){
				lli df=dinic_dfs(v,min(f,e.cap-e.f));
				if(df>0){e.f+=df;g[v][e.rev].f-=df;return df;}
			}
		}
		return 0;
	}
	lli max_flow(int _src, int _dst){
		src=_src;dst=_dst;
		lli result=0;
		while(dinic_bfs()){
			fill(all(work),0);
			while(lli delta=dinic_dfs(src,INF))result+=delta;
		}
		return result;
	}
};
int main(){ _
  lli n; cin >> n;
  vector<lli> a(3), b(3);
  cin >> a[0] >> a[2] >> a[1];
  cin >> b[0] >> b[2] >> b[1];
  vector<ii> v = {{0, 3}, {0, 4}, {1, 4}, {1, 5}, {2, 5}, {2, 3}};
  lli mx = min(a[0], b[2]) + min(a[1], b[0]) + min(a[2], b[1]);
  Dinic d(8);
  for(auto i : v) d.add_edge(i.f, i.s, INF);
  fore(i, 0, 3) d.add_edge(6, i, a[i]);
  fore(i, 3, 6) d.add_edge(i, 7, b[i - 3]);
  cout << n - d.max_flow(6, 7) << ' ' << mx << ENDL;
  return 0;
}
