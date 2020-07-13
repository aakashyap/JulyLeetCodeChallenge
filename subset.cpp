/*

Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]

*/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int size = nums.size();
        int powerset = 2 << size;
        set<vector<int>> cache;
        for(int i = 0;i<powerset;++i) {
            vector<int> temp;
            for(int j = 0;j<size;++j) {
                if (i & (1<<j)) {
                    temp.push_back(nums[j]);
                }
            }
            cache.insert(temp);
        }
        return vector<vector<int>>(cache.begin(),cache.end());
    }
};