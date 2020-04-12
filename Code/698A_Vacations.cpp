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

ll dp[105][3];
ll a[105];
int N, K;
ll Good(int n, int w) {
    if(n == N) return dp[n][w] = 0;
    if(dp[n][w] != -1) return dp[n][w];
    if(w == 0) {
        // First/Rest day, can do any activity
        if(a[n] == 0) dp[n][w] = Good(n+1, 0);
        else if(a[n] == 1) dp[n][w] = max(1 + Good(n+1, 1), Good(n+1, 0));
        else if(a[n] == 2) dp[n][w] = max(1 + Good(n+1, 2), Good(n+1, 0));
        else if(a[n] == 3) dp[n][w] = 1 + max(Good(n+1, 1), Good(n+1, 2));
        return dp[n][w];
    }
    else if(w == 1) {
        // can do sport
        if(a[n] == 0 || a[n] == 1) dp[n][w] = Good(n+1, 0);
        else if(a[n] == 2 || a[n] == 3) dp[n][w] = max(1 + Good(n+1, 2), Good(n+1, 0));
        return dp[n][w];
    }
    
    // can do contest
    if(a[n] == 0 || a[n] == 2) dp[n][w] = Good(n+1, 0);
    else if(a[n] == 1 || a[n] == 3) dp[n][w] = max(1 + Good(n+1, 1), Good(n+1, 0));
    return dp[n][w];
}

int main(){
    io;
    ll t, n, i, j, k;
    t=1;
    // cin >> t;
    while(t--) { 
        cin >> N;
        REP(i, N) cin >> a[i];  
        memset(dp, -1, sizeof(dp));
        cout << N - Good(0, 0) << endl;
    }
    return 0;
}
