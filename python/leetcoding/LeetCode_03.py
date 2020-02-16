#!/usr/bin/env python
#-*- coding:utf-8 -*-
# author:  zgl_csu
# name:    LeetCode_No03 
# datetime:2020/1/3 0:34
# software:PyCharm
"""
1.需求功能：
 https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/submissions/

2.实现过程：


"""

class Solution:

    def  lengthOfLongestSubstring(self,s):
        if len(s)<2:
            return len(s)
        map={}
        L=0
        result=0
        for i in range(len(s)):
            if s[i] in map:
                map[s[i]]+=1
            else:
                map[s[i]]=1
            while map[s[i]]>1:
                map[s[L]]-=1
                L+=1
            result=max(result,i-L+1)
        return result

    def lengthOfLongestSubstring1(self, s):
        if len(s) < 2:
            return len(s)
        L = 0
        result = 0
        temp=0
        for i in range(1,len(s)):
            for j in range(temp,i):
                if s[i]==s[j]:
                    result=max(result,i-temp)
                    temp=j+1
                    break
        print(result)
        result=max(result,len(s)-temp)
        return result


if __name__ == '__main__':
    s="cbb"
    solution =Solution()
    result =solution.lengthOfLongestSubstring1(s)
    print(result)