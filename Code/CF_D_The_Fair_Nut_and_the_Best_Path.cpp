/**
*   @author: Kshitiz Srivastava (Pirate_ksh) @ MNNIT Allahabad
*/
#include<bits/stdc++.h>
using namespace std;
 
// General
#define ll long long
#define ld long double
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define mod 1000000007 // 998244353
#define PI 3.1415926535897932384
#define endl "\n"
#define debug(x) cout<<x<<endl
#define REP(i,n) for(i=0;i<n;++i)
#define FOR(i,x,n) for(i=x;i<n;++i)
#define RREP(i,n) for(i=n-1;i>=0;--i)
#define RFOR(i,x,n) for(i=n-1;i>=x;--i)
 
// Bounds
#define lb(a,x) a.lower_bound(x)
#define ub(a,x) a.upper_bound(x)
#define all(a) a.begin(),a.end()
 
// Vector
#define vi vector <int>
#define pb(v,x) v.push_back(x)
#define vll vector <ll>
 
// Map
#define mii map <int, int>
#define umii unordered_map <int, int>
 
// Set
#define si set <int>
#define msi multiset<int>
 
// Pair
#define vpii vector<pair < int, int > >
#define vpll vector<pair < ll, ll > >
#define pii pair < int, int >
#define mp(a,b) make_pair(a,b)
#define F first
#define S second
#define vppi vector<pair<pair<int,int>,int>>
#define ppi pair<pair<int,int>,int>

void solve();

int main(){
    io
    ll t;
    t=1;
    // cin >> t;
    while(t--) solve();
    return 0;
}

ll DP(vector<pair<ll,ll>> graph[], vll &c, vll &vis, ll v, ll par, ll &ans) {
    vis[v] = 1;
    int sz = graph[v].size();
    if(sz == 1) return c[v];
    vll temp(sz);
    for(ll i=0;i<sz;++i) {
        if(graph[v][i].F != par) {
            temp[i] = DP(graph, c, vis, graph[v][i].F, v, ans);
            ans = max(ans,temp[i]);
        }
    }
    ll mx = INT_MIN, secondmx = INT_MIN;
    // Maximum
    for(ll i=0;i<sz;++i) {
        if(graph[v][i].F != par) {
            if(temp[i]-graph[v][i].S > mx) {
                mx = temp[i]-graph[v][i].S;
            }
        }
    }
    // Second maximum
    for(ll i=0;i<sz;++i) {
        if(graph[v][i].F != par) {
            if(temp[i]-graph[v][i].S > secondmx && temp[i]-graph[v][i].S != mx) {
                secondmx = temp[i]-graph[v][i].S;
            }
        }
    }
    ll tempp = c[v] + max({mx, mx + secondmx,(ll)0});
    ans = max(tempp, ans);
    return max({c[v], mx + c[v]});
}

void solve() {
    ll i, j, k, n;
    cin >> n;
    vll c(n+1);
    REP(i,n) cin >> c[i+1];
    vector<pair<ll,ll>> graph[n+1];
    REP(i,n-1) {
        ll a, b, w;
        cin >> a >> b >> w;
        pb(graph[a], mp(b,w));
        pb(graph[b], mp(a,w));
    }
    vll vis(n+1,0);
    ll ans = -1e18;
    FOR(i,1,n+1) {
        if(vis[i] == 0){
            DP(graph, c, vis, i, -1, ans);
        }
    }
    cout << ans;
}
