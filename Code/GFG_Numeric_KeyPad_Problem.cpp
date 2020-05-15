/************
* 	@Just Another Source code by: ankit.sangwan1999
*	@created on: 15 May 2020
*/
#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL) //;cout.tie(NULL)
#define ll long long
const int mod = 1e9+7;
#define endl '\n'

vector<vector<int>> keys;
vector<vector<vector<long long>>> dp;
bool is_safe(int x, int y){

	if(x<0 or x>5 or y<0 or y>4) return 0;
	return 1;

}

long long fun(int len , int x, int y){ // x,y button is pressed
	// Base Cases
	if(!is_safe(x,y) or keys[x][y]==-1) return 0; // pressed x,y button is invalid. 
	if(dp[len][x][y] != -1) return dp[len][x][y];
	if(len<=0) return 1; // Found a way.
	
	// Solving Choice Diagram

	long long ans=0;
	if(len-1>=0){
		if(dp[len-1][x][y] == -1){
			dp[len-1][x][y] = fun(len-1, x, y);  // choosing to press x,y button again
		}
		if(dp[len-1][x-1][y] == -1){
			dp[len-1][x-1][y] = fun(len-1, x-1, y); // choosing to press upper button and not the x,y again
		}
		if(dp[len-1][x][y-1] == -1){
			dp[len-1][x][y-1] = fun(len-1, x, y-1); // choosing to press left button and not the x,y again
		}
		if(dp[len-1][x+1][y] == -1){
			dp[len-1][x+1][y] = fun(len-1, x+1, y); // hoosing to press lower button and not the x,y again
		}
		if(dp[len-1][x][y+1] == -1){
			dp[len-1][x][y+1] = fun(len-1, x, y+1); // // choosing to press right button and not the x,y again
		}
		ans = dp[len-1][x][y]+dp[len-1][x-1][y]+dp[len-1][x][y-1]+dp[len-1][x+1][y]+dp[len-1][x][y+1];
	}
	

	return dp[len][x][y] = ans;

}

signed main(){

    fastio;

	keys = vector<vector<int>>(6,vector<int>(5)) ;
	int x=1;
	for(int i=0;i<6;i++){
		for(int j=0;j<5;j++){
			if(i==0 or j==0 or i==4 or j==4 or i==5){
				keys[i][j] = -1;
			}
			else{
				keys[i][j] = x++;
			}
			
		}
	}
	keys[4][2] = 0;
	// for(int i=0;i<6;i++){
	// 	for(int j=0;j<5;j++){
	// 		cout<<keys[i][j]<<"  ";			
	// 	}
	// 	cout<<endl;
	// }

    int t;
    cin>>t;
    while(t--){
    	int n;
    	cin>>n;

    	dp = vector<vector<vector<long long>>>(n,vector<vector<long long>>(6,vector<long long>(5))) ;
	    for(int k=0;k<n;k++){
	    	for(int i=0;i<6;i++){
	    		for(int j=0;j<5;j++){
	    			dp[k][i][j] = -1;
	    		}
	    	}
		}


    	long long ans=0;
    	for(int i=0;i<5;i++){
    		for(int j=0;j<5;j++){
    			if(keys[i][j] !=-1){
    				ans += fun(n-1, i, j);
    			}
    		}
    	}

    	cout<<ans<<endl;

    }

    return 0;
}