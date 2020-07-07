/*

Given a non-empty array of digits representing a non-negative integer, plus one to the integer.

The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.

You may assume the integer does not contain any leading zero, except the number 0 itself.

Example 1:

Input: [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Example 2:

Input: [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.

*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int size = digits.size();
        vector<int> result;
        /* Numbers get too huge
        int number = digits[0];
        for(int i = 1;i < size;++i) {
            number = number * 10 + digits[i];
        }
        ++number;
        while(number != 0) {
            result.insert(result.begin(),number%10);
            number /= 10;
        } */
        bool isCarry = false;
        int run = digits[size - 1] + 1;
        if (run == 10) {
            result.insert(result.begin(),0);
            isCarry = true;
        } else {
            result.insert(result.begin(),run);
        }
        for(int i = size - 2;i >= 0;--i) {
            if (isCarry) {
                run = digits[i] + 1;
                if (run == 10) {
                    isCarry = true;
                    run = 0;
                } else {
                    isCarry = false;
                }
                result.insert(result.begin(),run);
            } else {
                result.insert(result.begin(),digits[i]);
            } 
        }
        if (isCarry) result.insert(result.begin(),1);
        return result;
    }
};