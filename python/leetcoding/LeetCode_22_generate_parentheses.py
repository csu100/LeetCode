#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 2020/3/4 21:45
# @Author  : Zheng guoliang
# @Version : 1.0
# @File    : LeetCode_22_generate_parentheses.py
# @Software: PyCharm
"""
1.需求功能：
 https://leetcode-cn.com/problems/generate-parentheses/
 给出 n 代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且有效的括号组合。

2.实现过程：


"""


class Solution:
    def generateParenthesis(self, n):
        if n < 1:
            return []
        result = []
        self.get_all_generate_Parenthesis(n, n, result, "")
        return result

    def get_all_generate_Parenthesis(self, left, right, result, item):
        if (left == right and left == 0):
            result.append(item)
            return
        if left > 0:
            self.get_all_generate_Parenthesis(left - 1, right, result, item + "(")
        if left < right:
            self.get_all_generate_Parenthesis(left, right - 1, result, item + ")")
