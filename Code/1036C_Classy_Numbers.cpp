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
#define mp(a,b) make_pair(a,b)
#define F first
#define S second

ll t;
ll dp[20][20][2], L[20], R[20]; 

ll DP(ll i, ll cnt, ll is_less, ll n, ll N[], ll lenn){
    if(i == lenn) return dp[i][cnt][is_less] = 1;
    if(dp[i][cnt][is_less] != -1) return dp[i][cnt][is_less];
    if(cnt >= 3 && N[i] > 0) return dp[i][cnt][is_less] = DP(i+1, cnt, 1, n, N, lenn);
    if(cnt >= 3 && N[i] == 0) return dp[i][cnt][is_less] = DP(i+1, cnt, is_less, n, N, lenn);
    // Here number of Non - zero digits are less than 3
    ll ans = 0;
    if(is_less){
        for(int digit = 0; digit <= 9; ++digit) 
            ans += DP(i+1, cnt+(digit!=0), is_less, n, N, lenn);
        
    } else {
        ans += DP(i+1, cnt+(N[i]!=0), 0, n, N, lenn);
        for(int digit = 0; digit < N[i]; ++digit)
            ans += DP(i+1, cnt+(digit!=0), 1, n, N, lenn);
    }
    return dp[i][cnt][is_less] = ans;
}

int main(){
    io
    t=1;
    cin >> t;
    while(t--) {
        ll l, r, k, templ, tempr, fin_ans, lenl, lenr;
        cin >> l >> r;
        --l;
        if(l==0) lenl = 1;
        else lenl = log10(l) + 1;
        if(r==0) lenr = 1;
        else lenr = log10(r) + 1;
        templ = l;
        tempr = r;
        k = lenl-1;
        while(l>0) {
            L[k--] = l%10;
            l/=10;
        }
        k = lenr-1;
        while(r>0) {
            R[k--] = r%10;
            r/=10;
        }
        memset(dp, -1 ,sizeof(dp));
        ll RRR = DP(0, 0, 0, tempr, R, lenr);
        memset(dp, -1 ,sizeof(dp));
        ll LLL = DP(0, 0, 0, templ, L, lenl);
        cout << RRR - LLL << endl;
    }
    return 0;
}
