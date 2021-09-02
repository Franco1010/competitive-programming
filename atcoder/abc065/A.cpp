#include <iostream>
#define fore(i, a, b) for(long i = (a), asdf = (b); i < asdf; i++)
#define ENDL '\n'
using namespace std;
typedef long long lli;

int main() {
	lli x, a, b; cin >> x >> a >> b;
	lli foo = b - a;
	if(foo <= 0) cout << "delicious" << ENDL;
	else if(foo > x) cout << "dangerous" << ENDL;
	else cout << "safe" << ENDL;
	return 0;
}
