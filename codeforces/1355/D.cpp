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
  lli n, s; cin >> n >> s;
  lli x = s - (n - 1);
  if(n < x){
    cout << "YES" << ENDL;
    fore(i, 1, n) cout << 1 << ' '; cout << x << ENDL;
    cout << n << ENDL;
  }else cout << "NO" << ENDL;
  return 0;
}
