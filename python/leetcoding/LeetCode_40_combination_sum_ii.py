#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 2020/3/4 20:57
# @Author  : Zheng guoliang
# @Version : 1.0
# @File    : LeetCode_40_combination_sum_ii.py
# @Software: PyCharm
"""
1.需求功能：
 https://leetcode-cn.com/problems/combination-sum-ii/
给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

candidates 中的每个数字在每个组合中只能使用一次。

2.实现过程：


"""


class Solution:
    def combinationSum2(self, candidates, target):
        if len(candidates) < 1 or sum(candidates) < target:
            return []
        candidates.sort()
        result = []
        self.helper(candidates, target, 0, [],result)
        return result

    def helper(self, candidates, target, index, item, result):
        if target == 0:
            result.append(item)
            return
        for i in range(index, len(candidates)):
            temp = target - candidates[i]
            if temp< 0:
                break
            if i - 1 >= index and candidates[i - 1] == candidates[i]:
                continue
            self.helper(candidates, temp, i + 1, item + [candidates[i]],  result)


if __name__ == '__main__':
    ss = Solution()
    candidates = [10, 1, 2, 7, 6, 1, 5]
    target = 8
    result = ss.combinationSum2(candidates, target)
    print(result)
