3. longest Substring without Repeating characters

Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 
Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.


//////////////////////////////////////////////////////

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()<1) return 0;
        int result=0;
        int MAP[256]={0};
        int L=0;
        for(int i=0;i<s.size();i++)
        {
            MAP[s[i]]++;
            while(MAP[s[i]]>1)
            {
                MAP[s[L]]--;
                L+=1;
            }
            result=max(result,i-L+1);
        }
        return result;
    }
};     


#############################################

class Solution:
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        if len(s)<1:
            return 0
        MAP={}
        L=0
        result=0
        for i in range(len(s)):
            if s[i] not in MAP:
                MAP[s[i]]=1
            else:
                MAP[s[i]]+=1
            while MAP[s[i]]>1:
                MAP[s[L]]-=1
                L+=1
            if result<(i-L+1):
                result=i-L+1
        return result
