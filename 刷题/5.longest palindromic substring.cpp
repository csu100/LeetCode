5.longest palindromic substring

Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example 1:

Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: "cbbd"
Output: "bb"

////////////////////////////////////////////////////


class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size()<2) return s;
        string new_s=manacher(s);
        int len=new_s.size();
        vector<int> pA(len,0);
        int pR=-1;
        int index=-1;
        int pos=-1;
        int maxLen=-1;
        for(int i=0;i<len;i++)
        {
            pA[i]=pR>i?min(pA[2*index-i],pR-i):1;
            while(i-pA[i]>-1 && i+pA[i]<len)
            {
                if(new_s[i-pA[i]]!=new_s[i+pA[i]])
                {
                    break;
                }
                pA[i]++;
            }
            if(pA[i]+i>pR)
            {
                pR=pA[i]+i;
                index=i;
            }
            if(pA[i]>maxLen)
            {
                maxLen=pA[i];
                pos=i;
            }
        }
        maxLen--;
        string result=s.substr((pos-maxLen)/2,maxLen);
        return result;
    }

private:
    string manacher(string& s)
    {
        string res="";
        for(int i=0;i<s.size();i++)
        {
            res+='#';
            res+=s[i];
        }
        res+='#';
        return res;
    }
};


######################################################

class Solution:
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        if len(s)<2:
            return s
        new_s=list(self.manacher(s))
        pR=-1
        index=-1
        maxLen=-1
        pos=-1
        pA=[0 for i in range(len(new_s))]
        for i in range(len(new_s)):
            pA[i]=1
            if pR>i:
                pA[i]=min(pA[2*index-i],pR-i)
            while i+pA[i]<len(new_s) and i-pA[i]>-1:
                if new_s[i-pA[i]]!=new_s[i+pA[i]]:
                    break
                pA[i]+=1
            if pA[i]+i>pR:
                pR=i+pA[i]
                index=i
            if pA[i]>maxLen:
                maxLen=pA[i]
                pos=i
        maxLen-=1
        L=int((pos-maxLen)>>1)
        return s[L:L+maxLen]
        
        
        
    def manacher(self,s):
        new_s=[]
        for i in s:
            new_s+='#'
            new_s+=i
        new_s+='#'
        return ''.join(new_s)