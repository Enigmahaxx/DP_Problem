/**
*   @author: Kshitiz Srivastava (Pirate_ksh) @ MNNIT Allahabad
*   @note: To read about Matrix Exponentiation: https://www.hackerearth.com/practice/notes/matrix-exponentiation-1/
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

ll power(ll x, ll y) {
    ll res = 1;
    while (y > 0){
        if (y & 1)
            res = ((res % (ll)mod) * (x % (ll)mod)) % (ll)mod;
        y = y>>1;
        x = ((x % (ll)mod)*(x % (ll)mod)) % (ll)mod;
    }
    return res;
}

vector<vector<ll> > matrixMultiplication(vector<vector<ll> > &A, vector<vector<ll> > &B) {
    int I = A.size(), K = B.size(), J = B[0].size();
    // Matrix A is I x K, Matrix B is K x J 
    // Resultant will be I x J
    vector<vector<ll> > result(I, vector<ll>(J, 0));
    for(int i=0; i<I; ++i) {
        for(int j=0; j<J; ++j) {
            for(int k=0; k<K; ++k)
                result[i][j] = ((result[i][j] % mod) + ((A[i][k] % mod) * (B[k][j] % mod)) % mod) % mod;
        }
    }
    return result;
}

vector<vector<ll> > matrixExponentiation(vector<vector<ll> > M, int x) {
    int n = M.size();
    vector<vector<ll> > result(n, vector<ll>(n, 1));
    while(x>0) {
        if(x&1) result = matrixMultiplication(result, M);
        M = matrixMultiplication(M, M);
        x = x>>1;
    }
    return result;
}

ll t, k;
vector<vector<ll> > allowed(26, vector<ll> (26, 0)), allowedExponentiated(26, vector<ll>(26));

int main(){
    io
    for(int i=0;i<26;++i) {
        for(int j=0;j<26;++j){
            cin >> allowed[i][j];
        }
    }
    vector<vector<ll> > initial(1, vector<ll> (26, 1)), result(1, vector<ll>(26));
    cin >> t;
    while(t--) {
        char c;
        ll l;
        cin >> c >> l;
        allowedExponentiated = matrixExponentiation(allowed, l-1);
        result = matrixMultiplication(initial, allowedExponentiated);
        cout << ((result[0][((int)c)-97])%mod) * (power(26, mod-2)%mod) % mod << endl;
    }
    return 0;
}
