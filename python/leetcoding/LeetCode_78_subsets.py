#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 2020/3/2 21:53
# @Author  : Zheng guoliang
# @Version : 1.0
# @File    : LeetCode_78_subsets.py
# @Software: PyCharm
"""
1.需求功能：
 https://leetcode-cn.com/problems/subsets/
给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）
2.实现过程：


"""


class Solution:
    def subsets(self, nums):
        if nums is None or len(nums) < 1:
            return [[]]
        nums_length = 1 << len(nums)
        result = []
        for i in range(nums_length):
            item = []
            for j in range(len(nums)):
                if i & (1 << j):
                    item.append(nums[j])
            result.append(item)
        return result
