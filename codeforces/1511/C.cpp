/*
 © 2021-04-12 09:35:01 Franco1010 All Rights Reserved
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
const lli INF = 1e8;
typedef struct item *pitem;
struct item {
	int pr,cnt,val;
  array<int, 55>pos;
//	int sum; // (paramters for range query)
//	bool rev;int add; // (parameters for lazy prop)
	pitem l,r;
	item(int val): pr(rand()),cnt(1),val(val),l(0),r(0)/*,sum(val),rev(0),add(0)*/ {
    fore(i, 0, 55) pos[i] = 0;
    pos[val] = 1;
  }
};
void push(pitem it){
	if(it){
	}
}
int cnt(pitem t){return t?t->cnt:0;}
int pos(pitem t, lli p){ return t ? t->pos[p] : 0;}
// int sum(pitem t){return t?push(t),t->sum:0;}
void upd_cnt(pitem t){
	if(t){
		t->cnt=cnt(t->l)+cnt(t->r)+1;
    fore(i, 0, 55) t->pos[i] = pos(t->l, i) + pos(t->r, i);
    t->pos[t->val]++;
		// t->sum=t->val+sum(t->l)+sum(t->r);
	}
}
void merge(pitem& t, pitem l, pitem r){
	push(l);push(r);
	if(!l||!r)t=l?l:r;
	else if(l->pr>r->pr)merge(l->r,l->r,r),t=l;
	else merge(r->l,l,r->l),t=r;
	upd_cnt(t);
}
void split(pitem t, pitem& l, pitem& r, int sz){ // sz:desired size of l
	if(!t){l=r=0;return;}
	push(t);
	if(sz<=cnt(t->l))split(t->l,l,t->l,sz),r=t;
	else split(t->r,t->r,r,sz-1-cnt(t->l)),l=t;
	upd_cnt(t);
}
lli find(pitem t, lli col){
  if(!t) return 0;
  if(pos(t->l, col)) return find(t->l, col);
  if(t->val == col) return cnt(t->l) + 1;
  return cnt(t->l) + 1 + find(t->r, col);
}
int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  lli n, q; cin >> n >> q;
  pitem r = 0;
  fore(i, 0, n){
    lli x; cin >> x;
    merge(r, r, new item(x));
  }
  fore(i, 0, q){
    lli x; cin >> x;
    lli foo = find(r, x);
    cout << foo << ' ';
    pitem a, b, c;
    split(r, a, b, foo - 1);
    split(b, b, c, 1);
    merge(a, a, c);
    merge(r, b, a);
  }cout << ENDL;
  return 0;
}
