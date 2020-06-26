/*
 © 2020-06-25 21:33:37 Franco1010 All Rights Reserved
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
typedef vector<int> vi;
#define deb(x) cout << #x": " << (x) << endl;
bool f(vector<lli> &v, lli x, lli k){
  fore(p, 0, 2){
    lli cnt = 0;
    for(auto i : v) if((cnt&1) == p or i <= x) cnt++;
    if(cnt >= k) return true;
  }
  return false;
}
int main(){ _
  lli n, k; cin >> n >> k;
  vector<lli> v(n);
  fore(i, 0, n) cin >> v[i];
  lli pos = 1e9;
  for(lli p = 1e9; p > 0; p /= 2) while(pos - p >= 1 and f(v, pos - p, k)) pos -= p;
  cout << pos << ENDL;
  return 0;
}
