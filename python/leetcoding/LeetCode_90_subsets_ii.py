#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 2020/3/2 22:03
# @Author  : Zheng guoliang
# @Version : 1.0
# @File    : LeetCode_90_subsets_ii.py
# @Software: PyCharm
"""
1.需求功能：
 https://leetcode-cn.com/problems/subsets-ii/
给定一个可能包含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
2.实现过程：


"""


class Solution:
    def subsetsWithDup(self, nums):
        if nums is None or len(nums) < 1:
            return [[]]
        nums.sort()
        result = []
        for i in range(1 << len(nums)):
            item = []
            for j in range(1 << len(nums)):
                if i & (1 << j):
                    item.append(nums[j])
            if item not in result:
                result.append(item)
        return result

    def subsetWithDup1(self, nums):
        if nums is None or len(nums) < 1:
            return []
        nums.sort()
        result = []
        self.helper(nums,0,result,[])
        return result

    def helper(self,nums,index,result,item):
        result.append(item)
        for i in range(index,len(nums)):
            if i-1>=index and nums[i-1]==nums[i]:
                continue
            self.helper(nums,i+1,result,item+[nums[i]])


if __name__ == '__main__':
    solution = Solution()
    nums = [1,2,2]
    result = solution.subsetWithDup1(nums)
    print(result)
