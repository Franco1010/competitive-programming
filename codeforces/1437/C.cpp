/*
 © 2020-10-27 08:35:02 Franco1010 All Rights Reserved
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
typedef lli tf;
typedef lli tc;
const tf INFFLOW=1e9;
const tc INFCOST=1e9;
struct MCF{
	int n;
	vector<tc> prio, pot; vector<tf> curflow; vector<int> prevedge,prevnode;
	priority_queue<pair<tc, int>, vector<pair<tc, int>>, greater<pair<tc, int>>> q;
	struct edge{int to, rev; tf f, cap; tc cost;};
	vector<vector<edge>> g;
	MCF(int n):n(n),prio(n),curflow(n),prevedge(n),prevnode(n),pot(n),g(n){}
	void add_edge(int s, int t, tf cap, tc cost) {
		g[s].pb((edge){t,sz(g[t]),0,cap,cost});
		g[t].pb((edge){s,sz(g[s])-1,0,0,-cost});
	}
	pair<tf,tc> get_flow(int s, int t) {
		tf flow=0; tc flowcost=0;
		while(1){
			q.push({0, s});
			fill(all(prio),INFCOST);
			prio[s]=0; curflow[s]=INFFLOW;
			while(!q.empty()) {
				auto cur=q.top();
				tc d=cur.f;
				int u=cur.s;
				q.pop();
				if(d!=prio[u]) continue;
				for(int i=0; i<sz(g[u]); ++i) {
					edge &e=g[u][i];
					int v=e.to;
					if(e.cap<=e.f) continue;
					tc nprio=prio[u]+e.cost+pot[u]-pot[v];
					if(prio[v]>nprio) {
						prio[v]=nprio;
						q.push({nprio, v});
						prevnode[v]=u; prevedge[v]=i;
						curflow[v]=min(curflow[u], e.cap-e.f);
					}
				}
			}
			if(prio[t]==INFCOST) break;
			fore(i,0,n) pot[i]+=prio[i];
			tf df=min(curflow[t], INFFLOW-flow);
			flow+=df;
			for(int v=t; v!=s; v=prevnode[v]) {
				edge &e=g[prevnode[v]][prevedge[v]];
				e.f+=df; g[v][e.rev].f-=df;
				flowcost+=df*e.cost;
			}
		}
		return {flow,flowcost};
	}
};
int main(){ _
  lli q; cin >> q;
  while(q--){
    lli n; cin >> n;
    MCF mcf(n + 2 * n + 2);
    fore(i, 0, n){
      lli x; cin >> x;
      fore(j, 1, 2 * n + 1){
        mcf.add_edge(i + 1, j + n, 1, labs(j - x));
      }
    }
    fore(i, 1, n + 1) mcf.add_edge(0, i, 1, 0);
    fore(i, 1, 2 * n + 1) mcf.add_edge(i + n, 2 * n + 1 + n, 1, 0);
    cout << mcf.get_flow(0, 2 * n + 1 + n).s << ENDL;
  }
  return 0;
}
