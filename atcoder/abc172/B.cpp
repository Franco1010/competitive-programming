/*
 © 2020-06-27 07:00:49 Franco1010 All Rights Reserved
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

int main(){ _
  string s, t; cin >> s >> t;
  lli res = 0;
  fore(i, 0, sz(s)){
    if(s[i] != t[i]) res++;
  }
  cout << res << ENDL;
  return 0;
}
