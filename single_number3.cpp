/*

Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.

Example:

Input:  [1,2,1,3,2,5]
Output: [3,5]
Note:

The order of the result is not important. So in the above example, [5, 3] is also correct.
Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?

*/

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> result(2,0);
        int xy = 0;
        for(auto &x:nums) {
            xy ^= x;
        }
        int d = xy;
        d &= -d;
        for(auto &num:nums) {
            if ((num&d) == 0) {
                result[0] ^= num;
            } else {
                result[1] ^= num;
            }
        }
        return result;
    }
};