/*
 © 2020-06-07 09:35:03 Franco1010 All Rights Reserved
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
    lli n, m;
    cin >> n >> m;
    lli r = 0;
    vector<int> c(m, 1);
    fore(i, 0, n){
      lli cur = 1;
      fore(j, 0, m){
        lli x; cin >> x;
        if(x) {
          cur = 0;
          c[j] = 0;
        }
      }
      r += cur;
    }
    lli cc = 0;
    for(auto i : c) cc += i;
    lli aux = min(r, cc);
    if(aux % 2) cout << "Ashish" << ENDL;
    else cout << "Vivek" << ENDL;
  }
  return 0;
}
