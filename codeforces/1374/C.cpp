/*
 © 2020-06-28 09:35:02 Franco1010 All Rights Reserved
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
  lli t; cin >> t;
  while(t--){
    lli n; cin >> n;
    string s; cin >> s;
    stack<char> st;
    string res = "";
    for(auto i : s){
      if(res.empty()) res.pb(i);
      else if(res.back() == '(' and i == ')') res.pop_back();
      else res.pb(i);
    }
    lli l = 0, r = 0;
    for(auto i : res) if(i == '(') l++; else r++;
    cout << min(l, r) << ENDL;
  }
  return 0;
}
