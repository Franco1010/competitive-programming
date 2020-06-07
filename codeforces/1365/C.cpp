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
  lli n; cin >> n;
  vector<lli> a(n), b(n);
  map<lli,lli> pos;
  fore(i, 0, n) {
    cin >> a[i];
    pos[a[i]] = i;
  }
  map<lli,lli> mpl, mpr;
  fore(i, 0, n){
    cin >> b[i];
    mpl[((i - pos[b[i]] + n) % n)]++;
    mpr[((pos[b[i]] - i + n) % n)]++;
    // cout << ((i - pos[b[i]] + n) % n) << ' ' << ((pos[b[i]] - i + n) % n) << ENDL;
  }
  lli mx = 0;
  for(auto i : mpl) mx = max(mx, i.s);
  for(auto i : mpr) mx = max(mx, i.s);
  cout << mx << ENDL;
  return 0;
}
