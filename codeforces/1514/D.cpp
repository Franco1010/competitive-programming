/*
 © 2021-04-19 08:35:02 Franco1010 All Rights Reserved
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
const lli MAXN = 3e5 + 5;
int n,sq,nq;
struct qu{int l,r,id;};
qu qs[MAXN];
lli ans[MAXN]; 
lli v[MAXN], cnt[MAXN], cur[MAXN];
lli mx;
bool qcomp(const qu &a, const qu &b){
    if(a.l/sq!=b.l/sq) return a.l<b.l;
    return (a.l/sq)&1?a.r<b.r:a.r>b.r;
}
void add(lli x){
  cur[cnt[v[x]]]--;
  cnt[v[x]]++;
  if(!cur[cnt[v[x]]]) mx = max(mx, cnt[v[x]]);
  cur[cnt[v[x]]]++;
}
void remove(lli x){
  if(cur[cnt[v[x]]] == 1 and mx == cnt[v[x]]) mx--;
  cur[cnt[v[x]]--]--;
  cur[cnt[v[x]]]++;
}
lli get_ans(lli l, lli r){
  lli ans = 1;
  lli foo = r - l;
  if(mx > foo - mx + 1){
    ans += mx - (foo - mx + 1);
  }
  return ans;
}
void mos(){
    fore(i,0,nq)qs[i].id=i;
    sq=sqrt(n)+.5;
    sort(qs,qs+nq,qcomp);
    int l=0,r=0;
    fore(i,0,nq){
        qu q=qs[i];
        while(l>q.l)add(--l);
        while(r<q.r)add(r++);
        while(l<q.l)remove(l++);
        while(r>q.r)remove(--r);
        ans[q.id]=get_ans(l, r);
    }
}
int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  cin >> n >> nq;
  fore(i, 0, n) cin >> v[i];
  fore(i, 0, nq){
    auto& foo = qs[i];
    cin >> foo.l >> foo.r; foo.l--;
    foo.id = i;
  }
  mos();
  fore(i, 0, nq) cout << ans[i] << ENDL;
  return 0;
}
