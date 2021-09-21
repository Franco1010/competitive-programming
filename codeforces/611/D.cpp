/*
 © 2021-09-21 11:51:47 Franco1010 All Rights Reserved
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
struct Hash {
  int P=1777771,MOD[2],PI[2];
  vector<int> h[2],pi[2];
  Hash(string& s){
    MOD[0]=999727999;MOD[1]=1070777777;
    PI[0]=325255434;PI[1]=10018302;
    for(int k = 0; k < 2; ++k)h[k].resize(s.size()+1),pi[k].resize(s.size()+1);
    for(int k = 0; k < 2; ++k){
      h[k][0]=0;pi[k][0]=1;
      long long p=1;
      for(int i = 1; i < (int)(s.size()) + 1; ++i){
        h[k][i]=(h[k][i-1]+p*s[i-1])%MOD[k];
        pi[k][i]=(1LL*pi[k][i-1]*PI[k])%MOD[k];
        p=(p*P)%MOD[k];
      }
    }
  }
  long long get(int s, int e){
    long long h0=(h[0][e]-h[0][s]+MOD[0])%MOD[0];
    h0=(1LL*h0*pi[0][s])%MOD[0];
    long long h1=(h[1][e]-h[1][s]+MOD[1])%MOD[1];
    h1=(1LL*h1*pi[1][s])%MOD[1];
    return (h0<<32)|h1;
  }
};
const lli N = 5e3 + 5;
const lli MOD = 1e9 + 7;
lli n;
string s; 
lli dp[N][N];
lli acu[N][N];
bool le(Hash& hs, lli a, lli b, lli c, lli d){
  if(s[a] != s[c]) return s[a] < s[c];
  if(hs.get(a, b + 1) == hs.get(c, d + 1)) return false;
  lli pos = 0;
  for(lli p = n; p; p /= 2) while(pos + p < b - a + 1 and hs.get(a, a + pos + p + 1) == hs.get(c, c + pos + p + 1)) pos += p;
  pos++;
  return s[a + pos] < s[c + pos];
}
int main(){ _
  // freopen("file.in","r",stdin);
  // freopen("file.out","w",stdout);
  cin >> n;
  cin >> s;
  Hash hs(s);
  fore(i, 0, n) dp[i][n - 1] = acu[i][n - 1] = 1;
  for(lli i = n - 1; i >= 0; i--){
    for(lli j = n - 2; j >= i; j--){
      if(s[j + 1] != '0'){
        if(j + (j - i + 1) < n and le(hs, i, j, j + 1, j + (j - i + 1))){
          dp[i][j] = (dp[i][j] + acu[j + 1][j + (j - i + 1)]) % MOD;
        }else if(j + (j - i + 1) + 1 < n){
          dp[i][j] = (dp[i][j] + acu[j + 1][j + (j - i + 1) + 1]) % MOD;
        }
      }
      acu[i][j] = (acu[i][j] + acu[i][j + 1] + dp[i][j]) % MOD;
    }
  }
  cout << acu[0][0] << ENDL;
  return 0;
}
