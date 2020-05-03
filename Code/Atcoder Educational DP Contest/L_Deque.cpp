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
int a[3005];

ll dp[3005][3005][2];
ll DP(int front, int last, int plr) {
    if(front == last) {
        if(!plr) return dp[front][last][plr] = a[front]; // Taro
        else return dp[front][last][plr] = -a[front]; // Jiro
    }
    if(dp[front][last][plr] != -1) return dp[front][last][plr];
    // Taro
    if(plr==0) return dp[front][last][plr] = max(a[front] + DP(front+1, last, 1), a[last] + DP(front, last-1, 1));
    // Jiro
    else return dp[front][last][plr] = min(-a[front] + DP(front+1, last, 0), -a[last] + DP(front, last-1, 0));
}

int main(){
    io;
    t=1;
    while(t--) { 
        cin >> n;
        REP(i,n) cin >> a[i];
        memset(dp, -1, sizeof(dp));
        cout << DP(0,n-1,0) << endl;
    }
    return 0;
}
