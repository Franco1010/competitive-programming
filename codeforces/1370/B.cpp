/*
 © 2020-06-20 09:35:01 Franco1010 All Rights Reserved
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

int main(){ _
  lli t; cin >> t;
  while(t--){
    lli n; cin >> n;
    vector<lli> p, i;
    fore(j, 0, 2 * n){
      lli x; cin >> x;
      if(x % 2) i.pb(j + 1);
      else p.pb(j + 1);
    }
    fore(j, 0, n - 1){
      if(sz(p) > 2){
        cout << p.back() << ' ' ;
        p.pop_back();
        cout << p.back() << ENDL;
        p.pop_back();
      }else {
        cout << i.back() <<  ' ';
        i.pop_back();
        cout << i.back() << ENDL;
        i.pop_back();
      }
    }
  }
  return 0;
}
