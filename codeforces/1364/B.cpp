/*
 © 2020-06-13 10:05:01 Franco1010 All Rights Reserved
*/

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
typedef pair<int,int> ii;
#define deb(x) cout << #x": " << (x) << endl;
lli n;
int main(){ _
  lli t; cin >> t;
  while(t--){
    cin >> n;
    vector<lli> v, ans;
    lli prev = 0;
    lli up = -1;
    fore(i, 0, n){
      lli x; cin >> x;
      v.pb(x);
    }
    ans.pb(0);
    int r = 1;
    while(r < n){
      while(v[r] > v[r - 1] and r + 1 < n and v[r + 1] > v[r]) r++;
      ans.pb(r);
      r++;
    }
    vector<lli> aux;
    // for(auto i : ans) cout << i << ' '; cout << ENDL;
    for(auto i : ans) aux.pb(v[i]);
    v = aux;
    ans.clear();
    ans.pb(0);
    r = 1;
    while(r < sz(v)){
      while(v[r] < v[r - 1] and r + 1 < sz(v) and v[r + 1] < v[r]) r++;
      ans.pb(r);
      r++;
    }
    cout << sz(ans) << ENDL;
    for(auto i : ans) cout << v[i] << ' '; cout << ENDL;
  }
  return 0;
}
