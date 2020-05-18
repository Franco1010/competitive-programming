/*
 © 2020-05-18 12:44:09 Franco1010 All Rights Reserved
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
bool isP(lli x){
  if(x == 1) return false;
  fore(i, 2, sqrtl(x) + 1){
    if(x % i == 0) return false;
  }
  return true;
}
int main(){ _
  lli t; cin >> t;
  while(t--){
    lli n; cin >> n;
    lli x = sqrtl(n);
    if(isP(x) and x * x == n) cout << "YES" << ENDL;
    else cout << "NO" << ENDL;
  }
  return 0;
}
