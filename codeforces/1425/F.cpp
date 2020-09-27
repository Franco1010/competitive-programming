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
{   ///_
    lli n; cin >> n;
    lli tot, x;
    cout << "? 1 " << n << endl;
    cin >> tot;
    lli last;
    cout << "? 1 " << n - 1 << endl;
    cin >> last;
    last = tot - last;
    vi v;
    fore(i, 2, n) {
        cout << "? " << i << " " << n << endl;
        cin >> x;
        v.pb(tot - x);
        tot = x;
    }
    v.pb(tot - last);
    v.pb(last);
    cout << "! "; for(auto it : v) cout << it << ' '; cout << endl;
    return 0;
}
