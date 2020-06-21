/**
*   @author: Kshitiz Srivastava (Pirate_ksh) @ MNNIT Allahabad
*   @note: This is solution using Prefix Function (KMP).
*/
#include<bits/stdc++.h>
using namespace std;
 
// General
#define ll long long
#define ld long double
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define mod 1000000007
#define PI 3.1415926535897932384
#define endl "\n"
#define debug(x) cout<<x<<endl
#define REP(i,n) for(i=0;i<n;++i)
#define FOR(i,x,n) for(i=x;i<n;++i)
 
// Bounds
#define lb(a,x) a.lower_bound(x)
#define ub(a,x) a.upper_bound(x)
#define all(a) a.begin(),a.end()
 
// Vector
#define vi vector <int>
#define pb(v,x) v.push_back(x)
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

vector<int> prefix_function(string s) {
    int n = s.length();
    vector<int> pi(n, 0);
    for(int i=1;i<n;++i) {
        int j = pi[i-1];
        while(j>0 && s[i]!=s[j])
            j = pi[j-1];
        if(s[i] == s[j])
            ++j;
        pi[i] = j;
    }
    return pi;
}

int main(){
    io
    ll t,i,j,k,n,m,q;
    t=1;
    // cin >> t;
    while(t--) {
        string s, revs;
        cin >> s;
        n = s.length();
        vi pi = prefix_function(s+"#"+s);
        vi lens;
        j = pi[pi.size()-1];
        // pb(lens, j);
        while(j>0) {
            j = pi[j-1];
            if(j!=0 && j!=n) pb(lens,j);
        }
        sort(all(lens));
        vi cnt(n+1);
        REP(i,n) cnt[pi[i]]++;
        for(i=n-1;i>0;--i) cnt[pi[i-1]]+=cnt[i];
        REP(i,n+1) cnt[i]++;
        int sz = lens.size();
        bool flg = true;
        for(i=sz-1;i>=0;--i) {
            if(cnt[lens[i]] > 2) {
                cout << s.substr(0,lens[i]) << endl;
                flg = false;
                break;
            } 
        }
        if(flg) cout << "Just a legend\n";
    }   
    return 0;
}
