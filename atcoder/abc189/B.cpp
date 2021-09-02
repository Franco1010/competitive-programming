#include <iostream>
#define fore(i, a, b) for(long i = (a), asdf = (b); i < asdf; i++)
#define ENDL '\n'
using namespace std;
typedef long long lli;

int main() {
	lli n; cin >> n;
	lli x; cin >> x; x*= 100ll;
	lli cur = 0;
	fore(i, 0, n){
	  lli a, b; cin >> a >> b;
	  cur += a * b;
	  if(cur > x){
	    cout << i + 1 << ENDL;
	    return 0;
	  }
	}
	cout << -1 << ENDL;
	return 0;
}
