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
    lli n, k; cin >> n >> k;
    for(lli i = 1; i < k; i++){
      string s = to_string(n);
      lli a = *min_element(all(s)) - '0';
      lli b = *max_element(all(s)) - '0';
      if(a * b == 0) break;
      n += a * b;
    }
    cout << n << ENDL;
  }
  return 0;
}
