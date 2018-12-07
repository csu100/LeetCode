28. Implement strStr()
Easy
680
1051


Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:

Input: haystack = "hello", needle = "ll"
Output: 2
Example 2:

Input: haystack = "aaaaa", needle = "bba"
Output: -1


class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack.size()<1 && needle.size()<1) return 0;
        if(haystack.size()>0 && needle.size()<1)  return 0;
        if(haystack.size()<1 || needle.size()<1 || haystack.size()<needle.size()) return -1;
        int R=needle.size();
        int pos=0;
        for(int i=0;i<haystack.size();)
        {
            if(haystack[i]!=needle[pos])
            {
                int k=needle.size()-1;
                while(k>0 && R<haystack.size() && haystack[R]!=needle[k])
                {
                    k--;
                }
                i=R-k;
                pos=0;
                R=i+needle.size();
            }else
            {
                if(pos==needle.size()-1)
                {
                    return i-pos;
                }
                pos++;
                i++;
            }
        }
        return -1;
        
    }
};



class Solution {
    public int strStr(String haystack, String needle) {
        if(haystack.length()<1 && needle.length()<1) return 0;
        if(haystack.length()>0 && needle.length()<1) return 0;
        if(haystack.length()<1 || needle.length()<1 || haystack.length()<needle.length()) return -1;
        char[] hay=haystack.toCharArray();
        char[] match=needle.toCharArray();
        int R=match.length;
        int pos=0;
        for(int i=0;i<hay.length;)
        {
            if(hay[i]!=match[pos])
            {
                int k=match.length-1;
                while(k>0 &&  R<hay.length && match[k]!=hay[R])
                {
                    k--;
                }
                i=R-k;
                pos=0;
                R=i+match.length;
            }else
            {
                if(pos==match.length-1)
                {
                    return i-pos;
                }
                i++;
                pos++;
            }
        }
        return -1;
        
        
        
    }
}




