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
bool win(lli n){
  if(n > 1 and n&1) return true;
  for(lli i = 2; i * i <= n; i++){
    if(n % i == 0){
      if(i&1 and not win(n / i)) return true;
      if((n/i)&1 and not win(n / (n/i))) return true;
    }
  }
  if(n > 1 and not win(n - 1)) return true;
  return false;
}
int main(){ _
  lli t; cin >> t;
  while(t--){
    lli n; cin >> n;
    if(win(n)) cout << "Ashishgup" << ENDL;
    else cout << "FastestFinger" << ENDL;
  }
  return 0;
}
