#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define ENDL '\n'
#define all(a) begin(a), end(a)
#define sz(a) (int)(a.size())
#define deb(a) cout << #a << ": " << a << ENDL
#define fore(i, a, b) for(int i(a), ThkMk(b); i < ThkMk; ++i)
#define _ ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

typedef long long lli;
typedef long double ld;
typedef pair<lli, lli> ii;
typedef vector<lli> vi;

int main()
{   _
    lli t, n; cin >> t;
    while(t--) {
        cin >> n;
        lli nn = n;
        bool b = n % 2;
        n -= n % 2;
        lli ans = 0;
        while(n) {
            if(n == 4) {
                ans += 3;
                break;
            }
            if(n % 4 == 0) {
                ++ans;
                n -= 2;
                continue;
            }
            if(n % 2 == 0) {
                ans += n / 2;
                n /= 2;
                --n;
                continue;
            }
        }
        if(b) ans = (nn - ans);
        cout << ans << ENDL;
    }
    return 0;
}
