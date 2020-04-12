/**
*   @author: Kshitiz Srivastava (Pirate_ksh) @ MNNIT Allahabad
*   @note: This is an easy single state DP question.
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

ll dp[100005];
ll a[100005];
mii chk;

int main(){
    io;
    
    t=1;
    // cin >> t;
    while(t--) { 
        cin >> n >> k;
        REP(i, n) {
            cin >> a[i];
        }
        dp[n] = 1;
        chk[a[n-1]] = 1;
        for(i = n-2; i >= 0; --i) {
            if(!chk[a[i]]) {
                dp[i+1] = 1 + dp[i+2];
                chk[a[i]] = 1;
            }
            else dp[i+1] = dp[i+2];
        }
        REP(i, k) {
            int x;
            cin >> x;
            cout << dp[x] << endl;
        }
    }
    return 0;
}
