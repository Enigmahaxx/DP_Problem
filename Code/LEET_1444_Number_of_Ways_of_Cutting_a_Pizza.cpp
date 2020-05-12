/**
*   @author: Kshitiz Srivastava (Pirate_ksh) @ MNNIT Allahabad
*/
class Solution {
public:
    long long dp[55][55][15], MOD = 1000000007, n, m, k;
    long long DP(int i, int j, int cnt, vector<vector<int>>& p) {
        if(p[i][j] == 0) return dp[i][j][cnt] = 0;
        if(cnt == 0) return dp[i][j][cnt] = 1;
        if(dp[i][j][cnt] != -1) return dp[i][j][cnt];
        long long ans = 0;
        for(int it = i+1; it <= n; ++it) {
            // Horizontal Cut
            if(p[i][j] - p[it][j] > 0)
                ans = ((ans % MOD) + (DP(it,j,cnt-1,p) % MOD)) % MOD;
        }
        for(int it = j+1; it <= m; ++it) {
            // Vertical Cut
            if(p[i][j] - p[i][it] > 0)
                ans = ((ans % MOD) + (DP(i,it,cnt-1,p) % MOD)) % MOD;
        }
        return dp[i][j][cnt] = ans % MOD;
    }
    
    int ways(vector<string>& pizza, int k) {
        n = pizza.size();
        m = pizza[0].size();
        vector<vector<int> > pref(n+1, vector<int>(m+1,0));
        
        // Initialising prefix 2D vector
        pref[n][m] = (pizza[n-1][m-1] == 'A')?1:0;
        for(int i=n-1;i>0;--i) pref[i][m] = pref[i+1][m] + (pizza[i-1][m-1] == 'A');
        for(int i=m-1;i>0;--i) pref[n][i] = pref[n][i+1] + (pizza[n-1][i-1] == 'A');
        
        // Filling Rest of the cells of prefix 2D vector
        for(int i=n-1;i>0;--i) {
            for(int j=m-1;j>0;--j) {
                pref[i][j] = pref[i+1][j] + pref[i][j+1] - pref[i+1][j+1] + (pizza[i-1][j-1] == 'A');
            }
        }
        
        memset(dp, -1, sizeof(dp));
        return DP(1,1,k-1,pref);
    }
};
