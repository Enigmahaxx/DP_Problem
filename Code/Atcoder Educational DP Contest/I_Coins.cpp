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

ll t, i, j, k, n;
double p[3000];
double dp[3000][3000];

int main(){
    io;
    t=1;
    while(t--) { 
        cin >> n;
        REP(i,n) cin >> p[i];
        memset(dp, 0, sizeof(dp));
        REP(i,n+1) dp[0][i] = 1.0;
        FOR(i, 1, n+1) {
            REP(j, n+1) {
                double head = p[i-1] * dp[i-1][j-1], tail = 0.0;
                if(i-1+n-j >= (n+1)/2)
                    tail = (1-p[i-1]) * dp[i-1][j];
                dp[i][j] = head + tail;
            }
        }
        cout << setprecision(10) << dp[n][n] << endl;
    }
    return 0;
}
