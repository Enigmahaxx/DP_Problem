/*
*   @author: Kshitiz Srivastava (Pirateksh) @ MNNIT Allahabad
*   @note: We will assign "Hats to People" instead of assigning "People to hats" to reduce complexity from
*          O(m.2^n) to O(n.2^m) where n = 40 and 1 <= m <= 10.
*/
#define ll long long
#define vvi vector<vector<int> >
#define mod 1000000007
class Solution {
public:
    
    int countSetBits(ll x) { 
        int count = 0; 
        while (x) { 
            x &= (x-1); 
            count++; 
        } 
        return count;   
    } 
    
    ll dp[45][1030];
    int N;
    
    ll DP(int hatno, ll mask, vvi &p) {
        int n = countSetBits(mask);
        
        // All person have different hats now
        if(n == N) return dp[hatno][mask] = 1;
        
        // All hats exhausted
        if(hatno == 40) return dp[hatno][mask] = 0;
        
        if(dp[hatno][mask] != -1) return dp[hatno][mask];
        
        // Skip this hat
        ll ans = (DP(hatno+1, mask, p) % mod);
        
        // Give this hat to one of the person who wants it
        for(int i=0;i<p[hatno].size();++i) {
            if(!(mask&(1<<p[hatno][i])))
                ans = ((ans % mod) + (DP(hatno+1,mask|(1<<p[hatno][i]),p) % mod)) % mod;
        }
        return dp[hatno][mask] = ans;
    }
    
    int numberWays(vector<vector<int>>& hats) {
        N = hats.size();
        vvi peoples(40);
        for(int i=0;i<N;++i) {
            for(int j=0;j<hats[i].size();++j)
                peoples[hats[i][j]-1].push_back(i);
        }
        memset(dp,-1,sizeof(dp));
        return DP(0,0,peoples);
    }
};
