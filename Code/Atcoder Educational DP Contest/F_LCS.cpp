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

ll t, i, j, k;
string a, b;
int dp[3005][3005];

int DP(int n, int m) {
    if(n == 0 || m == 0) return dp[n][m] = 0;
    if(dp[n][m] != -1) return dp[n][m];
    if(a[n-1] == b[m-1]) return dp[n][m] = DP(n-1, m-1) + 1;
    return dp[n][m] = max(DP(n-1, m),DP(n, m-1));
}

int main(){
    io;
    t=1;
    // cin >> t;
    while(t--) { 
        cin >> a >> b;  
        memset(dp, -1, sizeof(dp));
        DP(a.length(),b.length());
        i=a.length();
        j=b.length();
        string ans = "";
        while(i>0 && j>0) {
            if(a[i-1] == b[j-1]) {
                ans = a[i-1] + ans;
                --i;
                --j;
            }
            else if(dp[i][j-1] > dp[i-1][j]) --j;
            else --i;
        }
        cout << ans << endl;
    }
    return 0;
}
