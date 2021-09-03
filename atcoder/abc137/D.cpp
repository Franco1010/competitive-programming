#include <bits/stdc++.h>
#define fore(i, a, b) for(long i = (a), asdf = (b); i < asdf; i++)
#define ENDL '\n'
using namespace std;
typedef long long lli;
const lli N = 2e3 + 5;
const lli MOD = 998244353ll;

int main() {
  lli n, m; cin >> n >> m;
  map<lli, vector<lli>> mp;
  fore(i, 0, n){
    lli a, b; cin >> a >> b;
    mp[a].push_back(b);
  }
  priority_queue<lli> pq;
  lli ans = 0;
  fore(i, 1, m + 1){
    for(auto j : mp[i]) pq.push(j);
    if(!pq.empty()){
      ans += pq.top(); pq.pop();
    }
  }
  cout << ans << ENDL;
	return 0;
}
