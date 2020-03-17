#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 2020/2/25 21:58
# @Author  : Zheng guoliang
# @Version : 1.0
# @File    : LeetCode_455_Asign_Cookies.py
# @Software: PyCharm
"""
1.需求功能：
 https://leetcode-cn.com/problems/assign-cookies/
 455. 分发饼干
假设你是一位很棒的家长，想要给你的孩子们一些小饼干。但是，每个孩子最多只能给一块饼干。对每个孩子 i ，都有一个胃口值 gi ，这是能让孩子们满足胃口的饼干的最小尺寸；并且每块饼干 j ，都有一个尺寸 sj 。如果 sj >= gi ，我们可以将这个饼干 j 分配给孩子 i ，这个孩子会得到满足。你的目标是尽可能满足越多数量的孩子，并输出这个最大数值。

2.实现过程：


"""

class Solution:
    def findContentChildren(self, g, s):
        if len(g) < 1 or len(s) < 1:
            return 0
        children = 0
        cookie = 0
        g = sorted(g)
        s = sorted(s)
        while children < len(g) and cookie < len(s):
            if g[children] <= s[cookie]:
                children += 1
            cookie += 1
        return children

if __name__ == '__main__':
    g = [1,2,3]
    s=[1,1]
    solution = Solution()
    result = solution.findContentChildren(g,s)
    print(result)