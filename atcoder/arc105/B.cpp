/*
 © 2020-10-11 08:18:43 Franco1010 All Rights Reserved
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

int main(){ _
  lli n; cin >> n;
  set<lli> st;
  fore(i,0, n){
    lli x; cin >> x;
    st.insert(x);
  }
  lli res = 0;
  while(sz(st) > 1){
    auto foo = begin(st);
    auto bar = end(st);
    bar--;
    if(*foo == *bar) break;
    res++;
    st.insert(*bar - *foo);
    st.erase(bar);
  }
  cout << *begin(st) << ENDL;
  return 0;
}
