/************
* 	@Just Another Source code by: ankit.sangwan1999
*	@created on: 11 Apr 2020
*/
#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL) //;cout.tie(NULL)
#define ll long long
// Constants
#define llmax LLONG_MAX
#define ullmax ULLONG_MAX
const int mod = 1e9+7;
#define endl '\n'
#define debug(x) cout<<x<<endl
// Bounds
#define lb(a, x) a.lower_bound(x)
#define ub(a, x) a.upper_bound(x)
#define all(a) a.begin(),a.end()
// Set
#define si set <int>
#define sl set <ll>
// Map
#define mii map <int, int>
#define mll map <ll, ll>
#define mpiii map <pii, int>
#define mpiil map <pii, ll>
// Pair
#define pii pair < int, int >
#define pll pair <ll, ll>
#define F first
#define S second
// Vector 
#define vi vector <int>
#define vl vector <ll>
#define vsi vector < si >
#define vpii vector < pii >
#define pb push_back
#define pp pop_back 
#define vlb(a,x) lower_bound(a.begin(),a.end(),x)
#define vub(a,x) upper_bound(a.begin(),a.end(),x)
// transform(str.begin(), str.end(), str.begin(), ::tolower); 
// transform(str.begin(), str.end(), str.begin(), ::toupper); 
// reverse(str.begin(), str.end());
/*******/
//NUMBER THEORY STARTS
/*******/

// MMI of a under m => a,m are coprime. O(log(max(a,b)))
//		  a*cofx + m*cofy = 1 
// 		call -> modmulinv(a,m,&cofx,&cofy); check-> if cofx<0 cofx += m;
/*
int modmulinv(int a, int m, int *cofx, int *cofy){
	if(a==0)
	{
		*cofx = 0;
		*cofy = 1;
		return m;
	}
	else{
		int x1,y1;
		int g= modmulinv( m%a , a , &x1 , &y1);
		*cofy = x1;
		*cofx = y1 - (m/a)*x1;
		return g;
	}
}
*/

//  SIEVE 
/*
const int PR = 1e6+5;
vector <int> primes;
vector <bool> isPrime(PR);
void sieve(){
	for(int i=2;i<PR;++i){
		isPrime[i] = true;
	}
	for(int i=2;i*i<PR;++i){
		if(isPrime[i] == true){
			for(int j=i*i;j<PR;j+=i){
				isPrime[j] = false;
			}
		}
	}
	for(int i=2;i<PR;++i)
		if(isPrime[i])
			primes.push_back(i);	
} 
*/

// POWER
/*
ll power( ll a, ll b){
	ll ans = 1;
	while(b>0){
		if(b&1)
			ans = ans * a;
		a = a * a;
		b>>=1;
	}
	return ans;
}
*/

//  FACTORIALS
/*
const int FA = 1e6+5;
vector<long long>fact(FA);
void factorial(){
    fact[0] = 1;
    for(int i=1;i<FA;++i){
        fact[i] = (fact[i-1]%mod * i%mod)%mod; 
    }
}
*/

// INV_FACTORIALS
/*
vector<long long> invfact(FA); // stores inverse factorial modulo 1e9+7
void invfactorial(){
    invfact[0] = 1;
    for(int i=1;i<FA;++i){
        invfact[i] = power(fact[i], mod-2); 
    }
}
*/

// nCr
/*
ll nCrmod(ll n, ll r){
	if(r>n) return 0;
	return ( (fact[n]%mod * invfact[r]%mod)%mod * (invfact[n-r]%mod) )%mod;
}
*/

/*******
NUMBER THEORY ENDS
*******/

// Strings
/*
bool is_palin(string s){
    int s_l = s.length();
    int i = 0;
    int j = s_l - 1;
    while(i<j){
        if(s[i]==s[j]){
            ++i;
            --j;
        }
        else{
            return false;
        }
    }
    return true;
}
*/

/**************************************************************************************/
map<string, bool> dp;

bool wb(map<string,bool>dict, string s){

	if(s.empty()){
		return true;
	}
    if(dp.find(s)!=dp.end()){
        return dp[s];
    }

	for(int i=1;i<=s.length();i++){
		if( dict[s.substr(0,i)] && wb(dict,s.substr(i,s.length()-i)) ){
            dp[s.substr(i,s.length()-i)] = true;
			return true;
		}
	}
    dp[s] = false;
	return false;

}

signed main(){
	//#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
 	//#endif

    fastio;
    int t=1;
    cin>>t;
    while(--t>=0){
    	int n;
    	cin>>n;
    	string s;
    	map<string,bool>dict;
    	
    	for(int i=0;i<n;i++){
    		cin>>s;
    		dict[s]=1;
    	}
    	// for(map<string,bool>::iterator itr = dict.begin();itr!=dict.end();itr++){
    	// 	cout<<(*itr).F<<endl;
    	// }

    	cin>>s;

    	bool dp[s.length()+1] = {0}; // dp[i] -> represents answer for i length of string.
    	dp[0] = true;

    	for(int i=1;i<=s.length();i++){
    		for(int j=0;j<i;j++){
    			if(dp[i]) continue;
    			dp[i] = dp[i] || (dp[j] && dict[s.substr(j,i-j)]);
    			// cout<<"String Checked: "<<s.substr(j,s.length()-j)<<endl;
    		}
    	}

    	if(dp[s.length()]){
    		cout<<"1"<<endl;
    	}
    	else{
    		cout<<"0"<<endl;
    	}
    }
	


    return 0;
}