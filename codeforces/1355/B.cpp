/*
 © 2020-05-16 22:45:14 Franco1010 All Rights Reserved
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
    vector<lli> v(n);
    fore(i, 0, n) cin >> v[i];
    sort(all(v));
    lli res = 0;
    lli last = -1;
    fore(i, 0, n){
      if(v[i] == i - last){
        last = i;
        res++;
      }
    }
    cout << res << ENDL;
  }
  return 0;
}
