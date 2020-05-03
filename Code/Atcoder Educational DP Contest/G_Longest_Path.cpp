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

ll t, i, j, k, N, M;
vi graph[100005];

void addDirectedEdge() {
    ll a,b;
    cin >> a >> b;
    pb(graph[a], b);
}

bool visited[100005] = {false};
/* Depth First Search */
int dp[100005];
int dfs(int n) {
    visited[n] = true;
    if(dp[n]==-1) {
        int max_length = 0;
        for(int i: graph[n]) max_length = max(max_length, 1+dfs(i));
        dp[n] = max_length;
    }
    return dp[n];
}

int main(){
    io;
    t=1;
    // cin >> t;
    while(t--) { 
        cin >> N >> M;
        REP(i,M) addDirectedEdge();
        memset(dp, -1, sizeof(dp));
        FOR(i,1,N+1) if(!visited[i]) dfs(i);
        cout << *max_element(dp+1,dp+1+N) << endl;
    }
    return 0;
}
