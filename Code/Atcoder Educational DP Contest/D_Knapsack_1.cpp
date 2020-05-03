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


ll w[100] = {0}, v[100] = {0};
ll dp[101][100001];
ll KnapSack(ll W, ll n) {
    if(W <= 0 || n == 0) return 0;
    if(dp[n][W] == -1) {
        if(w[n-1] > W) dp[n][W] = KnapSack(W, n-1);
        else
            dp[n][W] = max(v[n-1] + KnapSack(W-w[n-1], n-1), KnapSack(W, n-1));
    }
    return dp[n][W];
}

int main(){
    io;
    ll t, n, i, j;
    t=1;
    // cin >> t;
    ll W, k;
    while(t--) {
        cin >> n >> W;
        REP(i, n) cin >> w[i] >> v[i];
        memset(dp, -1, sizeof(dp));
        cout << KnapSack(W, n) << endl;   
    }   
    return 0;
}
