/*
 © 2020-06-04 09:35:19 Franco1010 All Rights Reserved
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
const int N = 1025;
int main(){ _
  lli t; cin >> t;
  while(t--){
    lli n; cin >> n;
    set<int> ori;
    fore(i, 0, n){
      lli x; cin >> x;
      ori.insert(x);
    }
    bool yes = false;
    fore(i, 1, N + 1){
      set<int> aux;
      for(auto j : ori){
        aux.insert(i xor j);
      }
      if(aux == ori){
        yes = true;
        cout << i << ENDL;
        break;
      }
    }
    if(not yes) cout << -1 << ENDL;
  }
  return 0;
}
