/*
 © 2021-06-06 09:35:01 Franco1010 All Rights Reserved
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
const lli N = 1e6 + 5;
struct Node{
  map<char, lli> mp;
};
Node st[N];
lli curnode;
void insert(string& s){
  lli pos = 0;
  for(auto i : s){
    if(st[pos].mp.count(i)){
      pos = st[pos].mp[i];
    }else{
      st[pos].mp[i] = curnode;
      st[curnode].mp.clear();
      pos = curnode++;
    }
  }
}
lli dp[N];
lli vis[N];
lli curvis;
const lli INF = 1e7;
lli solve(lli pos = 0){
  for(char x = 'a'; x <= 'z'; x++){
    if(!st[pos].mp.count(x)) return 1;
  }
  auto &ans = dp[pos];
  auto& mem = vis[pos];
  if(mem != curvis){
    mem = curvis;
    ans = INF;
    for(char x = 'a'; x <= 'z'; x++){
      ans = min(ans, solve(st[pos].mp[x]) + 1);
    }
  }
  return ans;
}
void rec(string& s, lli pos = 0){
  for(char x = 'a'; x <= 'z'; x++){
    if(!st[pos].mp.count(x)){
      s.pb(x);
      cout << s << ENDL;
      return;
    }
  }
  for(char x = 'a'; x <= 'z'; x++){
    if(solve(st[pos].mp[x]) + 1 == solve(pos)){
      s.pb(x);
      rec(s, st[pos].mp[x]);
      return;
    }
  }
}
int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  lli t; cin >> t;
  while(t--){
    curnode = 0;
    st[curnode].mp.clear();
    curnode++;
    lli n; cin >> n;
    string s; cin >> s;
    fore(i, 0, n){
      string foo = "";
      fore(j, i, n){
        foo.pb(s[j]);
        insert(foo);
      }
    }
    curvis++;
    lli foo = solve();
    string ans = "";
    rec(ans);
  }
  return 0;
}
