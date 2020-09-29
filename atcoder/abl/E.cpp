/*
 © 2020-09-28 15:06:12 Franco1010 All Rights Reserved
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
const lli MOD = 998244353;
typedef struct item *pitem;
struct item {
	lli pr,cnt,val;
	lli sum; // (paramters for range query)
  lli spot;
  lli pot;
//	bool rev;
  lli add; // (parameters for lazy prop)
	pitem l,r,f;
	item(lli val, lli pot): pr(rand()),cnt(1),val(val),l(0),r(0), pot(pot), spot(0), add(0)/*,sum(val),rev(0),add(0)*/ {}
};
lli cnt(pitem t){return t?t->cnt:0;}
lli spot(pitem t){return t? t->spot : 0;}
void push(pitem it){
	if(it){
    if(it->add){
      it->val = it->add;
      it->sum = spot(it) * it->add % MOD;
      if(it->l) it->l->add = it->add;
      if(it->r) it->r->add = it->add;
      it->add = 0;
    }
		// if(it->rev){
		// 	swap(it->l,it->r);
		// 	if(it->l)it->l->rev^=true;
		// 	if(it->r)it->r->rev^=true;
		// 	it->rev=false;
		// }
    // if(add){
    //   int ll = it->f ? cnt(it->f->l) : 0;
    // }
		// it->val+=it->add;it->sum+=it->cnt*it->add;
		// if(it->l)it->l->add+=it->add;
		// if(it->r)it->r->add+=it->add;
		// it->add=0;
	}
}
int sum(pitem t){return t?push(t),t->sum:0;}
void upd_cnt(pitem t){
	if(t){
		t->cnt=cnt(t->l)+cnt(t->r)+1;
    t->spot = (t->pot + spot(t->l) + spot(t->r) + MOD) % MOD;
    t->sum = (t->val * t->pot) % MOD;
    t->sum = (t->sum + sum(t->l) + sum(t->r)) % MOD;
		// t->sum=t->val+sum(t->l)+sum(t->r);
	}
}
void merge(pitem& t, pitem l, pitem r){
	push(l);push(r);
	if(!l||!r)t=l?l:r;
	else if(l->pr>r->pr)merge(l->r,l->r,r),l->r->f=t=l;
	else merge(r->l,l,r->l),r->l->f=t=r;
	upd_cnt(t);
}
void split(pitem t, pitem& l, pitem& r, int sz){
	if(!t){l=r=0;return;}
	push(t);
	if(sz<=cnt(t->l)){
		split(t->l,l,t->l,sz);r=t;
		if(l)l->f=0;
		if(t->l)t->l->f=t;
	}
	else {
		split(t->r,t->r,r,sz-1-cnt(t->l));l=t;
		if(r)r->f=0;
		if(t->r)t->r->f=t;
	}
	upd_cnt(t);
}
void push_all(pitem t){
	if(t->f)push_all(t->f);
	push(t);
}
pitem root(pitem t, int& pos){ // get root and position for node t
	push_all(t);
	pos=cnt(t->l);
	while(t->f){
		pitem f=t->f;
		if(t==f->r)pos+=cnt(f->l)+1;
		t=f;
	}
	return t;
}
void output(pitem t){ // useful for debugging
	if(!t)return;
	push(t);
	output(t->l);
  cout << "(" << t->val << ',' << t->pot << ") ";
  output(t->r);
}
int main(){ _
  lli n, q; cin >> n >> q;
  vector<lli> pp = {1};
  while(sz(pp) < n) pp.pb(pp.back() * 10ll % MOD);
  reverse(all(pp));
  // for(auto i : pot) cout << i << ' '; cout << ENDL;
  pitem t = 0;
  fore(i, 0, n){
    merge(t, t, new item(1, pp[i]));
  }
  // output(t);cout << ENDL;
  while(q--){
    lli l, r, d; cin >> l >> r >> d;
    pitem ll, mm, rr;
    split(t, mm, rr, r);
    split(mm, ll, mm, l - 1);
    mm->add = d;
    merge(mm, ll, mm);
    merge(t, mm, rr);
    cout << sum(t) << ENDL;
    // cout << cnt(ll) << ' ' << cnt(mm) << ' ' << cnt(rr) << ENDL;
    // cout << spot(ll) << ' ' << spot(mm) << ' ' << spot(rr) << ENDL;
  }
  return 0;
}
