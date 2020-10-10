/*
 © 2020-10-10 07:14:00 Franco1010 All Rights Reserved
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
void recal(lli &res, unordered_set<lli> &st){
  while(st.count(res))res++;
}
int main(){ _
  lli n; cin >> n;
  vi v(n);
  fore(i, 0, n){
    cin >> v[i];
  }
  unordered_set<lli> st;
  lli res = 0;
  for(auto i : v){
    st.insert(i);
    recal(res, st);
    cout << res << ENDL;
  }
  return 0;
}
