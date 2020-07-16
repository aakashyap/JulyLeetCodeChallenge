/*

Given an input string, reverse the string word by word.

 

Example 1:

Input: "the sky is blue"
Output: "blue is sky the"
Example 2:

Input: "  hello world!  "
Output: "world! hello"
Explanation: Your reversed string should not contain leading or trailing spaces.
Example 3:

Input: "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
 

Note:

A word is defined as a sequence of non-space characters.
Input string may contain leading or trailing spaces. However, your reversed string should not contain leading or trailing spaces.
You need to reduce multiple spaces between two words to a single space in the reversed string.
 

Follow up:

For C programmers, try to solve it in-place in O(1) extra space.

*/

class Solution {
public:
    string reverseWords(string s) {
        if (s.empty()) return s;
        reverse(s.begin(),s.end());
        int i =0;
        int j =0;
        while(i<s.size()) {
            if (s[i] != ' ') {
                j = i;
                while(j < s.size() && s[j]!=' ') {
                    ++j;
                }
                for(int k=0;k<(j-i)/2;++k) {
                    char temp = s[i+k];
                    s[i+k]=s[j-1-k];
                    s[j-1-k] = temp;
                }
                ++j;
                while(j<s.size() && s[j]==' ') {
                    s.erase(j,1);
                }
                if (j == s.size()) {
                    s.erase(j-1,1);
                }
                i = j;
            } else {
                s.erase(i,1);
            }
        }
        return s;
    }
};