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

ll t, i, j, k, h, w;
char grid[1005][1005];

ll dp[1005][1005];
ll DP(int i, int j) {
    if(i == h-1 && j == w-1) return dp[i][j] = 1;
    if(dp[i][j] != -1) return dp[i][j];
    ll right = 0, down = 0;
    if(j+1 < w && grid[i][j+1] == '.') right = DP(i,j+1) % mod;
    if(i+1 < h && grid[i+1][j] == '.') down = DP(i+1,j) % mod;
    return dp[i][j] = (right + down) % mod;
}

int main(){
    io;
    t=1;
    while(t--) { 
        cin >> h >> w;
        REP(i,h) REP(j,w) cin >> grid[i][j];
        memset(dp, -1, sizeof(dp));
        cout << DP(0,0) << endl;
    }
    return 0;
}
