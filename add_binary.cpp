/*

Given two binary strings, return their sum (also a binary string).

The input strings are both non-empty and contains only characters 1 or 0.

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"
 

Constraints:

Each string consists only of '0' or '1' characters.
1 <= a.length, b.length <= 10^4
Each string is either "0" or doesn't contain any leading zero.

*/

class Solution {
public:
    string addBinary(string a, string b) {
        string result;
        int i = a.size()-1;
        int j = b.size()-1;
        int carry = 0;
        while (i >= 0 && j >=0) {
            int x = a[i]-'0';
            int y = b[j]-'0';
            int res = x+y+carry;
            if (res == 1) {
                result += '1';
                carry = 0;
                --i;
                --j;
            } else if (res == 2) {
                result += '0';
                carry = 1;
                --i;
                --j;
            } else if (res == 0) {
                result += '0';
                carry = 0;
                --j;
                --i;
            } else if (res == 3) {
                result += '1';
                carry = 1;
                --i;
                --j;
            }
        }
        if (j >= 0) {
            i = j;
            a = b;
        }
        while (i >= 0) {
            int res = a[i]-'0' + carry;
            if (res == 1) {
                result += '1';
                carry = 0;
                --i;
            } else if (res == 0) {
                result += '0';
                carry = 0;
                --i;
            } else if (res == 2) {
                result += '0';
                carry = 1;
                --i;
            }
        }
        if (carry == 1) {
            result += '1';
        }
        reverse(result.begin(),result.end());
        return result;
    }
};