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

#define MODA 100000000
ll n1, n2, k1, k2;

ll dp[105][105][15][15];
ll Good(int frem, int hrem, int foot, int horse) {
    if((frem == 0 && hrem > k2) || (hrem == 0 && frem > k1))
        return dp[frem][hrem][foot][horse] = 0;
    if((frem == 0 && hrem <= k2) || (hrem == 0 && frem <= k1))
        return dp[frem][hrem][foot][horse] = 1;

    if(dp[frem][hrem][foot][horse] != -1)
        return dp[frem][hrem][foot][horse]%MODA;

    if(foot < k1 && horse == k2)
        dp[frem][hrem][foot][horse] = Good(frem-1, hrem, foot+1, 0) % MODA;
    else if(foot == k1 && horse < k2)
        dp[frem][hrem][foot][horse] = Good(frem, hrem-1, 0, horse + 1) % MODA;
    else if(foot < k1 && horse < k2)
        dp[frem][hrem][foot][horse] = (Good(frem-1, hrem, foot+1, 0)%MODA + Good(frem, hrem-1, 0, horse + 1)%MODA)%MODA;
    return dp[frem][hrem][foot][horse]%MODA;
}

int main(){
    io;
    ll t, n, i, j, k;
    t=1;
    // cin >> t;
    
    while(t--) { 
        cin >> n1 >> n2 >> k1 >> k2;
        memset(dp, -1, sizeof(dp));
        cout << Good(n1, n2, 0, 0)%MODA << endl;
    }
    return 0;
}
