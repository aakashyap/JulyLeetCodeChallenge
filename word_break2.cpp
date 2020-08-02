/*

Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences.

Note:

The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.
Example 1:

Input:
s = "catsanddog"
wordDict = ["cat", "cats", "and", "sand", "dog"]
Output:
[
  "cats and dog",
  "cat sand dog"
]
Example 2:

Input:
s = "pineapplepenapple"
wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
Output:
[
  "pine apple pen apple",
  "pineapple pen apple",
  "pine applepen apple"
]
Explanation: Note that you are allowed to reuse a dictionary word.
Example 3:

Input:
s = "catsandog"
wordDict = ["cats", "dog", "sand", "and", "cat"]
Output:
[]

*/

class Solution {
    unordered_map<string,vector<string>> dp;
    int size;
    vector<string> util(string s,const vector<string>& wordDict) {
        if (s.size() == 0) {
            return {""};
        }
        if (dp.find(s) != dp.end()) {
            return dp[s];
        }
        vector<string> partial,result;
        for(auto &word:wordDict) {
            string subStr = s.substr(0,word.size());
            if (subStr != word) {
                continue;
            } else {
                //cout<<"whatabouthere"<<endl;
                partial = util(s.substr(word.size()),wordDict);
            }
            
            for(auto &part:partial) {
                //cout<<"jere"<<endl;
                //cout<<part<<endl;
                if (part.size() == 0) {
                    result.push_back(word);
                } else {
                    result.push_back(word+" "+part);
                }
            }
        }
        return dp[s] = result;
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        size = wordDict.size();
        return util(s,wordDict);
    }
};