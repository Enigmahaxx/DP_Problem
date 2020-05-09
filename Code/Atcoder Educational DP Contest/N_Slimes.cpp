/**
*   @author: Kshitiz Srivastava (Pirate_ksh) @ MNNIT Allahabad
*   @note: This question is based on Matrix Chain Multiplication (MCM).
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
#define mp(a,b) make_pair(a,b)
#define F first
#define S second

ll dp[405][405], a[405], N, actu[405][405];
pair<ll,ll> DP(ll i, ll j) {
    if(i >= j) {
        dp[i][j] = actu[i][j] = a[i];
        return mp(a[i],a[i]);
    }
    if(dp[i][j] != -1) return mp(dp[i][j],actu[i][j]);
    pair<ll,ll> ans = mp((ll)1e18,0);
    for(ll k=i;k<j;++k) {
        pair<ll,ll> p1 = DP(i,k);
        pair<ll,ll> p2 = DP(k+1,j);
        pair<ll,ll> temp_ans = mp(p1.F+p2.F+p1.S+p2.S, p1.S+p2.S);
        if(ans.F > temp_ans.F) ans = temp_ans;
    }
    dp[i][j] = ans.F;
    actu[i][j] = ans.S;
    return ans;
}

int main(){
    io
    ll t;
    t = 1;
    while(t--) {
        cin >> N;
        ll it;
        REP(it,N) cin >> a[it];
        memset(dp, -1, sizeof(dp));
        pair<ll,ll> FIN = DP(0,N-1);
        cout << FIN.F - FIN.S << endl;
    }
    return 0;
}
