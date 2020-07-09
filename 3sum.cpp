/*

Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]

*/


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int size = nums.size();
        vector<vector<int>> result;
        if (size < 3) return result;
        sort(nums.begin(),nums.end());
        for (int i = 0;i<size-2;++i) {
            if (i >= 1 && nums[i] == nums[i-1]) continue;
            int val = -nums[i];
            int j = i+1;
            int k = size-1;
            while (j<k) {
                if (j > i+1 && nums[j] == nums[j-1]) {
                    ++j;
                    continue;
                }
                int twosum = nums[j] + nums[k];
                if (twosum == val) {
                    result.push_back({nums[i],nums[j],nums[k]});
                    ++j;
                } else if (nums[j] + nums[k] < val) {
                    ++j;
                } else {
                    --k;
                }
            } 
        }
        return result;
    }
};