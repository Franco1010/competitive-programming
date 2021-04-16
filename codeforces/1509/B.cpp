/*
 © 2021-04-16 09:35:01 Franco1010 All Rights Reserved
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

int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  lli t; cin >> t;
  while(t--){
    lli n; string s; cin >> n >> s;
    vector<ii> v;
    queue<lli> q;
    fore(i, 0, n){
      if(s[i] == 'T'){
        q.push(i);
      }else{
        if(!q.empty()){
          v.pb({q.front(), i});
          s[q.front()] = s[i] = '*';
          q.pop();
        }
      }
    }
    lli pos = 0, ans = 0;
    for(auto i : v){
      pos = max(pos, i.s);
      while(pos + 1 < n and s[pos] != 'T') pos++;
      if(pos >= n or s[pos] != 'T') break;
      ans++;
      s[pos] = '*';
      pos++;
    }
    if(ans < n / 3ll) cout << "NO" << ENDL;
    else cout << "YES" << ENDL;
  }
  return 0;
}
