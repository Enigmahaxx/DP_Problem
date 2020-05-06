/************
* 	@Just Another Source code by: ankit.sangwan1999
*	@created on: 6 May 2020
*/
#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL) //;cout.tie(NULL)
#define ll long long
const int mod = 1e9+7;
#define endl '\n'

const int MASK = 1024;
const int MAXTVAL = 100;
int dp[MASK+1][MAXTVAL+1];

int n;
int allmask;

vector<vector<int>> T(101); // T-shirt id Numbered from 1 to 100
int fun(int mask, int t_id){ // IMP. t_id is not same as no, of set bits in mask. So, t_id is a different state.

	// 2 - OPTIONS for every T-shirt 
				// 1. Dont give it to any one of T[t_id] i.e. completely skip this T-shirt for everyone.
				// 2. Give it to someone from T[t_id] who has not worn any T-shirt yet.
	// ith bit of mask denotes that whether ith person has worn a T-shirt.

	if(mask == allmask){
		return 1; // Found a way.
	}

	if(t_id>100){
		return 0; // This is not the way.
	}

	// MEMO:-
	if(dp[mask][t_id] != -1) return dp[mask][t_id];


	int ways = 0;
	// OPT. 1
	ways += fun(mask, t_id+1);

	int worthy_persons_list_size = T[t_id].size();

	// OPT. 2
	for(int i=0;i<worthy_persons_list_size;i++){

		if( (1<<T[t_id][i]) & mask ) continue; // This person has already worn a T-shirt.

		dp[mask | (1<<T[t_id][i])][t_id+1] = fun( mask | (1<<T[t_id][i]), t_id+1);
		ways = (ways%mod + dp[mask | (1<<T[t_id][i])][t_id+1]%mod)%mod;
	}

	return dp[mask][t_id] = ways;

}



signed main(){
    // fastio;
    int t;
    cin>>t;
    while(t--){
 		
    	memset(dp,-1,sizeof(dp));
    	T = vector<vector<int>>(101);
 		int n;
    	scanf("%d", &n);
    	vector<vector<int>> P(n); // Person Numbered as P0, P1, P2...
    	allmask = (int)pow(2,n) - 1;

    	int inp;
    	char temp;
    	for(int i=0;i<n;i++){
    		do{
		  		scanf("%d%c", &inp, &temp); 
		  		P[i].push_back(inp);
    			T[inp].push_back(i); // inp T-shirt is with all T[inp] persons.
		  	}while(temp!= '\n');
    	}

    	int mask = 0;
    	int t_id = 1;
    	// cout<<fun(mask, t_id)<<endl;
    	printf("%d\n", fun(mask, t_id));

    }


    return 0;
}