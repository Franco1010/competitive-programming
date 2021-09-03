#include <bits/stdc++.h>
#define fore(i, a, b) for(long i = (a), asdf = (b); i < asdf; i++)
#define ENDL '\n'
using namespace std;
typedef long long lli;
const lli N = 2e3 + 5;
const lli MOD = 998244353ll;

int main() {
  lli h, w; cin >> h >> w;
  vector<char> v(h + w - 1, '.');
  fore(i, 0, h){
    fore(j, 0, w){
      char x; cin >> x;
      if(x != '.'){
       if(v[i + j] == '.') v[i + j] = x;
       else if(v[i + j] != x){
         cout << 0 << ENDL;
         return 0;
       }
      }
    }
  }
  lli res = 1;
  for(auto i : v){
    if(i == '.') res = res * 2ll % MOD;
  }
  cout << res << ENDL;
	return 0;
}
