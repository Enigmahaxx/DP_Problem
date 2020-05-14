/*
*   @author: Kshitiz Srivastava (pirateksh) @ MNNIT Allahabad
*/
class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        multiset<int> s;
        s.insert(dp[0]);
        
        for(int i=1;i<nums.size();++i) {
            dp[i] = max(nums[i], nums[i] + *(--s.end()));
            s.insert(dp[i]);
            if(i-k >= 0) s.erase(s.find(dp[i-k]));
        }
        return *max_element(dp.begin(), dp.end());
    }
};
