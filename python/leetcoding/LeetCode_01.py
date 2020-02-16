#!/usr/bin/env python
# -*- coding:utf-8 -*-
# author:  zgl_csu
# name:    LeetCode_No01 
# datetime:2020/1/1 21:43
# software:PyCharm
"""
1.需求功能：
 https://leetcode-cn.com/problems/two-sum/submissions/

2.实现过程：


"""


class Solution:
    def twoSum(self, nums, target):
        if len(nums) < 2:
            return []
        map = {}
        for index in range(len(nums)):
            if target - nums[index] in map:
                return [map[target - nums[index]], index]
            else:
                map[nums[index]] = index
        return []


if __name__ == '__main__':
    solution = Solution()
    result = solution.twoSum([2, 5, 7, 11, 15], 9)
    print(result)
