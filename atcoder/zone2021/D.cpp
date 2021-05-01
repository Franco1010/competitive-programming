/*
 © 2021-05-01 07:01:01 Franco1010 All Rights Reserved
*/

// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("avx,avx2,fma")
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

int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  string s; cin >> s;
  deque<char> dq;
  bool r = true;
  for(auto i : s){
    if(i == 'R') r = !r;
    else{
      if(r){
        if(!dq.empty() and dq.back() == i) dq.pop_back();
        else dq.push_back(i);
      }else{
        if(!dq.empty() and dq.front() == i) dq.pop_front();
        else dq.push_front(i);
      }
    }
  }
  if(!r) reverse(all(dq));
  for(auto i : dq) cout << i; cout << ENDL;
  return 0;
}
