/*
 © 2020-09-08 09:35:03 Franco1010 All Rights Reserved
*/

#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("avx,avx2,fma")
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
lli q(lli x, lli y){
  x++,y++;
  cout << "? " << x << ' ' << y << endl;
  cin >> x;
  return x;
}
int main(){ _
  lli n; cin >> n;
  vector<lli> res(n, -1);
  lli cur = 0;
  bool yes = true;
  while(yes){
    yes = false;
    fore(i, 0, n){
      if(res[i] == -1 and i != cur){
        lli foo = q(cur, i);
        lli bar = q(i, cur);
        if(foo > bar){
          res[cur] = foo;
          cur = i;
          yes = true;
          break;
        }else{
          res[i] = bar;
        }
      }
    }
  }
  cout << "! ";
  for(auto i : res) cout << (i == -1? n : i) << ' '; cout << endl;
  return 0;
}
