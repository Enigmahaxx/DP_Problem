/************
* 	@Just Another Source code by: ankit.sangwan1999
*	@created on: 9 Apr 2020
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
const int N = 1e6;
vector<int> vec[N];



void pre(){
	bool vis[500001] = {0};
	for(int i=2;i<=500000;i++){
		if(!vis[i]){
			for(int j=i;j<=500000;j+=i){
				vis[j] = 1;
				vec[j].pb(i);
			}	
		}
	}
}

signed main(){


	// PROBLIEM LINK:- https://www.hackerrank.com/contests/hourrank-1/challenges/gcd-groups/problem

    fastio;
    pre();

    // for(int i=0;i<=100;i++){
    // 	if(vec[i].size()){
    // 		for(int j=0;j<vec[i].size();j++){
    // 			cout<<vec[i][j]<<" ";
    // 		}
    // 		cout<<endl;
    // 	}
    // }

    int t=1;
    cin>>t;
    while(--t>=0){
    	int n;
    	cin>>n;


    	int arr[n];
   		int ma = INT_MIN;
    	
    	for(int i=0;i<n;i++){
    		cin>>arr[i];
    		ma = max(ma,arr[i]);
    	}

    	int cnt[ma+1] = {0};
    	vi potential_comp;

    	for(int i=0;i<n;i++){
    		for(int j=0;j<vec[arr[i]].size();j++){
    			cnt[vec[arr[i]][j]]++;
    			if(cnt[vec[arr[i]][j]]==n/2){
    				potential_comp.pb(vec[arr[i]][j]);
    			}
    		}
    	}

	    // for(int i=0;i<potential_comp.size();i++){
	    // 	cout<<potential_comp[i]<<" "; 
	    // }
	    // exit(1);

    	bool flag = 0; 

    	for(int i=0;i<potential_comp.size();i++){
    		if(flag) break;
    		for(int j=i;j<potential_comp.size();j++){
    			int cnt1=0,cnt2=0,com=0;
    			for(int k=0;k<n;k++){
    				if(arr[k]%potential_comp[i]==0 &&  arr[k]%potential_comp[j]==0){
    					com++;
    				}
    				if(arr[k]%potential_comp[i]==0){
    					cnt1++;
    				}
    				if(arr[k]%potential_comp[j]==0){
    					cnt2++;
    				}
    			}
    			// cout<<"cnt1: "<<cnt1<<endl;
    			// cout<<"cnt2: "<<cnt2<<endl;

    			cnt1 -= com;
    			cnt2 -= com;
    			int cnt1_need = max(0,n/2 - cnt1);
    			int cnt2_need = max(0,n/2 - cnt2);
    			if(cnt1_need + cnt2_need <= com){
    				flag = 1;
    				break;
    			}

    		}
    	}
    	if(flag)
    		cout<<"YES"<<endl;
    	else
    		cout<<"NO"<<endl;
    }
	


    return 0;
}