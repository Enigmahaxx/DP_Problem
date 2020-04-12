/**
*   @author: Kshitiz Srivastava (Pirate_ksh) @ MNNIT Allahabad
*   @note: This question has mainly 3 possible solutions - 
*           1. O(1) solution: Refer to Tutorial https://codeforces.com/blog/entry/23522
*           2. BFS solution: https://codeforces.com/contest/626/submission/15997121
*           3. DP solution: This solution
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
ll r, b, g;
bool R = false, G = false, B = false;
bool dp[205][205][205];
bool DP(int r, int g, int b) {
    if(r + g + b == 1) {
        if(r == 1) R = true;
        else if(g == 1) G = true;
        else if(b == 1) B = true;
        return dp[r][g][b] = true;
    }
    if(dp[r][g][b]) return dp[r][g][b];
    if(r >= 2) DP(r-1, g, b);
    if(g >= 2) DP(r, g-1, b);
    if(b >= 2) DP(r, g, b-1);
    if(r >= 1 && g >= 1) DP(r-1, g-1, b+1);
    if(r >= 1 && b >= 1) DP(r-1, g+1, b-1);
    if(b >= 1 && g >= 1) DP(r+1, g-1, b-1);
    return dp[r][g][b] = true;
}

int main(){
    io;
    t=1;
    // cin >> t;
    while(t--) { 
        cin >> n;
        string s;
        cin >> s;
        REP(i, n) {
            if(s[i] == 'R') ++r;
            if(s[i] == 'B') ++b;
            if(s[i] == 'G') ++g;
        }
        
        REP(i, 205)
            REP(j, 205)
                REP(k, 205)
                    dp[i][j][k] = false;
       
        DP(r, g, b);
        
        if(B) cout << 'B';
        
        if(G) cout << 'G';   

        if(R) cout << 'R'; 
    }
    return 0;
}
