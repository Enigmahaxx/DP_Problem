/**
*   @author: Kshitiz Srivastava (Pirate_ksh) @ MNNIT Allahabad
*/
#include<bits/stdc++.h>
using namespace std;
 
// General
#define ll long long
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define mod 1000000007
#define mod_ 998244353 
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

ll t, n, i, j, k;

ll dp[105][105];
ll a[105];
ll DP(int n, int w) {
    if(n == 0 && w > 0) return dp[n][w] = INT_MAX;
    if(w == 0 || n == 0) return dp[n][w] = 0;
    if(dp[n][w] != -1) return dp[n][w];
    if(n > w || a[n-1] == -1)
        return dp[n][w] = DP(n-1, w);
    return dp[n][w] = min(a[n-1]+DP(n, w - n),DP(n-1, w));
}

int main(){
    io;   
    t=1;
    cin >> t;
    while(t--) { 
        cin >> n >> k;
        REP(i, k) cin >> a[i];
        memset(dp, -1, sizeof(dp));
        ll ans = DP(k,k);
        if(ans == INT_MAX) cout << -1 << endl;
        else cout << ans << endl;
    }
    return 0;
}
