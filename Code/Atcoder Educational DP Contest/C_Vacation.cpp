/**
*   @author: Kshitiz Srivastava (Pirate_ksh) @ MNNIT Allahabad
*/
#include<bits/stdc++.h>
using namespace std;
 
// General
#define ll long long
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define mod 1000000007
#define mod9 998244353 
#define endl "\n"
#define debug(x) cout<<x<<endl
#define REP(i,n) for(i=0;i<n;++i)
#define FOR(i,x,n) for(i=x;i<n;++i)
 
// Bounds
#define lb(a, x) a.lower_bound(x)
#define ub(a, x) a.upper_bound(x)
#define all(a) a.begin(),a.end()
 
// Vector
#define vi vector <int>
#define pb(v, x) v.push_back(x)
#define vsi vector <set <int> >
 
// Map
#define mii map <int, int>
 
// Set
#define si set <int>
 
// Pair
#define vpii vector<pair < int, int > >
#define pii pair < int, int >
#define F first
#define S second

int main(){
    io;
    ll t, n, i, j;
    t=1;
    // cin >> t;
    while(t--) {
        cin >> n;
        vi a(n), b(n), c(n);
        REP(i, n) cin >> a[i] >> b[i] >> c[i];
        int dp[n][3];
        dp[0][0] = a[0];
        dp[0][1] = b[0];
        dp[0][2] = c[0];
        FOR(i, 1, n) {
            dp[i][0] = a[i] + max(dp[i-1][1], dp[i-1][2]);
            dp[i][1] = b[i] + max(dp[i-1][0], dp[i-1][2]);
            dp[i][2] = c[i] + max(dp[i-1][1], dp[i-1][0]);
        }

        cout << max({dp[n-1][0], dp[n-1][1], dp[n-1][2]}) << endl;
    }   
    return 0;
}
