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

ll t, i, j, k, n, minimum;
int a[105];

int dp[100005][2];
int DP(int rem, int plr) {
    if(rem < minimum) return dp[rem][plr] = plr;
    if(dp[rem][plr] != -1) return dp[rem][plr];
    int ans = plr, it;
    REP(it,n) {
        if(rem >= a[it]) {
            if(plr == 0) ans = max(ans , DP(rem-a[it], (plr+1)%2));
            else ans = min(ans, DP(rem-a[it], (plr+1)%2));
        }
    }
    return dp[rem][plr] = ans;
}

int main(){
    io;
    t=1;
    while(t--) { 
        cin >> n >> k;
        REP(i,n) cin >> a[i];
        minimum = *min_element(a, a+n);
        memset(dp, -1, sizeof(dp));
        ll des = DP(k, 0);
        if(des == 0) cout << "Second\n";
        else cout << "First\n";
    }
    return 0;
}
