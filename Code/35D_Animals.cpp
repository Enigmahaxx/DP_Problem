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

ll dp[105][10004];
ll a[105];
int N, K;
ll Good(int n, int w) {
    if(n == N | w == 0) return dp[n][w] = 0;
    if(dp[n][w] != -1) return dp[n][w];
    if(w - (a[n] * (N-n)) >= 0)
        return dp[n][w] = max(Good(n+1, w), 1 + Good(n+1, w - (a[n] * (N-n))));
    return dp[n][w] = Good(n+1, w);
}

int main(){
    io;
    ll t, n, i, j, k;
    t=1;
    // cin >> t;
    while(t--) { 
        cin >> N >> K;
        REP(i, N) cin >> a[i];  
        memset(dp, -1, sizeof(dp));
        cout << Good(0, K) << endl;
    }
    return 0;
}
